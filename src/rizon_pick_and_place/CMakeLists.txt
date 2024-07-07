cmake_minimum_required(VERSION 3.5)
project(rizon_pick_and_place)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_task_constructor_core REQUIRED)

# Generate custom service
find_package(rosidl_default_generators REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/PickAndPlace.srv"
)

add_executable(pick_and_place_node src/pick_and_place_service.cpp)
ament_target_dependencies(pick_and_place_node
  rclcpp
  std_msgs
  geometry_msgs
  moveit_core
  moveit_ros_planning_interface
  moveit_task_constructor_core
)

install(TARGETS
  pick_and_place_node
  DESTINATION lib/${PROJECT_NAME})

ament_export_dependencies(rosidl_default_runtime)

ament_package()
