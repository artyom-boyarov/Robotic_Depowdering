// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flexiv_msgs:msg/JointPosVel.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__BUILDER_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flexiv_msgs/msg/detail/joint_pos_vel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flexiv_msgs
{

namespace msg
{

namespace builder
{

class Init_JointPosVel_velocities
{
public:
  explicit Init_JointPosVel_velocities(::flexiv_msgs::msg::JointPosVel & msg)
  : msg_(msg)
  {}
  ::flexiv_msgs::msg::JointPosVel velocities(::flexiv_msgs::msg::JointPosVel::_velocities_type arg)
  {
    msg_.velocities = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flexiv_msgs::msg::JointPosVel msg_;
};

class Init_JointPosVel_positions
{
public:
  Init_JointPosVel_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointPosVel_velocities positions(::flexiv_msgs::msg::JointPosVel::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return Init_JointPosVel_velocities(msg_);
  }

private:
  ::flexiv_msgs::msg::JointPosVel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flexiv_msgs::msg::JointPosVel>()
{
  return flexiv_msgs::msg::builder::Init_JointPosVel_positions();
}

}  // namespace flexiv_msgs

#endif  // FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__BUILDER_HPP_
