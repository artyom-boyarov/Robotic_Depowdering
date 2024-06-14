// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from flexiv_msgs:msg/RobotStates.idl
// generated code does not contain a copyright notice
#include "flexiv_msgs/msg/detail/robot_states__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "flexiv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "flexiv_msgs/msg/detail/robot_states__struct.h"
#include "flexiv_msgs/msg/detail/robot_states__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/accel__functions.h"  // tcp_vel
#include "geometry_msgs/msg/detail/pose__functions.h"  // cam_pose, flange_pose, tcp_pose, tcp_pose_des
#include "geometry_msgs/msg/detail/wrench__functions.h"  // ext_wrench_base_frame, ext_wrench_tcp_frame, ft_sensor_raw

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_flexiv_msgs
size_t get_serialized_size_geometry_msgs__msg__Accel(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_flexiv_msgs
size_t max_serialized_size_geometry_msgs__msg__Accel(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_flexiv_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Accel)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_flexiv_msgs
size_t get_serialized_size_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_flexiv_msgs
size_t max_serialized_size_geometry_msgs__msg__Pose(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_flexiv_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_flexiv_msgs
size_t get_serialized_size_geometry_msgs__msg__Wrench(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_flexiv_msgs
size_t max_serialized_size_geometry_msgs__msg__Wrench(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_flexiv_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Wrench)();


using _RobotStates__ros_msg_type = flexiv_msgs__msg__RobotStates;

static bool _RobotStates__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotStates__ros_msg_type * ros_message = static_cast<const _RobotStates__ros_msg_type *>(untyped_ros_message);
  // Field name: q
  {
    size_t size = 7;
    auto array_ptr = ros_message->q;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: theta
  {
    size_t size = 7;
    auto array_ptr = ros_message->theta;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: dq
  {
    size_t size = 7;
    auto array_ptr = ros_message->dq;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: dtheta
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtheta;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tau
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tau_des
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_des;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tau_dot
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_dot;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tau_ext
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_ext;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tcp_pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tcp_pose, cdr))
    {
      return false;
    }
  }

  // Field name: tcp_pose_des
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tcp_pose_des, cdr))
    {
      return false;
    }
  }

  // Field name: tcp_vel
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Accel
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tcp_vel, cdr))
    {
      return false;
    }
  }

  // Field name: cam_pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->cam_pose, cdr))
    {
      return false;
    }
  }

  // Field name: flange_pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->flange_pose, cdr))
    {
      return false;
    }
  }

  // Field name: ft_sensor_raw
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Wrench
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->ft_sensor_raw, cdr))
    {
      return false;
    }
  }

  // Field name: ext_wrench_tcp_frame
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Wrench
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->ext_wrench_tcp_frame, cdr))
    {
      return false;
    }
  }

  // Field name: ext_wrench_base_frame
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Wrench
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->ext_wrench_base_frame, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _RobotStates__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotStates__ros_msg_type * ros_message = static_cast<_RobotStates__ros_msg_type *>(untyped_ros_message);
  // Field name: q
  {
    size_t size = 7;
    auto array_ptr = ros_message->q;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: theta
  {
    size_t size = 7;
    auto array_ptr = ros_message->theta;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: dq
  {
    size_t size = 7;
    auto array_ptr = ros_message->dq;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: dtheta
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtheta;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tau
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tau_des
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_des;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tau_dot
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_dot;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tau_ext
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_ext;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tcp_pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tcp_pose))
    {
      return false;
    }
  }

  // Field name: tcp_pose_des
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tcp_pose_des))
    {
      return false;
    }
  }

  // Field name: tcp_vel
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Accel
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tcp_vel))
    {
      return false;
    }
  }

  // Field name: cam_pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->cam_pose))
    {
      return false;
    }
  }

  // Field name: flange_pose
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->flange_pose))
    {
      return false;
    }
  }

  // Field name: ft_sensor_raw
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Wrench
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->ft_sensor_raw))
    {
      return false;
    }
  }

  // Field name: ext_wrench_tcp_frame
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Wrench
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->ext_wrench_tcp_frame))
    {
      return false;
    }
  }

  // Field name: ext_wrench_base_frame
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Wrench
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->ext_wrench_base_frame))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flexiv_msgs
size_t get_serialized_size_flexiv_msgs__msg__RobotStates(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotStates__ros_msg_type * ros_message = static_cast<const _RobotStates__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name q
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->q;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name theta
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->theta;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dq
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dq;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dtheta
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dtheta;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_des
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau_des;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_dot
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau_dot;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_ext
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau_ext;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tcp_pose

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->tcp_pose), current_alignment);
  // field.name tcp_pose_des

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->tcp_pose_des), current_alignment);
  // field.name tcp_vel

  current_alignment += get_serialized_size_geometry_msgs__msg__Accel(
    &(ros_message->tcp_vel), current_alignment);
  // field.name cam_pose

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->cam_pose), current_alignment);
  // field.name flange_pose

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->flange_pose), current_alignment);
  // field.name ft_sensor_raw

  current_alignment += get_serialized_size_geometry_msgs__msg__Wrench(
    &(ros_message->ft_sensor_raw), current_alignment);
  // field.name ext_wrench_tcp_frame

  current_alignment += get_serialized_size_geometry_msgs__msg__Wrench(
    &(ros_message->ext_wrench_tcp_frame), current_alignment);
  // field.name ext_wrench_base_frame

  current_alignment += get_serialized_size_geometry_msgs__msg__Wrench(
    &(ros_message->ext_wrench_base_frame), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _RobotStates__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_flexiv_msgs__msg__RobotStates(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flexiv_msgs
size_t max_serialized_size_flexiv_msgs__msg__RobotStates(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: q
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: theta
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: dq
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: dtheta
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_des
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_dot
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_ext
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tcp_pose
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: tcp_pose_des
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: tcp_vel
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Accel(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: cam_pose
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: flange_pose
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Pose(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: ft_sensor_raw
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Wrench(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: ext_wrench_tcp_frame
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Wrench(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: ext_wrench_base_frame
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Wrench(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = flexiv_msgs__msg__RobotStates;
    is_plain =
      (
      offsetof(DataType, ext_wrench_base_frame) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RobotStates__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_flexiv_msgs__msg__RobotStates(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RobotStates = {
  "flexiv_msgs::msg",
  "RobotStates",
  _RobotStates__cdr_serialize,
  _RobotStates__cdr_deserialize,
  _RobotStates__get_serialized_size,
  _RobotStates__max_serialized_size
};

static rosidl_message_type_support_t _RobotStates__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotStates,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, flexiv_msgs, msg, RobotStates)() {
  return &_RobotStates__type_support;
}

#if defined(__cplusplus)
}
#endif
