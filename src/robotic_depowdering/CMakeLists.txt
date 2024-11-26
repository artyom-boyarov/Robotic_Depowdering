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
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_visual_tools REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(ament_index_cpp REQUIRED)


include_directories(include ${PCL_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})

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

add_executable(pick_up_object src/pick_up_object.cpp)
ament_target_dependencies(
  pick_up_object 
  rizon_pick_and_place 
  rclcpp 
  robotic_depowdering_interfaces 
  moveit_ros_planning_interface
  moveit_visual_tools
  trajectory_msgs 
  builtin_interfaces 
  tf2 
  tf2_ros 
  tf2_eigen 
  Eigen3 
  sensor_msgs
  shape_msgs
  ament_index_cpp
)

add_executable(move_to_pose_service src/move_to_pose_service.cpp)
target_include_directories(move_to_pose_service PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
  
target_compile_features(move_to_pose_service PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  move_to_pose_service
  "moveit_ros_planning_interface"
  "rclcpp"
  "moveit_visual_tools"
  "geometry_msgs"
  "robotic_depowdering_interfaces"
)
# target_link_directories(pick_up_object PRIVATE ${PROJECT_SOURCE_DIR}/../flexiv_ros2/flexiv_hardware/rdk/flexiv_rdk/lib)
target_include_directories(pick_up_object PRIVATE ${PROJECT_SOURCE_DIR}/../flexiv_ros2/flexiv_hardware/rdk/flexiv_rdk/include)
# target_link_directories(pick_up_object PRIVATE ~/Robotic_depowdering/build/flexiv_rdk/lib)


install( TARGETS
  server
  client
  pick_up_object
  move_to_pose_service
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch test_parts remeshed_test_parts
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
