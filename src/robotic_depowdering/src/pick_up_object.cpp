#include "rclcpp/rclcpp.hpp"
#include "robotic_depowdering_interfaces/srv/gpd_grasp.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "gpd_interface.hpp"

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
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("pick_up_object_client");

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

    Eigen::Vector3d test_object_position = {obj_x_pos, obj_y_pos, obj_z_pos};

    std::string test_object_filename = argv[1];

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Test object %s is placed at (%f, %f, %f)", test_object_filename.c_str(), obj_x_pos, obj_y_pos, obj_z_pos);

    auto grasp_config = generateGraspPose(test_object_filename);

    if (!grasp_config) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "GPD failed to generate a grasp pose. Check output for details.");
        return -1;
    }

    
    // Offset grasp position to account for objects not placed at origin.
    grasp_config->setPosition(grasp_config->getPosition() + test_object_position);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tposition: <%f, %f, %f>", 
        grasp_config->getPosition().x(), grasp_config->getPosition().y(), grasp_config->getPosition().z());
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tapproach: <%f, %f, %f>", 
        grasp_config->getApproach().x(), grasp_config->getApproach().y(), grasp_config->getApproach().z());
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tbinormal: <%f, %f, %f>", 
        grasp_config->getBinormal().x(), grasp_config->getBinormal().y(), grasp_config->getBinormal().z());
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\taxis: <%f, %f, %f>", 
        grasp_config->getAxis().x(), grasp_config->getAxis().y(), grasp_config->getAxis().z());
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\taperture: %f", 
        grasp_config->getGraspWidth());
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tscore: %f", 
        grasp_config->getScore());
    


    // Carry out IK 
    //   \/\/\/\/
    // This simply sets random positions.
    std::vector<double> positions1 = {-1.40, -0.70, 0.00, 1.57, 0.01, 0.69, 0.00};
    std::vector<double> positions2 = {-1.81, -0.70, 0.00, 1.57, 0.01, 0.69, 0.00};
    // srand((unsigned int)time(NULL));
    // for (auto& pos : positions) {
    //     pos = (float)rand() / RAND_MAX;
    // }
    

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
    armPoint.positions = positions1;
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
        positions1[0], 
        positions1[1], 
        positions1[2], 
        positions1[3], 
        positions1[4], 
        positions1[5], 
        positions1[6]
    );
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting for 5 seconds");
    std::this_thread::sleep_for(std::chrono::seconds(5));

    armPoint.positions = positions2;
    jointTrajectoryMessage.points = {armPoint};
    try {
        jointTrajectoryPublisher->publish(jointTrajectoryMessage);
        rclcpp::spin_some(node);
    } catch (const rclcpp::exceptions::RCLError& e) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to send message to Rizon 4s. Details: %s", e.what());
    }

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sent the arm to go to <%f, %f, %f, %f, %f, %f, %f>", 
        positions2[0], 
        positions2[1], 
        positions2[2], 
        positions2[3], 
        positions2[4], 
        positions2[5], 
        positions2[6]
    );
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting for 5 seconds");
    std::this_thread::sleep_for(std::chrono::seconds(5));

    
    armPoint.positions = positions1;
    jointTrajectoryMessage.points = {armPoint};

    try {
        jointTrajectoryPublisher->publish(jointTrajectoryMessage);
        rclcpp::spin_some(node);
    } catch (const rclcpp::exceptions::RCLError& e) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to send message to Rizon 4s. Details: %s", e.what());
    }

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sent the arm to go to <%f, %f, %f, %f, %f, %f, %f>", 
        positions1[0], 
        positions1[1], 
        positions1[2], 
        positions1[3], 
        positions1[4], 
        positions1[5], 
        positions1[6]
    );
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting for 5 seconds");
    std::this_thread::sleep_for(std::chrono::seconds(5));


    rclcpp::shutdown();
    return 0;
}