// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from flexiv_msgs:msg/RobotStates.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__STRUCT_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'tcp_pose'
// Member 'tcp_pose_des'
// Member 'cam_pose'
// Member 'flange_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'tcp_vel'
#include "geometry_msgs/msg/detail/accel__struct.hpp"
// Member 'ft_sensor_raw'
// Member 'ext_wrench_tcp_frame'
// Member 'ext_wrench_base_frame'
#include "geometry_msgs/msg/detail/wrench__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__flexiv_msgs__msg__RobotStates __attribute__((deprecated))
#else
# define DEPRECATED__flexiv_msgs__msg__RobotStates __declspec(deprecated)
#endif

namespace flexiv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStates_
{
  using Type = RobotStates_<ContainerAllocator>;

  explicit RobotStates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tcp_pose(_init),
    tcp_pose_des(_init),
    tcp_vel(_init),
    cam_pose(_init),
    flange_pose(_init),
    ft_sensor_raw(_init),
    ext_wrench_tcp_frame(_init),
    ext_wrench_base_frame(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->q.begin(), this->q.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->theta.begin(), this->theta.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->dq.begin(), this->dq.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->dtheta.begin(), this->dtheta.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->tau.begin(), this->tau.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->tau_des.begin(), this->tau_des.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->tau_dot.begin(), this->tau_dot.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->tau_ext.begin(), this->tau_ext.end(), 0.0);
    }
  }

  explicit RobotStates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : q(_alloc),
    theta(_alloc),
    dq(_alloc),
    dtheta(_alloc),
    tau(_alloc),
    tau_des(_alloc),
    tau_dot(_alloc),
    tau_ext(_alloc),
    tcp_pose(_alloc, _init),
    tcp_pose_des(_alloc, _init),
    tcp_vel(_alloc, _init),
    cam_pose(_alloc, _init),
    flange_pose(_alloc, _init),
    ft_sensor_raw(_alloc, _init),
    ext_wrench_tcp_frame(_alloc, _init),
    ext_wrench_base_frame(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->q.begin(), this->q.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->theta.begin(), this->theta.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->dq.begin(), this->dq.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->dtheta.begin(), this->dtheta.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->tau.begin(), this->tau.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->tau_des.begin(), this->tau_des.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->tau_dot.begin(), this->tau_dot.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->tau_ext.begin(), this->tau_ext.end(), 0.0);
    }
  }

  // field types and members
  using _q_type =
    std::array<double, 7>;
  _q_type q;
  using _theta_type =
    std::array<double, 7>;
  _theta_type theta;
  using _dq_type =
    std::array<double, 7>;
  _dq_type dq;
  using _dtheta_type =
    std::array<double, 7>;
  _dtheta_type dtheta;
  using _tau_type =
    std::array<double, 7>;
  _tau_type tau;
  using _tau_des_type =
    std::array<double, 7>;
  _tau_des_type tau_des;
  using _tau_dot_type =
    std::array<double, 7>;
  _tau_dot_type tau_dot;
  using _tau_ext_type =
    std::array<double, 7>;
  _tau_ext_type tau_ext;
  using _tcp_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _tcp_pose_type tcp_pose;
  using _tcp_pose_des_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _tcp_pose_des_type tcp_pose_des;
  using _tcp_vel_type =
    geometry_msgs::msg::Accel_<ContainerAllocator>;
  _tcp_vel_type tcp_vel;
  using _cam_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _cam_pose_type cam_pose;
  using _flange_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _flange_pose_type flange_pose;
  using _ft_sensor_raw_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _ft_sensor_raw_type ft_sensor_raw;
  using _ext_wrench_tcp_frame_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _ext_wrench_tcp_frame_type ext_wrench_tcp_frame;
  using _ext_wrench_base_frame_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _ext_wrench_base_frame_type ext_wrench_base_frame;

  // setters for named parameter idiom
  Type & set__q(
    const std::array<double, 7> & _arg)
  {
    this->q = _arg;
    return *this;
  }
  Type & set__theta(
    const std::array<double, 7> & _arg)
  {
    this->theta = _arg;
    return *this;
  }
  Type & set__dq(
    const std::array<double, 7> & _arg)
  {
    this->dq = _arg;
    return *this;
  }
  Type & set__dtheta(
    const std::array<double, 7> & _arg)
  {
    this->dtheta = _arg;
    return *this;
  }
  Type & set__tau(
    const std::array<double, 7> & _arg)
  {
    this->tau = _arg;
    return *this;
  }
  Type & set__tau_des(
    const std::array<double, 7> & _arg)
  {
    this->tau_des = _arg;
    return *this;
  }
  Type & set__tau_dot(
    const std::array<double, 7> & _arg)
  {
    this->tau_dot = _arg;
    return *this;
  }
  Type & set__tau_ext(
    const std::array<double, 7> & _arg)
  {
    this->tau_ext = _arg;
    return *this;
  }
  Type & set__tcp_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->tcp_pose = _arg;
    return *this;
  }
  Type & set__tcp_pose_des(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->tcp_pose_des = _arg;
    return *this;
  }
  Type & set__tcp_vel(
    const geometry_msgs::msg::Accel_<ContainerAllocator> & _arg)
  {
    this->tcp_vel = _arg;
    return *this;
  }
  Type & set__cam_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->cam_pose = _arg;
    return *this;
  }
  Type & set__flange_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->flange_pose = _arg;
    return *this;
  }
  Type & set__ft_sensor_raw(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->ft_sensor_raw = _arg;
    return *this;
  }
  Type & set__ext_wrench_tcp_frame(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->ext_wrench_tcp_frame = _arg;
    return *this;
  }
  Type & set__ext_wrench_base_frame(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->ext_wrench_base_frame = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    flexiv_msgs::msg::RobotStates_<ContainerAllocator> *;
  using ConstRawPtr =
    const flexiv_msgs::msg::RobotStates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<flexiv_msgs::msg::RobotStates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<flexiv_msgs::msg::RobotStates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      flexiv_msgs::msg::RobotStates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<flexiv_msgs::msg::RobotStates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      flexiv_msgs::msg::RobotStates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<flexiv_msgs::msg::RobotStates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<flexiv_msgs::msg::RobotStates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<flexiv_msgs::msg::RobotStates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__flexiv_msgs__msg__RobotStates
    std::shared_ptr<flexiv_msgs::msg::RobotStates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__flexiv_msgs__msg__RobotStates
    std::shared_ptr<flexiv_msgs::msg::RobotStates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStates_ & other) const
  {
    if (this->q != other.q) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    if (this->dq != other.dq) {
      return false;
    }
    if (this->dtheta != other.dtheta) {
      return false;
    }
    if (this->tau != other.tau) {
      return false;
    }
    if (this->tau_des != other.tau_des) {
      return false;
    }
    if (this->tau_dot != other.tau_dot) {
      return false;
    }
    if (this->tau_ext != other.tau_ext) {
      return false;
    }
    if (this->tcp_pose != other.tcp_pose) {
      return false;
    }
    if (this->tcp_pose_des != other.tcp_pose_des) {
      return false;
    }
    if (this->tcp_vel != other.tcp_vel) {
      return false;
    }
    if (this->cam_pose != other.cam_pose) {
      return false;
    }
    if (this->flange_pose != other.flange_pose) {
      return false;
    }
    if (this->ft_sensor_raw != other.ft_sensor_raw) {
      return false;
    }
    if (this->ext_wrench_tcp_frame != other.ext_wrench_tcp_frame) {
      return false;
    }
    if (this->ext_wrench_base_frame != other.ext_wrench_base_frame) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStates_

// alias to use template instance with default allocator
using RobotStates =
  flexiv_msgs::msg::RobotStates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace flexiv_msgs

#endif  // FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__STRUCT_HPP_
