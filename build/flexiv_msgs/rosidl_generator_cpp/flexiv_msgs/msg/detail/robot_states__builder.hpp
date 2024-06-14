// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flexiv_msgs:msg/RobotStates.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__BUILDER_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flexiv_msgs/msg/detail/robot_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flexiv_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotStates_ext_wrench_base_frame
{
public:
  explicit Init_RobotStates_ext_wrench_base_frame(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  ::flexiv_msgs::msg::RobotStates ext_wrench_base_frame(::flexiv_msgs::msg::RobotStates::_ext_wrench_base_frame_type arg)
  {
    msg_.ext_wrench_base_frame = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_ext_wrench_tcp_frame
{
public:
  explicit Init_RobotStates_ext_wrench_tcp_frame(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_ext_wrench_base_frame ext_wrench_tcp_frame(::flexiv_msgs::msg::RobotStates::_ext_wrench_tcp_frame_type arg)
  {
    msg_.ext_wrench_tcp_frame = std::move(arg);
    return Init_RobotStates_ext_wrench_base_frame(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_ft_sensor_raw
{
public:
  explicit Init_RobotStates_ft_sensor_raw(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_ext_wrench_tcp_frame ft_sensor_raw(::flexiv_msgs::msg::RobotStates::_ft_sensor_raw_type arg)
  {
    msg_.ft_sensor_raw = std::move(arg);
    return Init_RobotStates_ext_wrench_tcp_frame(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_flange_pose
{
public:
  explicit Init_RobotStates_flange_pose(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_ft_sensor_raw flange_pose(::flexiv_msgs::msg::RobotStates::_flange_pose_type arg)
  {
    msg_.flange_pose = std::move(arg);
    return Init_RobotStates_ft_sensor_raw(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_cam_pose
{
public:
  explicit Init_RobotStates_cam_pose(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_flange_pose cam_pose(::flexiv_msgs::msg::RobotStates::_cam_pose_type arg)
  {
    msg_.cam_pose = std::move(arg);
    return Init_RobotStates_flange_pose(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_tcp_vel
{
public:
  explicit Init_RobotStates_tcp_vel(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_cam_pose tcp_vel(::flexiv_msgs::msg::RobotStates::_tcp_vel_type arg)
  {
    msg_.tcp_vel = std::move(arg);
    return Init_RobotStates_cam_pose(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_tcp_pose_des
{
public:
  explicit Init_RobotStates_tcp_pose_des(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_tcp_vel tcp_pose_des(::flexiv_msgs::msg::RobotStates::_tcp_pose_des_type arg)
  {
    msg_.tcp_pose_des = std::move(arg);
    return Init_RobotStates_tcp_vel(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_tcp_pose
{
public:
  explicit Init_RobotStates_tcp_pose(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_tcp_pose_des tcp_pose(::flexiv_msgs::msg::RobotStates::_tcp_pose_type arg)
  {
    msg_.tcp_pose = std::move(arg);
    return Init_RobotStates_tcp_pose_des(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_tau_ext
{
public:
  explicit Init_RobotStates_tau_ext(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_tcp_pose tau_ext(::flexiv_msgs::msg::RobotStates::_tau_ext_type arg)
  {
    msg_.tau_ext = std::move(arg);
    return Init_RobotStates_tcp_pose(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_tau_dot
{
public:
  explicit Init_RobotStates_tau_dot(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_tau_ext tau_dot(::flexiv_msgs::msg::RobotStates::_tau_dot_type arg)
  {
    msg_.tau_dot = std::move(arg);
    return Init_RobotStates_tau_ext(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_tau_des
{
public:
  explicit Init_RobotStates_tau_des(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_tau_dot tau_des(::flexiv_msgs::msg::RobotStates::_tau_des_type arg)
  {
    msg_.tau_des = std::move(arg);
    return Init_RobotStates_tau_dot(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_tau
{
public:
  explicit Init_RobotStates_tau(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_tau_des tau(::flexiv_msgs::msg::RobotStates::_tau_type arg)
  {
    msg_.tau = std::move(arg);
    return Init_RobotStates_tau_des(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_dtheta
{
public:
  explicit Init_RobotStates_dtheta(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_tau dtheta(::flexiv_msgs::msg::RobotStates::_dtheta_type arg)
  {
    msg_.dtheta = std::move(arg);
    return Init_RobotStates_tau(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_dq
{
public:
  explicit Init_RobotStates_dq(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_dtheta dq(::flexiv_msgs::msg::RobotStates::_dq_type arg)
  {
    msg_.dq = std::move(arg);
    return Init_RobotStates_dtheta(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_theta
{
public:
  explicit Init_RobotStates_theta(::flexiv_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_dq theta(::flexiv_msgs::msg::RobotStates::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_RobotStates_dq(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_q
{
public:
  Init_RobotStates_q()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStates_theta q(::flexiv_msgs::msg::RobotStates::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_RobotStates_theta(msg_);
  }

private:
  ::flexiv_msgs::msg::RobotStates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flexiv_msgs::msg::RobotStates>()
{
  return flexiv_msgs::msg::builder::Init_RobotStates_q();
}

}  // namespace flexiv_msgs

#endif  // FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__BUILDER_HPP_
