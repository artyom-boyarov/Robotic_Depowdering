cmake_minimum_required(VERSION 3.8)
project(robotic_depowdering)
set(CMAKE_CXX_STANDARD 20)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(robotic_depowdering_interfaces REQUIRED)
find_package(PCL 1.9 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rizon_pick_and_place REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning REQUIRED)


include_directories(include ${PCL_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
link_directories(${CMAKE_INSTALL_PREFIX}/../gpd/lib)
include_directories(${CMAKE_INSTALL_PREFIX}/../gpd/include)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(server src/add_two_ints_server.cpp)
ament_target_dependencies(server rclcpp example_interfaces)

add_executable(client src/add_two_ints_client.cpp)
ament_target_dependencies(client rclcpp example_interfaces)

# add_executable(gripper_test src/gripper_test.cpp)
# ament_target_dependencies(gripper_test rclcpp)
# # Since the Flexiv RDK isn't available as an ament package, we include it like this:
# # NOTE: Disable the gripper test since there are some issues with the new RDK version.
# target_link_libraries(gripper_test flexiv_rdk.x86_64-linux-gnu)
# target_link_directories(gripper_test PRIVATE ${PROJECT_SOURCE_DIR}/../flexiv_ros2/flexiv_hardware/rdk/lib)
# target_include_directories(gripper_test PRIVATE ${PROJECT_SOURCE_DIR}/../flexiv_ros2/flexiv_hardware/rdk/include)

add_executable(pick_up_object src/pick_up_object.cpp src/gpd_interface.cpp)
ament_target_dependencies(pick_up_object rizon_pick_and_place rclcpp robotic_depowdering_interfaces trajectory_msgs builtin_interfaces tf2 tf2_ros tf2_eigen Eigen3)
# GPD isn't available as an ament package, so include it like this:
target_link_libraries(pick_up_object ${PCL_LIBRARIES} gpd)
target_link_directories(pick_up_object PRIVATE ${CMAKE_INSTALL_PREFIX}/../gpd/lib)
target_include_directories(pick_up_object PRIVATE ${CMAKE_INSTALL_PREFIX}/../gpd/include)
target_link_libraries(pick_up_object flexiv_rdk.x86_64-linux-gnu)
target_link_directories(pick_up_object PRIVATE ${PROJECT_SOURCE_DIR}/../flexiv_ros2/flexiv_hardware/rdk/lib)
target_include_directories(pick_up_object PRIVATE ${PROJECT_SOURCE_DIR}/../flexiv_ros2/flexiv_hardware/rdk/include)

add_executable(moveit_collision_detection_demo src/moveit_collision_detection_demo.cpp)
ament_target_dependencies(moveit_collision_detection_demo rclcpp moveit_core moveit_ros_planning)

add_executable(loop_parts_collision_demo src/loop_parts_collision_demo.cpp)
ament_target_dependencies(loop_parts_collision_demo rclcpp Eigen3 visualization_msgs)
target_include_directories(loop_parts_collision_demo PRIVATE ~/miniforge3/include)
target_link_directories(loop_parts_collision_demo PRIVATE ~/miniforge3/lib)
target_link_libraries(loop_parts_collision_demo hpp-fcl)

install( TARGETS
  server
  client
  pick_up_object
  # gripper_test
  moveit_collision_detection_demo
  DESTINATION lib/${PROJECT_NAME}
)

set(GPD_SRC_DIR ../gpd)
install(
  DIRECTORY cfg test_parts launch ${GPD_SRC_DIR}/models ${GPD_SRC_DIR}/pytorch
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
