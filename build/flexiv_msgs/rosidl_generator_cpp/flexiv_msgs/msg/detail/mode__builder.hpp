// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flexiv_msgs:msg/Mode.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__MODE__BUILDER_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flexiv_msgs/msg/detail/mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flexiv_msgs
{

namespace msg
{

namespace builder
{

class Init_Mode_mode
{
public:
  Init_Mode_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::flexiv_msgs::msg::Mode mode(::flexiv_msgs::msg::Mode::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flexiv_msgs::msg::Mode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flexiv_msgs::msg::Mode>()
{
  return flexiv_msgs::msg::builder::Init_Mode_mode();
}

}  // namespace flexiv_msgs

#endif  // FLEXIV_MSGS__MSG__DETAIL__MODE__BUILDER_HPP_
