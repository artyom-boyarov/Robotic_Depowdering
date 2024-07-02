from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():

    test_object_param_name = "test_object"
    test_object_x_pos_param_name = "test_object_x_pos"
    test_object_y_pos_param_name = "test_object_y_pos"
    test_object_z_pos_param_name = "test_object_z_pos"

    declared_arguments = []

    
    declared_arguments.append(
        DeclareLaunchArgument(
            test_object_param_name,
            default_value="/home/artyom/Robotic_Depowdering/src/robotic_depowdering/test_parts/Buckle.obj",
            description="File name (including directory and .obj extension) of the test object to be placed in scene which the robot has to pick up.",
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

    gpd_service = Node(
        package='robotic_depowdering',
        executable='gpd_service',
        name='gpd_service',
    )
    pick_up_object = Node(
        package='robotic_depowdering',
        executable='pick_up_object',
        name='pick_up_object',
        arguments=[test_object, test_object_x_pos, test_object_y_pos, test_object_z_pos]
    )

    nodes = [
        gpd_service,
        pick_up_object,

    ]
    return LaunchDescription(declared_arguments + nodes)