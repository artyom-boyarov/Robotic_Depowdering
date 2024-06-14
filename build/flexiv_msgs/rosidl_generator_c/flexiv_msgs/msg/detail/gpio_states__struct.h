// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flexiv_msgs:msg/GPIOStates.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__GPIO_STATES__STRUCT_H_
#define FLEXIV_MSGS__MSG__DETAIL__GPIO_STATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'states'
#include "flexiv_msgs/msg/detail/digital__struct.h"

/// Struct defined in msg/GPIOStates in the package flexiv_msgs.
typedef struct flexiv_msgs__msg__GPIOStates
{
  flexiv_msgs__msg__Digital__Sequence states;
} flexiv_msgs__msg__GPIOStates;

// Struct for a sequence of flexiv_msgs__msg__GPIOStates.
typedef struct flexiv_msgs__msg__GPIOStates__Sequence
{
  flexiv_msgs__msg__GPIOStates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flexiv_msgs__msg__GPIOStates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLEXIV_MSGS__MSG__DETAIL__GPIO_STATES__STRUCT_H_
