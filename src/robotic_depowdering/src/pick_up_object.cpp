#include "rclcpp/rclcpp.hpp"
#include "rclcpp/wait_for_message.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "robotic_depowdering_interfaces/srv/vcpd_grasp.hpp"
#include "robotic_depowdering_interfaces/srv/move_to_pose.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "Eigen/Geometry"
#include "tf2_eigen/tf2_eigen.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "moveit/move_group_interface/move_group_interface.h"
#include "moveit_visual_tools/moveit_visual_tools.h"
#include "moveit/planning_scene_interface/planning_scene_interface.h"
#include "shape_msgs/msg/mesh.hpp"
#include "OBJ_Loader.h"
#include "ament_index_cpp/get_package_share_directory.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>
#include <ctime>
#include <thread>
#include <string>
#include <optional>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std::chrono_literals;
using std::placeholders::_1;
using GraspConfiguration = robotic_depowdering_interfaces::srv::VCPDGrasp::Response;
using GraspRequest = robotic_depowdering_interfaces::srv::VCPDGrasp::Request;

// TODO: Maybe try using visual tools?
class PickUpObjectNode : public rclcpp::Node
{
    std::string object;
    Eigen::Vector3d object_position;
    rclcpp::Client<robotic_depowdering_interfaces::srv::VCPDGrasp>::SharedPtr vcpd_client;

    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_interface_;
    std::shared_ptr<moveit::planning_interface::PlanningSceneInterface> planning_scene_interface_;
    std::shared_ptr<moveit_visual_tools::MoveItVisualTools> moveit_visual_tools_;

    objl::Loader objLoader;
    shape_msgs::msg::Mesh target_obj_mesh;

    moveit_msgs::msg::CollisionObject target_obj_collision;
    moveit_msgs::msg::CollisionObject floor_collision;

    bool controlGripperForce(float grasp_force = 10.0)
    {
        // Call Flexiv ROS2 gripper action server.
        return true;
    }

    bool controlGripperWidth(float grasp_width = 10.0)
    {
        return true;
    }

public:
    PickUpObjectNode() : Node("pick_up_object_node")
    {
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

        loadTargetObjectMesh();

        vcpd_client =
            this->create_client<robotic_depowdering_interfaces::srv::VCPDGrasp>(
                "vcpd_get_grasp");

        RCLCPP_INFO(this->get_logger(), "Initialized VCPD client");

        RCLCPP_INFO(this->get_logger(), "Initialized pick_up_object_node to pick up %s located at <%f, %f, %f>",
                    object.c_str(), object_x, object_y, object_z);
    }

    void initiailizeMoveIt()
    {
        move_group_interface_ =
            std::make_shared<moveit::planning_interface::MoveGroupInterface>(
                shared_from_this(), "rizon_arm");

        move_group_interface_->setNumPlanningAttempts(10);
        move_group_interface_->setPlanningTime(5.0);

        RCLCPP_INFO(this->get_logger(), "Initialized move_group_interface");
        planning_scene_interface_ =
            std::make_shared<moveit::planning_interface::PlanningSceneInterface>();

        // Construct and initialize MoveItVisualTools
        moveit_visual_tools_ = std::make_shared<moveit_visual_tools::MoveItVisualTools>(
            shared_from_this(),
            "base_link",
            rviz_visual_tools::RVIZ_MARKER_TOPIC,
            move_group_interface_->getRobotModel());

        moveit_visual_tools_->deleteAllMarkers();
        moveit_visual_tools_->loadRemoteControl();
        RCLCPP_INFO(this->get_logger(), "Initialized moveit_visual_tools");
    }

    void loadTargetObjectMesh()
    {
        std::string robotic_depowdering_share_dir = ament_index_cpp::get_package_share_directory("robotic_depowdering");
        if (!objLoader.LoadFile(robotic_depowdering_share_dir + "/test_parts/" + object + ".obj"))
        {
            RCLCPP_ERROR(this->get_logger(), "Unable to load OBJ of the object to be picked up");
        }
        RCLCPP_INFO(this->get_logger(), "Loaded OBJ mesh of object to pick up: %s. Mesh has %ld meshes", object.c_str(), objLoader.LoadedMeshes.size());
        // # List of triangles; the index values refer to positions in vertices[].
        // MeshTriangle[] triangles
        // # The actual vertices that make up the mesh.
        // geometry_msgs/Point[] vertices

        uint32_t index_offset = 0;
        for (size_t mesh_num = 0; mesh_num < objLoader.LoadedMeshes.size(); mesh_num++)
        {
            auto loadedObjMesh = objLoader.LoadedMeshes[mesh_num];

            target_obj_mesh.vertices.reserve(
                target_obj_mesh.vertices.size() +
                loadedObjMesh.Vertices.size());
            for (const auto &loadedVertex : loadedObjMesh.Vertices)
            {
                geometry_msgs::msg::Point meshVertex;
                meshVertex.x = loadedVertex.Position.X;
                meshVertex.y = loadedVertex.Position.Y;
                meshVertex.z = loadedVertex.Position.Z;
                target_obj_mesh.vertices.push_back(meshVertex);
            }

            target_obj_mesh.triangles.reserve(
                target_obj_mesh.triangles.size() +
                loadedObjMesh.Indices.size() / 3);
            for (size_t i = 0; i < loadedObjMesh.Indices.size(); i += 3)
            {
                shape_msgs::msg::MeshTriangle meshTri;
                meshTri.vertex_indices[0] = index_offset + loadedObjMesh.Indices[i];
                meshTri.vertex_indices[1] = index_offset + loadedObjMesh.Indices[i + 1];
                meshTri.vertex_indices[2] = index_offset + loadedObjMesh.Indices[i + 2];
                target_obj_mesh.triangles.push_back(meshTri);
            }
            index_offset += loadedObjMesh.Vertices.size();
        }
    }

    void addTargetObjectCollisionObject()
    {

        target_obj_collision.header.frame_id = "world";
        target_obj_collision.id = "target_obj";

        geometry_msgs::msg::Pose target_obj_pose;
        target_obj_pose.orientation.w = 1.0;
        target_obj_pose.position = tf2::toMsg(object_position);

        target_obj_collision.meshes.push_back(target_obj_mesh);
        target_obj_collision.mesh_poses.push_back(target_obj_pose);
        target_obj_collision.operation = target_obj_collision.ADD;

        RCLCPP_INFO(this->get_logger(), "Added the target object to avoid collisions");
        planning_scene_interface_->applyCollisionObject(target_obj_collision);
    }

    void removeTargetObjectCollisionObject()
    {
        target_obj_collision.operation = target_obj_collision.REMOVE;
        RCLCPP_INFO(this->get_logger(), "Removed the target object");
        planning_scene_interface_->applyCollisionObject(target_obj_collision);
    }

    void addFloorCollisionObject()
    {
        shape_msgs::msg::SolidPrimitive floor_box;
        floor_box.type = floor_box.BOX;
        floor_box.dimensions.resize(3);
        floor_box.dimensions[floor_box.BOX_X] = 0.1;
        floor_box.dimensions[floor_box.BOX_Y] = 2;
        floor_box.dimensions[floor_box.BOX_Z] = 2;

        geometry_msgs::msg::Pose floor_pose;
        floor_pose.orientation.w = 1.0;
        floor_pose.position.x = 0.0;
        floor_pose.position.y = 0.0;
        floor_pose.position.z = -0.05;

        floor_collision.primitives.push_back(floor_box);
        floor_collision.primitive_poses.push_back(floor_pose);
        floor_collision.operation = floor_collision.ADD;

        RCLCPP_INFO(this->get_logger(), "Added the floor object to avoid collisions");
        planning_scene_interface_->applyCollisionObject(floor_collision);
    }

    void doPickUp()
    {
        // Initialize MoveIt.
        initiailizeMoveIt();
        // Add collision objects.
        addTargetObjectCollisionObject();
        addFloorCollisionObject();

        std::optional<std::shared_ptr<GraspConfiguration>> grasp = getGrasp();

        if (!grasp.has_value())
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to find a grasp. Exiting");
            return;
        }

        auto graspConfiguration = grasp.value();
        // Offset grasp for object position
        graspConfiguration->position.x += object_position.x();
        graspConfiguration->position.y += object_position.y();
        graspConfiguration->position.z += object_position.z();

        // Convert to Pose msg
        geometry_msgs::msg::Pose grasp_pose = getGraspPose(graspConfiguration);

        auto grasp_bite_pose = grasp_pose;
        auto &bite_pose_position = grasp_bite_pose.position;

        // Offset bite position
        bite_pose_position.x -= 0.1 * graspConfiguration->approach.x;
        bite_pose_position.y -= 0.1 * graspConfiguration->approach.y;
        bite_pose_position.z -= 0.1 * graspConfiguration->approach.z;

        auto grasp_raised_pose = grasp_pose;
        auto &raised_pose_position = grasp_raised_pose.position;

        // Offset raised pose
        raised_pose_position.z += 0.2; // Raise by 20 cm

        RCLCPP_INFO(this->get_logger(), "About to begin planning. Set the planner in MotionPlanning->Context->Default to BFMTkConfigDefault and check the target_obj in scene objects.");
        RCLCPP_INFO(this->get_logger(), "Once complete, click Continue to move to grasp bite pose.");
        waitForContinue();

        RCLCPP_INFO(this->get_logger(), "Moving to grasp bite pose.");
        if (!moveToPose(grasp_bite_pose))
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to move to grasp bite pose.");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Moved to bite pose. Press 'Continue' to move to grasp pose.");
        waitForContinue();

        RCLCPP_INFO(this->get_logger(), "Moving to grasp pose.");
        if (!moveBetweenPoses(grasp_bite_pose, grasp_pose))
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to move to grasp pose.");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Moved to grasp pose. Press 'Continue' to close gripper.");

        waitForContinue();

        RCLCPP_INFO(this->get_logger(), "Closing gripper");
        if (!controlGripperForce(10.0))
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to close gripper.");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Closed gripper. Press 'Continue' to raise object.");
        waitForContinue();

        RCLCPP_INFO(this->get_logger(), "Moving to raised pose.");
        if (!moveBetweenPoses(grasp_pose, grasp_raised_pose))
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to move to raised pose.");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Moved to raised pose. Press 'Continue' to open gripper and release the object.");
        waitForContinue();

        RCLCPP_INFO(this->get_logger(), "Opening gripper");
        if (!controlGripperWidth(graspConfiguration->width * 1.1))
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to open gripper.");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Opened gripper. Exiting.");
    }

    bool moveBetweenPoses(geometry_msgs::msg::Pose &p1, geometry_msgs::msg::Pose &p2)
    {
        moveit_msgs::msg::RobotTrajectory computed_trajectory;
        double path_percent = move_group_interface_->computeCartesianPath({p1, p2}, 0.01, 10.0, computed_trajectory, false);
        if (path_percent < 0.0) {
            RCLCPP_ERROR(this->get_logger(), "Failed to compute cartesian path");
            return false;
        }

        RCLCPP_INFO(this->get_logger(), "Computed Cartesian path (%.2f%% achieved)", path_percent * 100.0);
        auto const ok = static_cast<bool>(move_group_interface_->execute(computed_trajectory));
        if (!ok)
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to execute trajectory");
            return false;
        }
        RCLCPP_INFO(this->get_logger(), "Computed Cartesian path successfully executed");
        return true;
    }

    void waitForContinue()
    {
        sensor_msgs::msg::Joy rviz_msg;
        while (!rclcpp::wait_for_message(rviz_msg, this->shared_from_this(), "/rviz_visual_tools_gui", std::chrono::seconds(5)))
        {
            RCLCPP_INFO(this->get_logger(), "Waiting for continue to be clicked");
        }
    }

    geometry_msgs::msg::Pose getGraspPose(std::shared_ptr<GraspConfiguration> graspConfiguration)
    {
        geometry_msgs::msg::Pose target_pose;
        target_pose.position = graspConfiguration->position;

        Eigen::Matrix3d rot_mat;
        rot_mat << graspConfiguration->axis.x, graspConfiguration->binormal.x, graspConfiguration->approach.x,
            graspConfiguration->axis.y, graspConfiguration->binormal.y, graspConfiguration->approach.y,
            graspConfiguration->axis.z, graspConfiguration->binormal.z, graspConfiguration->approach.z;

        Eigen::Quaternion<double> rot_q(rot_mat);
        rot_q.normalize();

        target_pose.orientation = tf2::toMsg(rot_q);
        return target_pose;
    }

    void doRaise(const geometry_msgs::msg::Pose &grasp_pose)
    {
        // if (msg->buttons[2] != 1) return;
        RCLCPP_INFO(this->get_logger(), "Lifting part");

        auto raisedPose = grasp_pose;
        raisedPose.position.z += 0.2; // Raise by 20 cm

        if (!moveToPose(raisedPose))
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to raise part");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Test finished. When ready, switch the robot to manual mode to release the part");
    }

    std::optional<std::shared_ptr<GraspConfiguration>> getGrasp()
    {
        // Construct and call grasp service

        auto graspRequest = std::make_shared<GraspRequest>();
        graspRequest->name = object;
        graspRequest->position = Eigen::toMsg(object_position);

        while (!vcpd_client->wait_for_service(1s))
        {
            if (!rclcpp::ok())
            {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for service, exiting");
                return {};
            }
            RCLCPP_INFO(this->get_logger(), "Waiting for VCPD service");
        }

        auto result = vcpd_client->async_send_request(graspRequest);

        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == rclcpp::FutureReturnCode::SUCCESS)
        {
            auto graspConfiguration = result.get();
            RCLCPP_INFO(this->get_logger(), "Received grasp configuration for %s with base position at <%f, %f, %f> and width %f",
                        object.c_str(), graspConfiguration->position.x, graspConfiguration->position.y, graspConfiguration->position.z, graspConfiguration->width);
            return graspConfiguration;
        }

        return {};
    }

    bool moveToPose(const geometry_msgs::msg::Pose &target_pose)
    {
        RCLCPP_INFO(this->get_logger(), "Moving to pose");
        // Set the target pose
        move_group_interface_->setPoseTarget(target_pose);

        auto const [success, plan] = [&move_group_interface = move_group_interface_]
        {
            moveit::planning_interface::MoveGroupInterface::Plan move_plan;
            auto const ok = static_cast<bool>(move_group_interface->plan(move_plan));
            return std::make_pair(ok, move_plan);
        }();

        if (success)
        {
            RCLCPP_INFO(this->get_logger(), "Planning succeeded, executing trajectory");

            auto const ok = static_cast<bool>(move_group_interface_->execute(plan));
            if (!ok)
            {
                RCLCPP_ERROR(this->get_logger(), "Failed to execute trajectory");
                return false;
            }
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Planning and execution failed.");
            return false;
        }
        return true;
    }
};

std::shared_ptr<rclcpp::Node> node;

// Should this run only once, or multiple times?
// Turn this into an action.
int main(int argc, char **argv)
{

    rclcpp::init(argc, argv);
    std::shared_ptr<PickUpObjectNode> node = std::make_shared<PickUpObjectNode>();
    node->doPickUp();
    rclcpp::shutdown();

    return 0;
}