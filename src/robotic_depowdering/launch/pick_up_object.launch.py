from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, RegisterEventHandler, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, TextSubstitution
from launch.event_handlers import OnProcessExit
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():

    # Delete any existing markers
    # Spawn test object in RViz
    # Run pick-up demo

    object_param_name = "object"
    object_x_pos_param_name = "object_x_pos"
    object_y_pos_param_name = "object_y_pos"
    object_z_pos_param_name = "object_z_pos"
    sim_param_name = "sim"

    declared_arguments = []

    
    declared_arguments.append(
        DeclareLaunchArgument(
            object_param_name,
            # TODO: Change to not be .obj
            description="File name of the object (without directory and with .obj extension) of the test object to be placed in scene which the robot has to pick up.",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            object_x_pos_param_name,
            default_value="0.25",
            description="X-coordinate of where to place the test object",
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            object_y_pos_param_name,
            default_value="0.25",
            description="Y-coordinate of where to place the test object",
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            object_z_pos_param_name,
            default_value="0.0",
            description="Z-coordinate of where to place the test object"
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            sim_param_name,
            default_value="true",
            description="Whether you are running in simulation, or on the real robot",
        )
    )

    object = LaunchConfiguration(object_param_name)
    object_x_pos = LaunchConfiguration(object_x_pos_param_name)
    object_y_pos = LaunchConfiguration(object_y_pos_param_name)
    object_z_pos = LaunchConfiguration(object_z_pos_param_name)
    sim = LaunchConfiguration(sim_param_name)
    
    object_obj_path = PathJoinSubstitution([
        FindPackageShare('robotic_depowdering'),
        'test_parts',
        object,
    ])

    # When the flexiv ros2 is fixed we will add this
    # Clear RViz of objects
    publish_clear_rviz_cmd = ExecuteProcess(
        cmd=[[
            "ros2 topic pub ",
            "--once ",
            "/visualization_markers ",
            "visualization_msgs/msg/Marker ",
            "\"{header: {frame_id: \"base_link\"}, type: 0, action: 3}\"",
        ]],
        shell=True,
    )
    
    # Publish object to /visualization_markers topic
    #     ros2 topic pub -1 /visualization_markers visualization_msgs/msg/Marker 
    # "{header: {frame_id: \"base_link\"}, type: 10, action: 0, pose: {position: {x: 0.25, y: 0.25, z: 0}}, scale: {x: 0.001, y: 0.001, z: 0
    # .001}, color: {r: 0.0, g: 1.0, b: 0.0, a: 1.0}, mesh_resource: \"package://robotic_depowdering/test_parts/Buckle.bin.stl\"}"
    
    publish_object_cmd = ExecuteProcess(
        cmd=[[
            "ros2 topic pub ",
            "--once ",
            "/visualization_markers ",
            "visualization_msgs/msg/Marker ",
            "\"{header: {frame_id: \"base_link\"}, type: 10, action: 0, pose: {position: {x: ",
            object_x_pos,
            ", y: ",
            object_y_pos,
            ", z: ",
            object_z_pos,
            "}}, scale: {x: 1, y: 1, z: 1}, color: {r: 0.0, g: 1.0, b: 0.0, a: 1.0}, mesh_resource: \"",
            "package://robotic_depowdering/test_parts/",
            object,
            ".obj.bin.stl",
            "\"}\"",
        ]],
        shell=True,
    )
    # Delay publishing object to /visualization_marker after RViz set up
    delay_publish_object = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=publish_clear_rviz_cmd,
            on_exit=[publish_object_cmd]
        )
    )

    # Start the move_to_pose_service node
    # move_to_pose_service = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource([
    #         FindPackageShare('rizon_pick_and_place'),
    #         '/launch/rizon_pick_and_place.launch.py'
    #     ]),
    #     launch_arguments={
    #         "robot_ip"
    #     }
    # )
    
    pick_up_object = Node(
        package='robotic_depowdering',
        executable='pick_up_object',
        name='pick_up_object',
        parameters=[
            {'object' : object},
            {'object_x' : object_x_pos},
            {'object_y' : object_y_pos},
            {'object_z' : object_z_pos},
            {'sim': sim}
        ]
    )

    vcpd_service = Node(
        package='vcpd',
        executable='vcpd_service',
        name='vcpd_service',
        parameters=[
            os.path.join(
                'config',
                'dev.yaml'
            )
        ]
    )

    # Delay picking up the object after the marker is put into RViz
    delay_pick_up_object = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=publish_object_cmd,
            on_exit=[pick_up_object]
        )
    )


    nodes = [
        publish_clear_rviz_cmd,
        delay_publish_object,
        delay_pick_up_object,
        vcpd_service,
        # move_to_pose_service,
    ]
    return LaunchDescription(declared_arguments + nodes)