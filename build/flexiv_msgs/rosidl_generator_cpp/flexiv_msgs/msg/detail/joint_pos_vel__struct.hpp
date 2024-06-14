// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from flexiv_msgs:msg/JointPosVel.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__STRUCT_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__flexiv_msgs__msg__JointPosVel __attribute__((deprecated))
#else
# define DEPRECATED__flexiv_msgs__msg__JointPosVel __declspec(deprecated)
#endif

namespace flexiv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointPosVel_
{
  using Type = JointPosVel_<ContainerAllocator>;

  explicit JointPosVel_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->positions.begin(), this->positions.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->velocities.begin(), this->velocities.end(), 0.0);
    }
  }

  explicit JointPosVel_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : positions(_alloc),
    velocities(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->positions.begin(), this->positions.end(), 0.0);
      std::fill<typename std::array<double, 7>::iterator, double>(this->velocities.begin(), this->velocities.end(), 0.0);
    }
  }

  // field types and members
  using _positions_type =
    std::array<double, 7>;
  _positions_type positions;
  using _velocities_type =
    std::array<double, 7>;
  _velocities_type velocities;

  // setters for named parameter idiom
  Type & set__positions(
    const std::array<double, 7> & _arg)
  {
    this->positions = _arg;
    return *this;
  }
  Type & set__velocities(
    const std::array<double, 7> & _arg)
  {
    this->velocities = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    flexiv_msgs::msg::JointPosVel_<ContainerAllocator> *;
  using ConstRawPtr =
    const flexiv_msgs::msg::JointPosVel_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<flexiv_msgs::msg::JointPosVel_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<flexiv_msgs::msg::JointPosVel_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      flexiv_msgs::msg::JointPosVel_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<flexiv_msgs::msg::JointPosVel_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      flexiv_msgs::msg::JointPosVel_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<flexiv_msgs::msg::JointPosVel_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<flexiv_msgs::msg::JointPosVel_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<flexiv_msgs::msg::JointPosVel_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__flexiv_msgs__msg__JointPosVel
    std::shared_ptr<flexiv_msgs::msg::JointPosVel_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__flexiv_msgs__msg__JointPosVel
    std::shared_ptr<flexiv_msgs::msg::JointPosVel_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointPosVel_ & other) const
  {
    if (this->positions != other.positions) {
      return false;
    }
    if (this->velocities != other.velocities) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointPosVel_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointPosVel_

// alias to use template instance with default allocator
using JointPosVel =
  flexiv_msgs::msg::JointPosVel_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace flexiv_msgs

#endif  // FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__STRUCT_HPP_
