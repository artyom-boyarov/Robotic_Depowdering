from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, RegisterEventHandler, ExecuteProcess
from launch.conditions import IfCondition
from launch.event_handlers import OnProcessExit, OnProcessStart
from launch.substitutions import (
    Command,
    FindExecutable,
    LaunchConfiguration,
    PathJoinSubstitution,
    TextSubstitution
)
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    rizon_type_param_name = "rizon_type"
    robot_ip_param_name = "robot_ip"
    local_ip_param_name = "local_ip"
    start_rviz_param_name = "start_rviz"
    use_fake_hardware_param_name = "use_fake_hardware"
    fake_sensor_commands_param_name = "fake_sensor_commands"
    robot_controller_param_name = "robot_controller"
    test_object_param_name = "test_object"
    test_object_x_pos_param_name = "test_object_x_pos"
    test_object_y_pos_param_name = "test_object_y_pos"
    test_object_z_pos_param_name = "test_object_z_pos"
    start_pick_up_process_param_name = "start_pick_up_process"

    # Declare arguments
    declared_arguments = []

    declared_arguments.append(
        DeclareLaunchArgument(
            rizon_type_param_name,
            description="Type of the Flexiv Rizon robot.",
            default_value="rizon4",
            choices=["rizon4", "rizon4s", "rizon10"],
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            robot_ip_param_name,
            description="IP address of the robot server (remote).",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            local_ip_param_name,
            description="IP address of the workstation PC (local).",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            start_rviz_param_name,
            default_value="true",
            description="start RViz automatically with the launch file",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            use_fake_hardware_param_name,
            default_value="false",
            description="Start robot with fake hardware mirroring command to its states.",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            fake_sensor_commands_param_name,
            default_value="false",
            description="Enable fake command interfaces for sensors used for simple simulations. \
            Used only if 'use_fake_hardware' parameter is true.",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            robot_controller_param_name,
            default_value="rizon_arm_controller",
            description="Robot controller to start. Available: forward_position_controller, rizon_arm_controller, joint_impedance_controller.",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            test_object_param_name,
            default_value="Buckle",
            description="File name (without directory and extension) of the test object to be placed in scene which the robot has to pick up.",
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

    declared_arguments.append(
        DeclareLaunchArgument(
            start_pick_up_process_param_name,
            default_value="true",
            description="Start the robotic_depowdering pick_up process to visualize the robot arm reaching towards and picking up the object",
        )
    )

    # Initialize Arguments
    rizon_type = LaunchConfiguration(rizon_type_param_name)
    robot_ip = LaunchConfiguration(robot_ip_param_name)
    local_ip = LaunchConfiguration(local_ip_param_name)
    start_rviz = LaunchConfiguration(start_rviz_param_name)
    use_fake_hardware = LaunchConfiguration(use_fake_hardware_param_name)
    fake_sensor_commands = LaunchConfiguration(fake_sensor_commands_param_name)
    robot_controller = LaunchConfiguration(robot_controller_param_name)
    test_object = LaunchConfiguration(test_object_param_name)
    test_object_x_pos = LaunchConfiguration(test_object_x_pos_param_name)
    test_object_y_pos = LaunchConfiguration(test_object_y_pos_param_name)
    test_object_z_pos = LaunchConfiguration(test_object_z_pos_param_name)
    start_pick_up_process = LaunchConfiguration(start_pick_up_process_param_name)

    # Get URDF via xacro
    flexiv_urdf_xacro = PathJoinSubstitution(
        [FindPackageShare("flexiv_description"), "urdf", "rizon.urdf.xacro"]
    )

    # Get URDF via xacro
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            flexiv_urdf_xacro,
            " ",
            "robot_ip:=",
            robot_ip,
            " ",
            "local_ip:=",
            local_ip,
            " ",
            "name:=",
            "rizon",
            " ",
            "rizon_type:=",
            rizon_type,
            " ",
            "use_fake_hardware:=",
            use_fake_hardware,
            " ",
            "fake_sensor_commands:=",
            fake_sensor_commands,
        ]
    )
    robot_description = {"robot_description": robot_description_content}

    # RViZ
    rviz_config_file = PathJoinSubstitution(
        [FindPackageShare("flexiv_description"), "rviz", "view_rizon_object.rviz"]
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
        condition=IfCondition(start_rviz),
    )

    # Robot controllers
    robot_controllers = PathJoinSubstitution(
        [FindPackageShare("flexiv_bringup"), "config", "rizon_controllers.yaml"]
    )

    # Controller Manager
    ros2_control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[robot_description, robot_controllers],
        output="both",
    )

    # Robot state publisher
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="both",
        parameters=[robot_description],
    )

    # Run robot controller
    robot_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[robot_controller, "--controller-manager", "/controller_manager"],
    )

    # Run joint state broadcaster
    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "joint_state_broadcaster",
            "--controller-manager",
            "/controller_manager",
        ],
    )

    # Run force torque sensor broadcaster
    force_torque_sensor_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "force_torque_sensor_broadcaster",
            "--controller-manager",
            "/controller_manager",
        ],
    )

    # Run external wrench in base broadcaster
    external_wrench_in_base_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "external_wrench_in_base_broadcaster",
            "--controller-manager",
            "/controller_manager",
        ],
    )

    # Run external wrench in tcp broadcaster
    external_wrench_in_tcp_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "external_wrench_in_tcp_broadcaster",
            "--controller-manager",
            "/controller_manager",
        ],
    )

    # Run tcp pose state broadcaster
    tcp_pose_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "tcp_pose_state_broadcaster",
            "--controller-manager",
            "/controller_manager",
        ],
    )

    # Run gpio controller
    gpio_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["gpio_controller", "--controller-manager", "/controller_manager"],
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
            "}}, scale: {x: 0.001, y: 0.001, z: .001}, color: {r: 0.0, g: 1.0, b: 0.0, a: 1.0}, mesh_resource: \"",
            "package://robotic_depowdering/test_parts/",
            test_object,
            ".bin.stl",
            "\"}\"",
        ]],
        shell=True,
    )

    # Delay rviz start after `joint_state_broadcaster`
    delay_rviz_after_joint_state_broadcaster_spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=joint_state_broadcaster_spawner,
            on_exit=[rviz_node],
        )
    )

    # Delay start of robot_controller after `joint_state_broadcaster`
    delay_robot_controller_spawner_after_joint_state_broadcaster_spawner = (
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=joint_state_broadcaster_spawner,
                on_exit=[robot_controller_spawner],
            )
        )
    )

    # Delay publishing object to /visualization_marker after RViz set up
    delay_publish_object_to_vis_topic = RegisterEventHandler(
        event_handler=OnProcessStart(
            target_action=rviz_node,
            on_start=[publish_object_cmd]
        )
    )

    # Launch robotic_depowdering service.
    


    nodes = [
        ros2_control_node,
        robot_state_publisher_node,
        joint_state_broadcaster_spawner,
        force_torque_sensor_broadcaster_spawner,
        external_wrench_in_base_broadcaster_spawner,
        external_wrench_in_tcp_broadcaster_spawner,
        tcp_pose_state_broadcaster_spawner,
        gpio_controller_spawner,
        delay_rviz_after_joint_state_broadcaster_spawner,
        delay_robot_controller_spawner_after_joint_state_broadcaster_spawner,
        delay_publish_object_to_vis_topic,
    ]

    return LaunchDescription(declared_arguments + nodes)
