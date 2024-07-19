from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, RegisterEventHandler, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.event_handlers import OnProcessStart
from launch.substitutions import (
    Command,
    FindExecutable,
    LaunchConfiguration,
    PathJoinSubstitution,
)
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # Declare arguments
    declared_arguments = []
    
    flexiv_rviz_bringup_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([FindPackageShare("flexiv_bringup"), "launch", "rizon_with_object_pickup.launch.py"])
        ),
        launch_arguments={
            "robot_ip": "dont-care",
            "local_ip": "dont-care",
            "use_fake_hardware": "true"
        }.items()
    )

    # moveit_collision_detection_demo_node = Node(
    #     package="robotic_depowdering",
    #     executable="moveit_collision_detection_demo",
    #     parameters=[robot_description, robot_description_semantic, robot_description_kinematics],
    # )

    loop_parts_collision_demo_node = Node(
        package="robotic_depowdering",
        executable="loop_parts_collision_demo"
    )

    # delay_loop_parts_collision_demo_node = RegisterEventHandler(
    #     event_handler=OnProcessStart(
    #         target_action=flexiv_rviz_bringup_node,
    #         on_start=[loop_parts_collision_demo_node]
    #     )
    # )

    nodes = [
        # moveit_collision_detection_demo_node
        flexiv_rviz_bringup_node,
        loop_parts_collision_demo_node
    ]

    return LaunchDescription(declared_arguments + nodes)
