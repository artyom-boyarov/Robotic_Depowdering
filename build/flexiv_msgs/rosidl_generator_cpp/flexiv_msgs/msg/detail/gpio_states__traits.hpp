// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flexiv_msgs:msg/GPIOStates.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__GPIO_STATES__TRAITS_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__GPIO_STATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flexiv_msgs/msg/detail/gpio_states__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'states'
#include "flexiv_msgs/msg/detail/digital__traits.hpp"

namespace flexiv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GPIOStates & msg,
  std::ostream & out)
{
  out << "{";
  // member: states
  {
    if (msg.states.size() == 0) {
      out << "states: []";
    } else {
      out << "states: [";
      size_t pending_items = msg.states.size();
      for (auto item : msg.states) {
        to_flow_style_yaml(item, out);
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
  const GPIOStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.states.size() == 0) {
      out << "states: []\n";
    } else {
      out << "states:\n";
      for (auto item : msg.states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GPIOStates & msg, bool use_flow_style = false)
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
  const flexiv_msgs::msg::GPIOStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  flexiv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flexiv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const flexiv_msgs::msg::GPIOStates & msg)
{
  return flexiv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flexiv_msgs::msg::GPIOStates>()
{
  return "flexiv_msgs::msg::GPIOStates";
}

template<>
inline const char * name<flexiv_msgs::msg::GPIOStates>()
{
  return "flexiv_msgs/msg/GPIOStates";
}

template<>
struct has_fixed_size<flexiv_msgs::msg::GPIOStates>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<flexiv_msgs::msg::GPIOStates>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<flexiv_msgs::msg::GPIOStates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLEXIV_MSGS__MSG__DETAIL__GPIO_STATES__TRAITS_HPP_
