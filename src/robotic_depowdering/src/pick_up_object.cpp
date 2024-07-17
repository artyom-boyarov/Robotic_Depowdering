#include "rclcpp/rclcpp.hpp"
#include "robotic_depowdering_interfaces/srv/gpd_grasp.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "gpd_interface.hpp"
#include "robotic_depowdering_interfaces/srv/move_to_pose.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "Eigen/Geometry"

#include <chrono>
#include <cstdlib>
#include <memory>
#include <ctime>
#include <thread>

using namespace std::chrono_literals;

// Should this run only once, or multiple times?
// Turn this into an action.
int main(int argc, char** argv) {

    rclcpp::init(argc, argv);

    const auto logger = rclcpp::get_logger("rclcpp");
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("pick_up_object_client");


    // Assume all arguments are correctly formed.
    // Will have to change this.
    if (argc < 2) {
        RCLCPP_ERROR(logger, "Usage: ros2 run robotic_depowdering pick_up_object [filename.obj] [x-coord=0.0] [y-coord=0.0] [z-coord=0.0]");
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

    Eigen::Vector3d test_object_position = {obj_x_pos, obj_y_pos, obj_z_pos};

    std::string test_object_filename = argv[1];

    RCLCPP_INFO(logger, "Test object %s is placed at (%f, %f, %f)", test_object_filename.c_str(), obj_x_pos, obj_y_pos, obj_z_pos);

    auto grasp_config = generateGraspPose(test_object_filename);

    if (!grasp_config) {
        RCLCPP_ERROR(logger, "GPD failed to generate a grasp pose. Check output for details.");
        return -1;
    }

    
    // Offset grasp position to account for objects not placed at origin.
    grasp_config->setPosition(grasp_config->getPosition() + test_object_position);

    RCLCPP_INFO(logger, "\tposition: <%f, %f, %f>", 
        grasp_config->getPosition().x(), grasp_config->getPosition().y(), grasp_config->getPosition().z());
    RCLCPP_INFO(logger, "\tapproach: <%f, %f, %f>", 
        grasp_config->getApproach().x(), grasp_config->getApproach().y(), grasp_config->getApproach().z());
    RCLCPP_INFO(logger, "\tbinormal: <%f, %f, %f>", 
        grasp_config->getBinormal().x(), grasp_config->getBinormal().y(), grasp_config->getBinormal().z());
    RCLCPP_INFO(logger, "\taxis: <%f, %f, %f>", 
        grasp_config->getAxis().x(), grasp_config->getAxis().y(), grasp_config->getAxis().z());
    RCLCPP_INFO(logger, "\taperture: %f", 
        grasp_config->getGraspWidth());
    RCLCPP_INFO(logger, "\tscore: %f", 
        grasp_config->getScore());

    // Set the target pose for the robot to move to
    auto target_pose = geometry_msgs::msg::Pose();
    target_pose.position.x = grasp_config->getPosition().x();
    target_pose.position.y = grasp_config->getPosition().y();
    target_pose.position.z = grasp_config->getPosition().z();
    Eigen::Matrix3d rot_mat;
    rot_mat << grasp_config->getAxis().x(), grasp_config->getBinormal().x(), grasp_config->getApproach().x(),
           grasp_config->getAxis().y(), grasp_config->getBinormal().y(), grasp_config->getApproach().y(),
           grasp_config->getAxis().z(), grasp_config->getBinormal().z(), grasp_config->getApproach().z();
    Eigen::Quaternion<double> rot_q(rot_mat);
    rot_q.normalize();
    target_pose.orientation.w = rot_q.w();
    target_pose.orientation.x = rot_q.x();
    target_pose.orientation.y = rot_q.y();
    target_pose.orientation.z = rot_q.z();

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Got quaternion w:%f x:%f y:%f z:%f", rot_q.x(), rot_q.y(), rot_q.z(), rot_q.w());
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%f %f %f %f %f %f %f",
        grasp_config->getPosition().x(), grasp_config->getPosition().y(), grasp_config->getPosition().z(),
        rot_q.x(), rot_q.y(), rot_q.z(), rot_q.w());

    // Create a service client to call the move_to_pose service
    auto client = node->create_client<robotic_depowdering_interfaces::srv::MoveToPose>("move_to_pose");
    while (!client->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting for the service to be available...");
    }

    auto request = std::make_shared<robotic_depowdering_interfaces::srv::MoveToPose::Request>();
    request->target_pose = target_pose;

    auto result = client->async_send_request(request);
    if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS) {
        if (result.get()->success) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Successfully moved to target pose.");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to move to target pose.");
        }
    } else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service move_to_pose");
    }

    /*
    // Carry out IK 
    //   \/\/\/\/
    // This simply sets random positions.
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

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sent the arm to go to <%f, %f, %f, %f, %f, %f, %f>", 
        positions[0], 
        positions[1], 
        positions[2], 
        positions[3], 
        positions[4], 
        positions[5], 
        positions[6]
    );
    */

    rclcpp::shutdown();
    return 0;
}