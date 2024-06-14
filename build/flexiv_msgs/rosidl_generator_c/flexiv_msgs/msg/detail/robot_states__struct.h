// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flexiv_msgs:msg/RobotStates.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__STRUCT_H_
#define FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tcp_pose'
// Member 'tcp_pose_des'
// Member 'cam_pose'
// Member 'flange_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'tcp_vel'
#include "geometry_msgs/msg/detail/accel__struct.h"
// Member 'ft_sensor_raw'
// Member 'ext_wrench_tcp_frame'
// Member 'ext_wrench_base_frame'
#include "geometry_msgs/msg/detail/wrench__struct.h"

/// Struct defined in msg/RobotStates in the package flexiv_msgs.
typedef struct flexiv_msgs__msg__RobotStates
{
  double q[7];
  double theta[7];
  double dq[7];
  double dtheta[7];
  double tau[7];
  double tau_des[7];
  double tau_dot[7];
  double tau_ext[7];
  geometry_msgs__msg__Pose tcp_pose;
  geometry_msgs__msg__Pose tcp_pose_des;
  geometry_msgs__msg__Accel tcp_vel;
  geometry_msgs__msg__Pose cam_pose;
  geometry_msgs__msg__Pose flange_pose;
  geometry_msgs__msg__Wrench ft_sensor_raw;
  geometry_msgs__msg__Wrench ext_wrench_tcp_frame;
  geometry_msgs__msg__Wrench ext_wrench_base_frame;
} flexiv_msgs__msg__RobotStates;

// Struct for a sequence of flexiv_msgs__msg__RobotStates.
typedef struct flexiv_msgs__msg__RobotStates__Sequence
{
  flexiv_msgs__msg__RobotStates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flexiv_msgs__msg__RobotStates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__STRUCT_H_
