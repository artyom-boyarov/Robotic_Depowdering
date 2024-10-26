#include "rclcpp/rclcpp.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "robotic_depowdering_interfaces/srv/vcpd_grasp.hpp"
#include "robotic_depowdering_interfaces/srv/move_to_pose.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "Eigen/Geometry"
#include "tf2_eigen/tf2_eigen.hpp"
// #include <flexiv/rdk/robot.hpp>
// #include <flexiv/rdk/gripper.hpp>
// #include <flexiv/rdk/utility.hpp>

#include <chrono>
#include <cstdlib>
#include <memory>
#include <ctime>
#include <thread>
#include <string>
#include <optional>

using namespace std::chrono_literals;

using GraspConfiguration = robotic_depowdering_interfaces::srv::VCPDGrasp::Response;
using GraspRequest = robotic_depowdering_interfaces::srv::VCPDGrasp::Request;

class PickUpObjectNode : public rclcpp::Node {
    std::string object;
    Eigen::Vector3d object_position;
    rclcpp::Client<robotic_depowdering_interfaces::srv::VCPDGrasp>::SharedPtr vcpd_client;


    bool controlGripper(float grasp_width, float grasp_force = 5.0) {
    // std::string robotSN = "abcdef";
    // flexiv::rdk::Robot robot(robotSN);


    // // Clear fault on robot server if any
    // if (robot.fault()) {
    //     RCLCPP_ERROR(node->get_logger(), "Fault occurred on robot server, trying to clear ...");
    //     // Try to clear the fault
    //     if (!robot.ClearFault()) {
    //         RCLCPP_ERROR(node->get_logger(), "Unable to clear robot fault, exiting");
    //         return false;
    //     }
    //     std::this_thread::sleep_for(std::chrono::seconds(2));
    //     // Check again
    //     RCLCPP_INFO(node->get_logger(), "Fault on robot server is cleared");
    // }

    // // Enable the robot, make sure the E-stop is released before enabling
    // RCLCPP_INFO(node->get_logger(), "Enabling robot ...");
    // robot.Enable();

    // // Wait for the robot to become operational
    // while (!robot.operational()) {
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }
    // RCLCPP_INFO(node->get_logger(), "Robot is now operational");

    // if (robot.mode() == flexiv::rdk::Mode::IDLE) {
    //     RCLCPP_INFO(node->get_logger(), "Robot is in IDLE mode, switching to NRT_JOINT_POSITION");
    //     robot.SwitchMode(flexiv::rdk::Mode::NRT_JOINT_POSITION);
    // }

    // // Gripper Control
    // // =========================================================================================
    // // Gripper control is not available if the robot is in IDLE mode, so switch to some mode
    // // other than IDLE
    // // Instantiate gripper control interface
    // flexiv::rdk::Gripper gripper(robot);
    // RCLCPP_INFO(node->get_logger(), "Initializing gripper, takes ~10 seconds");
    // gripper.Init();
    
    // // TODO: avoid constantly re-initializing gripper? But since we only pick
    // // up one object this needs to only be done once
    // RCLCPP_INFO(node->get_logger(), "Gripper initialization complete");    
    // RCLCPP_INFO(node->get_logger(), "Closing grip for object");
    // gripper.Move(grasp_width, 0.02, grasp_force);

    // std::this_thread::sleep_for(std::chrono::seconds(5));
    
    // RCLCPP_INFO(node->get_logger(), "Opening grip for object");
    // gripper.Move(0.1, 0.02);
    // std::this_thread::sleep_for(std::chrono::seconds(5));
    // RCLCPP_INFO(node->get_logger(), "Stopping gripper");
    // gripper.Stop();

    return true;
}


public:


    PickUpObjectNode() : Node("pick_up_object_node") {
        this->declare_parameter("object", "Buckle");
        this->declare_parameter("object_x", 0.0);
        this->declare_parameter("object_y", 0.0);
        this->declare_parameter("object_z", 0.0);

        object = this->get_parameter("object").as_string();
        double object_x, object_y, object_z;
        object_x = this->get_parameter("object_x").as_double();
        object_y = this->get_parameter("object_y").as_double();
        object_z = this->get_parameter("object_z").as_double();
        object_position = {object_x, object_y, object_z};


        vcpd_client = this->create_client<robotic_depowdering_interfaces::srv::VCPDGrasp>("vcpd_get_grasp");

        RCLCPP_INFO(this->get_logger(), "Initialized pick_up_object_node to pick up %s located at <%f, %f, %f>",
            object.c_str(), object_x, object_y, object_z);

    }

    void doPickUp() {

        std::optional<std::shared_ptr<GraspConfiguration>> grasp = getGrasp();

        if (!grasp.has_value()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to find a grasp. Exiting");
            return;
        }

        auto graspConfiguration = grasp.value();

        // Move the arm here.
        // // Create a service client to call the move_to_pose service
        // auto client = node->create_client<robotic_depowdering_interfaces::srv::MoveToPose>("move_to_pose");
        // while (!client->wait_for_service(std::chrono::seconds(1))) {
        //     if (!rclcpp::ok()) {
        //         RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
        //         return 0;
        //     }
        //     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Waiting for the service to be available...");
        // }

        // auto request = std::make_shared<robotic_depowdering_interfaces::srv::MoveToPose::Request>();
        // request->target_pose = target_pose;

        // auto result = client->async_send_request(request);
        // if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS) {
        //     if (result.get()->success) {
        //         RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Successfully moved to target pose.");
        //     } else {
        //         RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to move to target pose.");
        //     }
        // } else {
        //     RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service move_to_pose");
    // }
    }

    std::optional<std::shared_ptr<GraspConfiguration>> getGrasp() {
        // Construct and call grasp service

        auto graspRequest = std::make_shared<GraspRequest>();
        graspRequest->name = object;
        graspRequest->position = Eigen::toMsg(object_position);

        while (!vcpd_client->wait_for_service(1s))
        {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for service, exiting");
                return {};
            }
            RCLCPP_INFO(this->get_logger(), "Waiting for VCPD service");
        }

        auto result = vcpd_client->async_send_request(graspRequest);

        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == rclcpp::FutureReturnCode::SUCCESS) {
            auto graspConfiguration = result.get();
            RCLCPP_INFO(this->get_logger(), "Received grasp configuration for %s with base position at <%f, %f, %f> and width %f",
                object.c_str(), graspConfiguration->position.x, graspConfiguration->position.y,graspConfiguration->position.z, graspConfiguration->width);
            return graspConfiguration;
        }
        
        return {};
    }
};

std::shared_ptr<rclcpp::Node> node;

// Should this run only once, or multiple times?
// Turn this into an action.
int main(int argc, char** argv) {

    rclcpp::init(argc, argv);
    std::shared_ptr<PickUpObjectNode> node = std::make_shared<PickUpObjectNode>();
    node->doPickUp();

    rclcpp::shutdown();


    return 0;
}