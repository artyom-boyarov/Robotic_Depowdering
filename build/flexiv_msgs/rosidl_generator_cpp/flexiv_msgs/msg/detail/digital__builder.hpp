// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flexiv_msgs:msg/Digital.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__DIGITAL__BUILDER_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__DIGITAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flexiv_msgs/msg/detail/digital__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flexiv_msgs
{

namespace msg
{

namespace builder
{

class Init_Digital_state
{
public:
  explicit Init_Digital_state(::flexiv_msgs::msg::Digital & msg)
  : msg_(msg)
  {}
  ::flexiv_msgs::msg::Digital state(::flexiv_msgs::msg::Digital::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flexiv_msgs::msg::Digital msg_;
};

class Init_Digital_pin
{
public:
  Init_Digital_pin()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Digital_state pin(::flexiv_msgs::msg::Digital::_pin_type arg)
  {
    msg_.pin = std::move(arg);
    return Init_Digital_state(msg_);
  }

private:
  ::flexiv_msgs::msg::Digital msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flexiv_msgs::msg::Digital>()
{
  return flexiv_msgs::msg::builder::Init_Digital_pin();
}

}  // namespace flexiv_msgs

#endif  // FLEXIV_MSGS__MSG__DETAIL__DIGITAL__BUILDER_HPP_
