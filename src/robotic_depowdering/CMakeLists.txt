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

add_executable(gpd_service src/gpd_service.cpp)
ament_target_dependencies(gpd_service rclcpp robotic_depowdering_interfaces tf2 tf2_ros tf2_eigen Eigen3 gpd)
target_link_libraries(gpd_service ${PCL_LIBRARIES} gpd)

add_executable(pick_up_object src/pick_up_object.cpp)
ament_target_dependencies(pick_up_object rclcpp robotic_depowdering_interfaces trajectory_msgs builtin_interfaces)

install( TARGETS
  server
  client
  gpd_service
  pick_up_object
  DESTINATION lib/${PROJECT_NAME}
)

set(GPD_SRC_DIR ../gpd)
install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/cfg ${GPD_SRC_DIR}/models ${GPD_SRC_DIR}/pytorch
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
