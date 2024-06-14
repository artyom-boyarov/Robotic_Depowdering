// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from flexiv_msgs:msg/Mode.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__MODE__STRUCT_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__flexiv_msgs__msg__Mode __attribute__((deprecated))
#else
# define DEPRECATED__flexiv_msgs__msg__Mode __declspec(deprecated)
#endif

namespace flexiv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Mode_
{
  using Type = Mode_<ContainerAllocator>;

  explicit Mode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  explicit Mode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  // field types and members
  using _mode_type =
    int8_t;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__mode(
    const int8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t MODE_UNKNOWN =
    -1;
  static constexpr int8_t MODE_IDLE =
    0;
  static constexpr int8_t MODE_RT_JOINT_TORQUE =
    1;
  static constexpr int8_t MODE_RT_JOINT_POSITION =
    2;
  static constexpr int8_t MODE_NRT_JOINT_POSITION =
    3;
  static constexpr int8_t MODE_NRT_PLAN_EXECUTION =
    4;
  static constexpr int8_t MODE_NRT_PRIMITIVE_EXECUTION =
    5;
  static constexpr int8_t MODE_RT_CARTESIAN_MOTION_FORCE_BASE =
    6;
  static constexpr int8_t MODE_RT_CARTESIAN_MOTION_FORCE_TCP =
    7;
  static constexpr int8_t MODE_NRT_CARTESIAN_MOTION_FORCE_BASE =
    8;
  static constexpr int8_t MODE_NRT_CARTESIAN_MOTION_FORCE_TCP =
    9;

  // pointer types
  using RawPtr =
    flexiv_msgs::msg::Mode_<ContainerAllocator> *;
  using ConstRawPtr =
    const flexiv_msgs::msg::Mode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<flexiv_msgs::msg::Mode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<flexiv_msgs::msg::Mode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      flexiv_msgs::msg::Mode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<flexiv_msgs::msg::Mode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      flexiv_msgs::msg::Mode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<flexiv_msgs::msg::Mode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<flexiv_msgs::msg::Mode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<flexiv_msgs::msg::Mode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__flexiv_msgs__msg__Mode
    std::shared_ptr<flexiv_msgs::msg::Mode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__flexiv_msgs__msg__Mode
    std::shared_ptr<flexiv_msgs::msg::Mode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mode_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mode_

// alias to use template instance with default allocator
using Mode =
  flexiv_msgs::msg::Mode_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_RT_JOINT_TORQUE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_RT_JOINT_POSITION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_NRT_JOINT_POSITION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_NRT_PLAN_EXECUTION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_NRT_PRIMITIVE_EXECUTION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_RT_CARTESIAN_MOTION_FORCE_BASE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_RT_CARTESIAN_MOTION_FORCE_TCP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_NRT_CARTESIAN_MOTION_FORCE_BASE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t Mode_<ContainerAllocator>::MODE_NRT_CARTESIAN_MOTION_FORCE_TCP;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace flexiv_msgs

#endif  // FLEXIV_MSGS__MSG__DETAIL__MODE__STRUCT_HPP_
