from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, RegisterEventHandler, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, TextSubstitution
from launch.event_handlers import OnProcessExit
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():

    # Delete any existing markers
    # Spawn test object in RViz
    # Run de-powdering demo


    test_object_param_name = "test_object"
    test_object_x_pos_param_name = "test_object_x_pos"
    test_object_y_pos_param_name = "test_object_y_pos"
    test_object_z_pos_param_name = "test_object_z_pos"

    declared_arguments = []

    
    declared_arguments.append(
        DeclareLaunchArgument(
            test_object_param_name,
            description="File name of the object (without directory and with .obj extension) of the test object to be placed in scene which the robot has to pick up.",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            test_object_x_pos_param_name,
            default_value="0.25",
            description="X-coordinate of where to place the test object",
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            test_object_y_pos_param_name,
            default_value="0.25",
            description="Y-coordinate of where to place the test object",
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            test_object_z_pos_param_name,
            default_value="0",
            description="Z-coordinate of where to place the test object",
        )
    )

    test_object = LaunchConfiguration(test_object_param_name)
    test_object_x_pos = LaunchConfiguration(test_object_x_pos_param_name)
    test_object_y_pos = LaunchConfiguration(test_object_y_pos_param_name)
    test_object_z_pos = LaunchConfiguration(test_object_z_pos_param_name)
    
    test_object_obj_path = PathJoinSubstitution([
        FindPackageShare('robotic_depowdering'),
        'test_parts',
        test_object,
    ])

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
    # object_marker_msg = TextSubstitution([
        
    # ])
    
    publish_object_cmd = ExecuteProcess(
        cmd=[[
            "ros2 topic pub ",
            "--once ",
            "/visualization_markers ",
            "visualization_msgs/msg/Marker ",
            "\"{header: {frame_id: \"base_link\"}, type: 10, action: 0, pose: {position: {x: ",
            test_object_x_pos,
            ", y: ",
            test_object_y_pos,
            ", z: ",
            test_object_z_pos,
            "}}, scale: {x: 1, y: 1, z: 1}, color: {r: 0.0, g: 1.0, b: 0.0, a: 1.0}, mesh_resource: \"",
            "package://robotic_depowdering/test_parts/",
            test_object,
            ".bin.stl",
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
    move_to_pose_service = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            FindPackageShare('rizon_pick_and_place'),
            '/launch/move_to_pose_service.launch.py'
        ])
    )
    pick_up_object = Node(
        package='robotic_depowdering',
        executable='pick_up_object',
        name='pick_up_object',
        arguments=[test_object_obj_path, test_object_x_pos, test_object_y_pos, test_object_z_pos]
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
        move_to_pose_service,
    ]
    return LaunchDescription(declared_arguments + nodes)