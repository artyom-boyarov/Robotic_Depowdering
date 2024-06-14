// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from flexiv_msgs:msg/JointPosVel.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "flexiv_msgs/msg/detail/joint_pos_vel__rosidl_typesupport_introspection_c.h"
#include "flexiv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "flexiv_msgs/msg/detail/joint_pos_vel__functions.h"
#include "flexiv_msgs/msg/detail/joint_pos_vel__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  flexiv_msgs__msg__JointPosVel__init(message_memory);
}

void flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_fini_function(void * message_memory)
{
  flexiv_msgs__msg__JointPosVel__fini(message_memory);
}

size_t flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__size_function__JointPosVel__positions(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_const_function__JointPosVel__positions(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_function__JointPosVel__positions(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__fetch_function__JointPosVel__positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_const_function__JointPosVel__positions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__assign_function__JointPosVel__positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_function__JointPosVel__positions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__size_function__JointPosVel__velocities(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_const_function__JointPosVel__velocities(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_function__JointPosVel__velocities(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__fetch_function__JointPosVel__velocities(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_const_function__JointPosVel__velocities(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__assign_function__JointPosVel__velocities(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_function__JointPosVel__velocities(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_message_member_array[2] = {
  {
    "positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__JointPosVel, positions),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__size_function__JointPosVel__positions,  // size() function pointer
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_const_function__JointPosVel__positions,  // get_const(index) function pointer
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_function__JointPosVel__positions,  // get(index) function pointer
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__fetch_function__JointPosVel__positions,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__assign_function__JointPosVel__positions,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocities",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__JointPosVel, velocities),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__size_function__JointPosVel__velocities,  // size() function pointer
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_const_function__JointPosVel__velocities,  // get_const(index) function pointer
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__get_function__JointPosVel__velocities,  // get(index) function pointer
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__fetch_function__JointPosVel__velocities,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__assign_function__JointPosVel__velocities,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_message_members = {
  "flexiv_msgs__msg",  // message namespace
  "JointPosVel",  // message name
  2,  // number of fields
  sizeof(flexiv_msgs__msg__JointPosVel),
  flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_message_member_array,  // message members
  flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_init_function,  // function to initialize message memory (memory has to be allocated)
  flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_message_type_support_handle = {
  0,
  &flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flexiv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flexiv_msgs, msg, JointPosVel)() {
  if (!flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_message_type_support_handle.typesupport_identifier) {
    flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &flexiv_msgs__msg__JointPosVel__rosidl_typesupport_introspection_c__JointPosVel_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
