#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <rizon_pick_and_place/srv/pick_and_place.hpp>
#include <rclcpp/rclcpp.hpp>
#include <moveit/planning_scene/planning_scene.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/task_constructor/task.h>
#include <moveit/task_constructor/solvers.h>
#include <moveit/task_constructor/stages.h>
#include <moveit/planning_scene/planning_scene.h>
#include <moveit/planning_pipeline/planning_pipeline.h>
#include <moveit/robot_model_loader/robot_model_loader.h>

class PickAndPlaceService : public rclcpp::Node
{
public:
    PickAndPlaceService()
        : Node("pick_and_place_service")
    {
        // Initialize MoveIt
        robot_model_loader_ = std::make_shared<robot_model_loader::RobotModelLoader>("robot_description");
        robot_model_ = robot_model_loader_->getModel();
        planning_scene_ = std::make_shared<planning_scene::PlanningScene>(robot_model_);
        planning_pipeline_ = std::make_shared<planning_pipeline::PlanningPipeline>(robot_model_, this->get_node_names(), "planning_plugin", "request_adapters");

        // Create the service
        service_ = this->create_service<rizon_pick_and_place::srv::PickAndPlace>(
            "pick_and_place", std::bind(&PickAndPlaceService::pickAndPlace, this, std::placeholders::_1, std::placeholders::_2));
    }

private:
    void pickAndPlace(const std::shared_ptr<rizon_pick_and_place::srv::PickAndPlace::Request> request,
                      std::shared_ptr<rizon_pick_and_place::srv::PickAndPlace::Response> response)
    {
        moveit::task_constructor::Task t;
        t.stages()->setName("pick_and_place");

        // Start with the current state
        auto current_state = std::make_shared<moveit::task_constructor::stages::CurrentState>("current state");
        t.add(current_state);

        // Move to a pre-grasp position
        auto pre_grasp = std::make_shared<moveit::task_constructor::stages::MoveTo>("move to pre-grasp", planning_pipeline_);
        pre_grasp->setGroup("arm");
        pre_grasp->setGoal("pre_grasp_pose");
        t.add(pre_grasp);

        // Compute IK for the pick pose
        auto ik_pick = std::make_shared<moveit::task_constructor::stages::ComputeIK>("compute IK for pick");
        ik_pick->setGroup("arm");
        ik_pick->setIKFrame("flange");
        ik_pick->properties().configureInitFrom(moveit::task_constructor::Stage::PARENT);
        ik_pick->properties().property("target_pose").set(request->pick_pose);
        t.add(ik_pick);

        // Pick the object
        auto pick = std::make_shared<moveit::task_constructor::stages::Pick>("pick object");
        pick->setGroup("arm");
        pick->setProperty("eef", "flange");
        pick->setProperty("object", "object_to_pick");
        t.add(pick);

        // Compute IK for the place pose
        auto ik_place = std::make_shared<moveit::task_constructor::stages::ComputeIK>("compute IK for place");
        ik_place->setGroup("arm");
        ik_place->setIKFrame("flange");
        ik_place->properties().configureInitFrom(moveit::task_constructor::Stage::PARENT);
        ik_place->properties().property("target_pose").set(request->place_pose);
        t.add(ik_place);

        // Place the object
        auto place = std::make_shared<moveit::task_constructor::stages::Place>("place object");
        place->setGroup("arm");
        place->setProperty("eef", "flange");
        t.add(place);

        // Plan and execute the task
        try
        {
            t.plan();
            if (t.solutions().size() > 0)
            {
                t.execute();
                response->success = true;
                response->message = "Pick and place task executed successfully.";
            }
            else
            {
                response->success = false;
                response->message = "Failed to find a valid solution for pick and place task.";
            }
        }
        catch (const std::exception &e)
        {
            response->success = false;
            response->message = std::string("Exception: ") + e.what();
        }
    }

    rclcpp::Service<rizon_pick_and_place::srv::PickAndPlace>::SharedPtr service_;
    robot_model_loader::RobotModelLoaderPtr robot_model_loader_;
    moveit::core::RobotModelPtr robot_model_;
    planning_scene::PlanningScenePtr planning_scene_;
    planning_pipeline::PlanningPipelinePtr planning_pipeline_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PickAndPlaceService>());
    rclcpp::shutdown();
    return 0;
}
