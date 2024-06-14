// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flexiv_msgs:msg/JointPosVel.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__TRAITS_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flexiv_msgs/msg/detail/joint_pos_vel__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace flexiv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const JointPosVel & msg,
  std::ostream & out)
{
  out << "{";
  // member: positions
  {
    if (msg.positions.size() == 0) {
      out << "positions: []";
    } else {
      out << "positions: [";
      size_t pending_items = msg.positions.size();
      for (auto item : msg.positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: velocities
  {
    if (msg.velocities.size() == 0) {
      out << "velocities: []";
    } else {
      out << "velocities: [";
      size_t pending_items = msg.velocities.size();
      for (auto item : msg.velocities) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JointPosVel & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions.size() == 0) {
      out << "positions: []\n";
    } else {
      out << "positions:\n";
      for (auto item : msg.positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: velocities
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.velocities.size() == 0) {
      out << "velocities: []\n";
    } else {
      out << "velocities:\n";
      for (auto item : msg.velocities) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JointPosVel & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace flexiv_msgs

namespace rosidl_generator_traits
{

[[deprecated("use flexiv_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const flexiv_msgs::msg::JointPosVel & msg,
  std::ostream & out, size_t indentation = 0)
{
  flexiv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flexiv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const flexiv_msgs::msg::JointPosVel & msg)
{
  return flexiv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flexiv_msgs::msg::JointPosVel>()
{
  return "flexiv_msgs::msg::JointPosVel";
}

template<>
inline const char * name<flexiv_msgs::msg::JointPosVel>()
{
  return "flexiv_msgs/msg/JointPosVel";
}

template<>
struct has_fixed_size<flexiv_msgs::msg::JointPosVel>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<flexiv_msgs::msg::JointPosVel>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<flexiv_msgs::msg::JointPosVel>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__TRAITS_HPP_
