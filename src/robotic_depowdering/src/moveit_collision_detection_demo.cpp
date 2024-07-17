#include <moveit/collision_detection/collision_common.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_state/robot_state.h>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char** argv) {

    rclcpp::init(argc, argv);
    rclcpp::NodeOptions node_options;
    // This enables loading undeclared parameters
    // best practice would be to declare parameters in the corresponding classes
    // and provide descriptions about expected use
    node_options.automatically_declare_parameters_from_overrides(true);
    auto node = rclcpp::Node::make_shared("robot_model_and_state_tutorial", node_options);
    const auto& LOGGER = node->get_logger();


    node->declare_parameter("publish_robot_description", "world");
    bool publish_robot_description_param = node->get_parameter("publish_robot_description").as_bool();
    if (publish_robot_description_param) {
        std::cout << "publish_robot_description is set to true\n";
    } else {
        std::cout << "publish_robot_description is set to false\n";
    }

    robot_model_loader::RobotModelLoader robot_model_loader(node);
    const moveit::core::RobotModelPtr& kinematic_model = robot_model_loader.getModel();
    RCLCPP_INFO(LOGGER, "Model frame: %s", kinematic_model->getModelFrame().c_str());

    std::string root_joint_name = kinematic_model->getRootJointName();
    RCLCPP_INFO(LOGGER, "Root joint name: %s", root_joint_name.c_str());

    moveit::core::RobotStatePtr robot_state(new moveit::core::RobotState(kinematic_model));
    const moveit::core::JointModelGroup* joint_model_group = kinematic_model->getJointModelGroup(root_joint_name);

    const std::vector<std::string>& joint_names = joint_model_group->getVariableNames();

    // Get Joint Values
    // ^^^^^^^^^^^^^^^^
    // We can retrieve the current set of joint values stored in the state for the arm.
    std::vector<double> joint_values;
    robot_state->copyJointGroupPositions(joint_model_group, joint_values);
    for (std::size_t i = 0; i < joint_names.size(); ++i)
    {
        RCLCPP_INFO(LOGGER, "Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
    }

    rclcpp::shutdown();
    return 0;
}