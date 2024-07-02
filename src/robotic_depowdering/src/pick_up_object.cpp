#include "rclcpp/rclcpp.hpp"
#include "robotic_depowdering_interfaces/srv/gpd_grasp.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"


#include <chrono>
#include <cstdlib>
#include <memory>
#include <ctime>

using namespace std::chrono_literals;

// Should this run only once, or multiple times?
// Turn this into an action.
int main(int argc, char** argv) {

    rclcpp::init(argc, argv);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Got %d arguments", argc);

    // Assume all arguments are correctly formed.
    // Will have to change this.
    if (argc < 2) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Usage: ros2 run robotic_depowdering pick_up_object [filename.obj] [x-coord=0.0] [y-coord=0.0] [z-coord=0.0]");
        return -1;
    }

    float obj_x_pos = 0.0f, obj_y_pos = 0.0f, obj_z_pos = 0.0f;
    if (argc >= 3) {
        // x pos set
        obj_x_pos = atof(argv[2]);
    }
    if (argc >= 4) {
        // y pos set
        obj_y_pos = atof(argv[3]);
    }
    if (argc >= 5) {
        // y pos set
        obj_z_pos = atof(argv[4]);
    }

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("pick_up_object_client");
    rclcpp::Client<robotic_depowdering_interfaces::srv::GpdGrasp>::SharedPtr client = 
        node->create_client<robotic_depowdering_interfaces::srv::GpdGrasp>("gpd_service");
    
    auto request = std::make_shared<robotic_depowdering_interfaces::srv::GpdGrasp::Request>();
    request->file_name = argv[1];

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Test object %s is placed at (%f, %f, %f)", request->file_name.c_str(), obj_x_pos, obj_y_pos, obj_z_pos);

    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service gpd_service unavailable");
    }

    auto resultFuture = client->async_send_request(request);
    std::shared_ptr<robotic_depowdering_interfaces::srv::GpdGrasp::Response> result;
    // Wait for the result
    if (rclcpp::spin_until_future_complete(node, resultFuture) == 
        rclcpp::FutureReturnCode::SUCCESS) 
    {
        result = resultFuture.get();
        if (result.get()->found_grasp) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Got back grasp configuration.");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "GPD failed to return a grasp configuration");
            return -2;
        }
        
    } else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
        return -3;
    }

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tposition: <%f, %f, %f>", result.get()->position.x, result.get()->position.y, result.get()->position.z);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tapproach: <%f, %f, %f>", result.get()->approach.x, result.get()->approach.y, result.get()->approach.z);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tbinormal: <%f, %f, %f>", result.get()->binormal.x, result.get()->binormal.y, result.get()->binormal.z);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\taxis: <%f, %f, %f>", result.get()->axis.x, result.get()->axis.y, result.get()->axis.z);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\taperture: %f", result.get()->width);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tscore: %f", result.get()->score);

    // Carry out IK 
    //   \/\/\/\/
    std::vector<double> positions(7);
    srand((unsigned int)time(NULL));
    for (auto& pos : positions) {
        pos = (float)rand() / RAND_MAX;
    }
    

    // Now, after we've done IK, we publish the list of joint angles for the 7 joints to "/rizon_arm_controller/joint_trajectory".
    const std::string rizon_interface_topic = "/rizon_arm_controller/joint_trajectory";
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr jointTrajectoryPublisher = 
        node->create_publisher<trajectory_msgs::msg::JointTrajectory>(rizon_interface_topic, 10);
    
    trajectory_msgs::msg::JointTrajectory jointTrajectoryMessage;
    jointTrajectoryMessage.joint_names = std::vector<std::string>({
      "joint1",
      "joint2",
      "joint3",
      "joint4",
      "joint5",
      "joint6",
      "joint7"});
    
    trajectory_msgs::msg::JointTrajectoryPoint armPoint;
    armPoint.positions = positions;
    auto duration = builtin_interfaces::msg::Duration();
    duration.sec = 1;
    armPoint.time_from_start = duration;

    jointTrajectoryMessage.points = {armPoint};

    try {
        jointTrajectoryPublisher->publish(jointTrajectoryMessage);
        rclcpp::spin_some(node);
    } catch (const rclcpp::exceptions::RCLError& e) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to send message to Rizon 4s. Details: %s", e.what());
    }

    

    rclcpp::shutdown();
    return 0;
}