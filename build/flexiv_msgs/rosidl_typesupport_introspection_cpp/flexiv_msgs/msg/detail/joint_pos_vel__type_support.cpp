// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from flexiv_msgs:msg/JointPosVel.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "flexiv_msgs/msg/detail/joint_pos_vel__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace flexiv_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void JointPosVel_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) flexiv_msgs::msg::JointPosVel(_init);
}

void JointPosVel_fini_function(void * message_memory)
{
  auto typed_message = static_cast<flexiv_msgs::msg::JointPosVel *>(message_memory);
  typed_message->~JointPosVel();
}

size_t size_function__JointPosVel__positions(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__JointPosVel__positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__JointPosVel__positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void fetch_function__JointPosVel__positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__JointPosVel__positions(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__JointPosVel__positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__JointPosVel__positions(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__JointPosVel__velocities(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__JointPosVel__velocities(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__JointPosVel__velocities(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void fetch_function__JointPosVel__velocities(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__JointPosVel__velocities(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__JointPosVel__velocities(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__JointPosVel__velocities(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember JointPosVel_message_member_array[2] = {
  {
    "positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs::msg::JointPosVel, positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__JointPosVel__positions,  // size() function pointer
    get_const_function__JointPosVel__positions,  // get_const(index) function pointer
    get_function__JointPosVel__positions,  // get(index) function pointer
    fetch_function__JointPosVel__positions,  // fetch(index, &value) function pointer
    assign_function__JointPosVel__positions,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "velocities",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs::msg::JointPosVel, velocities),  // bytes offset in struct
    nullptr,  // default value
    size_function__JointPosVel__velocities,  // size() function pointer
    get_const_function__JointPosVel__velocities,  // get_const(index) function pointer
    get_function__JointPosVel__velocities,  // get(index) function pointer
    fetch_function__JointPosVel__velocities,  // fetch(index, &value) function pointer
    assign_function__JointPosVel__velocities,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers JointPosVel_message_members = {
  "flexiv_msgs::msg",  // message namespace
  "JointPosVel",  // message name
  2,  // number of fields
  sizeof(flexiv_msgs::msg::JointPosVel),
  JointPosVel_message_member_array,  // message members
  JointPosVel_init_function,  // function to initialize message memory (memory has to be allocated)
  JointPosVel_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t JointPosVel_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &JointPosVel_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace flexiv_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<flexiv_msgs::msg::JointPosVel>()
{
  return &::flexiv_msgs::msg::rosidl_typesupport_introspection_cpp::JointPosVel_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, flexiv_msgs, msg, JointPosVel)() {
  return &::flexiv_msgs::msg::rosidl_typesupport_introspection_cpp::JointPosVel_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
