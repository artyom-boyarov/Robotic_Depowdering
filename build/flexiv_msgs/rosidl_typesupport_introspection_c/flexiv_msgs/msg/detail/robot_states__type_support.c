// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from flexiv_msgs:msg/RobotStates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "flexiv_msgs/msg/detail/robot_states__rosidl_typesupport_introspection_c.h"
#include "flexiv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "flexiv_msgs/msg/detail/robot_states__functions.h"
#include "flexiv_msgs/msg/detail/robot_states__struct.h"


// Include directives for member types
// Member `tcp_pose`
// Member `tcp_pose_des`
// Member `cam_pose`
// Member `flange_pose`
#include "geometry_msgs/msg/pose.h"
// Member `tcp_pose`
// Member `tcp_pose_des`
// Member `cam_pose`
// Member `flange_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `tcp_vel`
#include "geometry_msgs/msg/accel.h"
// Member `tcp_vel`
#include "geometry_msgs/msg/detail/accel__rosidl_typesupport_introspection_c.h"
// Member `ft_sensor_raw`
// Member `ext_wrench_tcp_frame`
// Member `ext_wrench_base_frame`
#include "geometry_msgs/msg/wrench.h"
// Member `ft_sensor_raw`
// Member `ext_wrench_tcp_frame`
// Member `ext_wrench_base_frame`
#include "geometry_msgs/msg/detail/wrench__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  flexiv_msgs__msg__RobotStates__init(message_memory);
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_fini_function(void * message_memory)
{
  flexiv_msgs__msg__RobotStates__fini(message_memory);
}

size_t flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__q(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__q(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__q(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__q(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__q(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__q(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__q(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__theta(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__theta(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__theta(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__theta(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__theta(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__theta(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__theta(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__dq(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__dq(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__dq(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__dq(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__dq(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__dq(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__dq(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__dtheta(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__dtheta(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__dtheta(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__dtheta(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__dtheta(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__dtheta(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__dtheta(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__tau(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__tau(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__tau(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__tau_des(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau_des(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau_des(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__tau_des(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau_des(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__tau_des(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau_des(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__tau_dot(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau_dot(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau_dot(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__tau_dot(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau_dot(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__tau_dot(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau_dot(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__tau_ext(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau_ext(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau_ext(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__tau_ext(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau_ext(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__tau_ext(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau_ext(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array[16] = {
  {
    "q",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, q),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__q,  // size() function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__q,  // get_const(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__q,  // get(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__q,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__q,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, theta),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__theta,  // size() function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__theta,  // get_const(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__theta,  // get(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__theta,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__theta,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dq",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, dq),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__dq,  // size() function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__dq,  // get_const(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__dq,  // get(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__dq,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__dq,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dtheta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, dtheta),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__dtheta,  // size() function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__dtheta,  // get_const(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__dtheta,  // get(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__dtheta,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__dtheta,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tau",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, tau),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__tau,  // size() function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau,  // get_const(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau,  // get(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__tau,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__tau,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tau_des",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, tau_des),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__tau_des,  // size() function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau_des,  // get_const(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau_des,  // get(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__tau_des,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__tau_des,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tau_dot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, tau_dot),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__tau_dot,  // size() function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau_dot,  // get_const(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau_dot,  // get(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__tau_dot,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__tau_dot,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tau_ext",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, tau_ext),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__size_function__RobotStates__tau_ext,  // size() function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_const_function__RobotStates__tau_ext,  // get_const(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__get_function__RobotStates__tau_ext,  // get(index) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__fetch_function__RobotStates__tau_ext,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__assign_function__RobotStates__tau_ext,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tcp_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, tcp_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tcp_pose_des",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, tcp_pose_des),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tcp_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, tcp_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cam_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, cam_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flange_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, flange_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ft_sensor_raw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, ft_sensor_raw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ext_wrench_tcp_frame",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, ext_wrench_tcp_frame),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ext_wrench_base_frame",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__RobotStates, ext_wrench_base_frame),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_members = {
  "flexiv_msgs__msg",  // message namespace
  "RobotStates",  // message name
  16,  // number of fields
  sizeof(flexiv_msgs__msg__RobotStates),
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array,  // message members
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_init_function,  // function to initialize message memory (memory has to be allocated)
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_type_support_handle = {
  0,
  &flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flexiv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flexiv_msgs, msg, RobotStates)() {
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array[9].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array[10].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Accel)();
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array[11].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array[12].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array[13].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Wrench)();
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array[14].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Wrench)();
  flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_member_array[15].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Wrench)();
  if (!flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_type_support_handle.typesupport_identifier) {
    flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &flexiv_msgs__msg__RobotStates__rosidl_typesupport_introspection_c__RobotStates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
