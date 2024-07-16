#include <memory>
#include <thread>
#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include "robotic_depowdering_interfaces/srv/move_to_pose.hpp"
#include "geometry_msgs/msg/pose.hpp"

class MoveToPoseService : public rclcpp::Node
{
public:
  MoveToPoseService() : Node("move_to_pose_service")
  {
    // Create the service
    service_ = this->create_service<robotic_depowdering_interfaces::srv::MoveToPose>(
        "move_to_pose", std::bind(&MoveToPoseService::handle_move_to_pose, this, std::placeholders::_1, std::placeholders::_2));

    // Create the MoveIt MoveGroup Interface
    move_group_interface_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(shared_from_this(), "rizon_arm");

    // Construct and initialize MoveItVisualTools
    moveit_visual_tools_ = std::make_shared<moveit_visual_tools::MoveItVisualTools>(
        shared_from_this(), "base_link", rviz_visual_tools::RVIZ_MARKER_TOPIC, move_group_interface_->getRobotModel());
    moveit_visual_tools_->deleteAllMarkers();
    moveit_visual_tools_->loadRemoteControl();

    // Create closures for visualization
    draw_title_ = [this](auto text) {
      auto const text_pose = [] {
        auto msg = Eigen::Isometry3d::Identity();
        msg.translation().z() = 1.0;
        return msg;
      }();
      moveit_visual_tools_->publishText(text_pose, text, rviz_visual_tools::WHITE,
                                        rviz_visual_tools::XLARGE);
    };

    prompt_ = [this](auto text) {
      moveit_visual_tools_->prompt(text);
    };

    draw_trajectory_tool_path_ = [this](auto const trajectory) {
      moveit_visual_tools_->publishTrajectoryLine(trajectory, move_group_interface_->getRobotModel()->getJointModelGroup("rizon_arm"));
    };
  }

private:
  void handle_move_to_pose(
      const std::shared_ptr<robotic_depowdering_interfaces::srv::MoveToPose::Request> request,
      std::shared_ptr<robotic_depowdering_interfaces::srv::MoveToPose::Response> response)
  {
    // Set the target pose
    move_group_interface_->setPoseTarget(request->target_pose);

    // Planning
    draw_title_("Planning");
    moveit_visual_tools_->trigger();

    auto const [success, plan] = [&move_group_interface = move_group_interface_] {
      moveit::planning_interface::MoveGroupInterface::Plan msg;
      auto const ok = static_cast<bool>(move_group_interface->plan(msg));
      return std::make_pair(ok, msg);
    }();

    
    if (success)
    {
      draw_trajectory_tool_path_(plan.trajectory_);
      moveit_visual_tools_->trigger();
      prompt_("Press 'Next' in the RvizVisualToolsGui window to execute");
      draw_title_("Executing");
      moveit_visual_tools_->trigger();

      move_group_interface_->execute(plan);
      response->success = true;
    }
    else
    {
      draw_title_("Planning Failed!");
      moveit_visual_tools_->trigger();
      response->success = false;
      RCLCPP_ERROR(this->get_logger(), "Planning and execution failed.");
    }
  }

  rclcpp::Service<robotic_depowdering_interfaces::srv::MoveToPose>::SharedPtr service_;
  std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_interface_;
  std::shared_ptr<moveit_visual_tools::MoveItVisualTools> moveit_visual_tools_;

  std::function<void(std::string)> draw_title_;
  std::function<void(std::string)> prompt_;
  std::function<void(const moveit_msgs::msg::RobotTrajectory&)> draw_trajectory_tool_path_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MoveToPoseService>();

  // We spin up a SingleThreadedExecutor so MoveItVisualTools interact with ROS
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node);
  auto spinner = std::thread([&executor]() { executor.spin(); });

  rclcpp::spin(node);
  rclcpp::shutdown();
  spinner.join();
  return 0;
}
