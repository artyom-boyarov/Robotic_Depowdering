// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flexiv_msgs:msg/Digital.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__DIGITAL__STRUCT_H_
#define FLEXIV_MSGS__MSG__DETAIL__DIGITAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Digital in the package flexiv_msgs.
typedef struct flexiv_msgs__msg__Digital
{
  uint8_t pin;
  bool state;
} flexiv_msgs__msg__Digital;

// Struct for a sequence of flexiv_msgs__msg__Digital.
typedef struct flexiv_msgs__msg__Digital__Sequence
{
  flexiv_msgs__msg__Digital * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flexiv_msgs__msg__Digital__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLEXIV_MSGS__MSG__DETAIL__DIGITAL__STRUCT_H_
