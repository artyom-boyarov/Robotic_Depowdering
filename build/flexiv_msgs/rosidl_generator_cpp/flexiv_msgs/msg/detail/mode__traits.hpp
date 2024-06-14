// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flexiv_msgs:msg/Mode.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__MODE__TRAITS_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flexiv_msgs/msg/detail/mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace flexiv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Mode & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mode & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mode & msg, bool use_flow_style = false)
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
  const flexiv_msgs::msg::Mode & msg,
  std::ostream & out, size_t indentation = 0)
{
  flexiv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flexiv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const flexiv_msgs::msg::Mode & msg)
{
  return flexiv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flexiv_msgs::msg::Mode>()
{
  return "flexiv_msgs::msg::Mode";
}

template<>
inline const char * name<flexiv_msgs::msg::Mode>()
{
  return "flexiv_msgs/msg/Mode";
}

template<>
struct has_fixed_size<flexiv_msgs::msg::Mode>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<flexiv_msgs::msg::Mode>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<flexiv_msgs::msg::Mode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLEXIV_MSGS__MSG__DETAIL__MODE__TRAITS_HPP_
