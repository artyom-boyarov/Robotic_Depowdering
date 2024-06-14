// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flexiv_msgs:msg/GPIOStates.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__GPIO_STATES__BUILDER_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__GPIO_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flexiv_msgs/msg/detail/gpio_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flexiv_msgs
{

namespace msg
{

namespace builder
{

class Init_GPIOStates_states
{
public:
  Init_GPIOStates_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::flexiv_msgs::msg::GPIOStates states(::flexiv_msgs::msg::GPIOStates::_states_type arg)
  {
    msg_.states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flexiv_msgs::msg::GPIOStates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flexiv_msgs::msg::GPIOStates>()
{
  return flexiv_msgs::msg::builder::Init_GPIOStates_states();
}

}  // namespace flexiv_msgs

#endif  // FLEXIV_MSGS__MSG__DETAIL__GPIO_STATES__BUILDER_HPP_
