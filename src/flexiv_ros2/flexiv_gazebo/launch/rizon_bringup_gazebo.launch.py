import os
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    RegisterEventHandler,
    AppendEnvironmentVariable,
    IncludeLaunchDescription,
)
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.event_handlers import OnProcessExit
from launch.substitutions import (
    Command,
    FindExecutable,
    LaunchConfiguration,
    PathJoinSubstitution,
    PythonExpression,
)
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    rizon_type_param_name = "rizon_type"
    robot_ip_param_name = "robot_ip"
    local_ip_param_name = "local_ip"
    start_rviz_param_name = "start_rviz"
    use_fake_hardware_param_name = "use_fake_hardware"
    fake_sensor_commands_param_name = "fake_sensor_commands"
    robot_controller_param_name = "robot_controller"
    rizon_prefix_param_name = "rizon_prefix"
    gripper_prefix_param_name = "gripper_prefix"
    package_name_gazebo = "flexiv_gazebo"
    package_name_description = "flexiv_description"
    declare_simulator_cmd = "headless"
    declare_use_sim_time_cmd = "use_sim_time"
    declare_use_simulator_cmd = "use_simulator"
    declare_world_cmd = "world"
    declare_x_cmd = "x"
    declare_y_cmd = "y"
    declare_z_cmd = "z"
    declare_roll_cmd = "roll"
    declare_pitch_cmd = "pitch"
    declare_yaw_cmd = "yaw"
    declare_use_robot_state_pub_cmd = "use_robot_state_pub"

    # Constants for paths to different files and folders
    world_file_path = (
        "worlds/empty.world"  # e.g. 'world/empty.world', 'world/house.world'
    )
    gazebo_launch_file_path = "launch"

    ros_gz_bridge_config_file_path = "config/ros_gz_bridge.yaml"

    # Set the path to different files and folders.
    pkg_ros_gz_sim = FindPackageShare(package="ros_gz_sim").find("ros_gz_sim")
    pkg_share_gazebo = FindPackageShare(package=package_name_gazebo).find(
        package_name_gazebo
    )
    default_ros_gz_bridge_config_file_path = os.path.join(
        pkg_share_gazebo, ros_gz_bridge_config_file_path
    )
    default_ros_gz_bridge_config_file_path = os.path.join(
        pkg_share_gazebo, ros_gz_bridge_config_file_path
    )
    gazebo_launch_file_path = os.path.join(pkg_share_gazebo, gazebo_launch_file_path)
    world_path = os.path.join(pkg_share_gazebo, world_file_path)
    # Declare arguments
    declared_arguments = []

    declared_arguments.append(
        DeclareLaunchArgument(
            rizon_type_param_name,
            description="Type of the Flexiv Rizon robot.",
            default_value="rizon4s",
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
            declare_simulator_cmd,
            default_value="False",
            description="Display the Gazebo GUI if False, otherwise run in headless mode",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_use_sim_time_cmd,
            default_value="false",
            description="Use simulation (Gazebo) clock if true",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_use_simulator_cmd,
            default_value="True",
            description="Whether to start Gazebo",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_world_cmd,
            default_value=world_path,
            description="Full path to the world model file to load",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_use_robot_state_pub_cmd,
            default_value="True",
            description="Whether to start the robot state publisher",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_x_cmd,
            default_value="0.0",
            description="x component of initial position, meters",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_y_cmd,
            default_value="0.0",
            description="y component of initial position, meters",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_z_cmd,
            default_value="0.0",
            description="z component of initial position, meters",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_roll_cmd,
            default_value="0.0",
            description="roll component of initial position, meters",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_pitch_cmd,
            default_value="0.0",
            description="pitch component of initial position, meters",
        )
    )

    declared_arguments.append(
        DeclareLaunchArgument(
            declare_yaw_cmd,
            default_value="0.0",
            description="yaw component of initial position, meters",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            rizon_prefix_param_name,
            default_value="",
            description="Prefix for the Rizon robot.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            gripper_prefix_param_name,
            default_value="gripper_",
            description="Prefix for the gripper.",
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
    headless = LaunchConfiguration("headless")
    use_sim_time = LaunchConfiguration("use_sim_time")
    use_simulator = LaunchConfiguration("use_simulator")
    use_robot_state_pub = LaunchConfiguration("use_robot_state_pub")
    world = LaunchConfiguration("world")
    rizon_prefix = LaunchConfiguration(rizon_prefix_param_name)
    gripper_prefix = LaunchConfiguration(gripper_prefix_param_name)
    # Set the default pose
    x = LaunchConfiguration("x")
    y = LaunchConfiguration("y")
    z = LaunchConfiguration("z")
    roll = LaunchConfiguration("roll")
    pitch = LaunchConfiguration("pitch")
    yaw = LaunchConfiguration("yaw")
    # Get URDF via xacro
    pkg_flexiv_description = FindPackageShare(package="flexiv_description").find(
        "flexiv_description"
    )

    # Get URDF via xacro
    flexiv_urdf_xacro = PathJoinSubstitution(
        [pkg_flexiv_description, "urdf", "rizon.urdf.xacro"]
    )

    gazebo_models_path = PathJoinSubstitution(
        [pkg_flexiv_description, ".."]
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
            " ",
            "rizon_prefix:=",
            rizon_prefix,
            " ",
            "gripper_prefix:=",
            gripper_prefix,
        ]
    )
    robot_description = {"robot_description": robot_description_content}

    # Specify the actions
    set_env_vars_resources = AppendEnvironmentVariable(
        "GZ_SIM_RESOURCE_PATH", gazebo_models_path
    )
    # Start Gazebo server
    start_gazebo_server_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, "launch", "gz_sim.launch.py")
        ),
        condition=IfCondition(use_simulator),
        launch_arguments={
            "gz_args": ["-r -s -v4 ", world],
            "on_exit_shutdown": "true",
        }.items(),
    )

    # Start Gazebo client
    start_gazebo_client_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, "launch", "gz_sim.launch.py")
        ),
        launch_arguments={"gz_args": "-g -v4 "}.items(),
        condition=IfCondition(PythonExpression([use_simulator, " and not ", headless])),
    )
    # Subscribe to the joint states of the robot, and publish the 3D pose of each link.
    start_robot_state_publisher_cmd = Node(
        condition=IfCondition(use_robot_state_pub),
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="both",
        parameters=[
            {
                "use_sim_time": use_sim_time,
                "robot_description": robot_description_content,
            }
        ],
    )
    # RViZ
    rviz_config_file = PathJoinSubstitution(
        [FindPackageShare("flexiv_description"), "rviz", "view_rizon.rviz"]
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="both",
        arguments=["-d", rviz_config_file],
        condition=IfCondition(start_rviz),
    )
    # Spawn the robot
    start_gazebo_ros_spawner_cmd = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=[
            "-name",
            rizon_type_param_name,
            "-string",
            robot_description_content,
            "-x",
            x,
            "-y",
            y,
            "-z",
            z,
            "-R",
            roll,
            "-P",
            pitch,
            "-Y",
            yaw,
        ],
        output="screen",
    )

    # Bridge ROS topics and Gazebo messages for establishing communication
    start_gazebo_ros_bridge_cmd = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        parameters=[
            {
                "config_file": default_ros_gz_bridge_config_file_path,
            }
        ],
        output="screen",
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
        output="screen",
    )
    """
    
    # Robot state publisher
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="both",
        parameters=[robot_description],
    )
    """
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

    # Launch the joint state broadcaster after spawning the robot
    delay_joint_state_broadcaster_after_gazebo_spawner_cmd = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=start_gazebo_ros_spawner_cmd,
            on_exit=[joint_state_broadcaster_spawner],
        )
    )

    # Delay rviz start after joint_state_broadcaster
    delay_rviz_after_joint_state_broadcaster_spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=joint_state_broadcaster_spawner,
            on_exit=[rviz_node],
        )
    )

    # Delay start of robot_controller after joint_state_broadcaster
    delay_robot_controller_spawner_after_joint_state_broadcaster_spawner = (
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=joint_state_broadcaster_spawner,
                on_exit=[robot_controller_spawner],
            )
        )
    )

    nodes = [
        # set_env_vars_resources,
        ros2_control_node,
        # robot_state_publisher_node,
        # joint_state_broadcaster_spawner,
        delay_joint_state_broadcaster_after_gazebo_spawner_cmd,
        force_torque_sensor_broadcaster_spawner,
        external_wrench_in_base_broadcaster_spawner,
        external_wrench_in_tcp_broadcaster_spawner,
        tcp_pose_state_broadcaster_spawner,
        gpio_controller_spawner,
        delay_rviz_after_joint_state_broadcaster_spawner,
        delay_robot_controller_spawner_after_joint_state_broadcaster_spawner,
        # Gazebo
        # set_env_vars_resources,
        start_gazebo_server_cmd,
        start_gazebo_client_cmd,
        start_gazebo_ros_spawner_cmd,
        start_gazebo_ros_bridge_cmd,
        start_robot_state_publisher_cmd,
    ]

    return LaunchDescription(declared_arguments + nodes)
