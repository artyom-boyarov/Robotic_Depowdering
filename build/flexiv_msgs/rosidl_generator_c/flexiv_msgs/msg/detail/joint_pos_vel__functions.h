// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from flexiv_msgs:msg/JointPosVel.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__FUNCTIONS_H_
#define FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "flexiv_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "flexiv_msgs/msg/detail/joint_pos_vel__struct.h"

/// Initialize msg/JointPosVel message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * flexiv_msgs__msg__JointPosVel
 * )) before or use
 * flexiv_msgs__msg__JointPosVel__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
bool
flexiv_msgs__msg__JointPosVel__init(flexiv_msgs__msg__JointPosVel * msg);

/// Finalize msg/JointPosVel message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
void
flexiv_msgs__msg__JointPosVel__fini(flexiv_msgs__msg__JointPosVel * msg);

/// Create msg/JointPosVel message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * flexiv_msgs__msg__JointPosVel__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
flexiv_msgs__msg__JointPosVel *
flexiv_msgs__msg__JointPosVel__create();

/// Destroy msg/JointPosVel message.
/**
 * It calls
 * flexiv_msgs__msg__JointPosVel__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
void
flexiv_msgs__msg__JointPosVel__destroy(flexiv_msgs__msg__JointPosVel * msg);

/// Check for msg/JointPosVel message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
bool
flexiv_msgs__msg__JointPosVel__are_equal(const flexiv_msgs__msg__JointPosVel * lhs, const flexiv_msgs__msg__JointPosVel * rhs);

/// Copy a msg/JointPosVel message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
bool
flexiv_msgs__msg__JointPosVel__copy(
  const flexiv_msgs__msg__JointPosVel * input,
  flexiv_msgs__msg__JointPosVel * output);

/// Initialize array of msg/JointPosVel messages.
/**
 * It allocates the memory for the number of elements and calls
 * flexiv_msgs__msg__JointPosVel__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
bool
flexiv_msgs__msg__JointPosVel__Sequence__init(flexiv_msgs__msg__JointPosVel__Sequence * array, size_t size);

/// Finalize array of msg/JointPosVel messages.
/**
 * It calls
 * flexiv_msgs__msg__JointPosVel__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
void
flexiv_msgs__msg__JointPosVel__Sequence__fini(flexiv_msgs__msg__JointPosVel__Sequence * array);

/// Create array of msg/JointPosVel messages.
/**
 * It allocates the memory for the array and calls
 * flexiv_msgs__msg__JointPosVel__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
flexiv_msgs__msg__JointPosVel__Sequence *
flexiv_msgs__msg__JointPosVel__Sequence__create(size_t size);

/// Destroy array of msg/JointPosVel messages.
/**
 * It calls
 * flexiv_msgs__msg__JointPosVel__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
void
flexiv_msgs__msg__JointPosVel__Sequence__destroy(flexiv_msgs__msg__JointPosVel__Sequence * array);

/// Check for msg/JointPosVel message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
bool
flexiv_msgs__msg__JointPosVel__Sequence__are_equal(const flexiv_msgs__msg__JointPosVel__Sequence * lhs, const flexiv_msgs__msg__JointPosVel__Sequence * rhs);

/// Copy an array of msg/JointPosVel messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_flexiv_msgs
bool
flexiv_msgs__msg__JointPosVel__Sequence__copy(
  const flexiv_msgs__msg__JointPosVel__Sequence * input,
  flexiv_msgs__msg__JointPosVel__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FLEXIV_MSGS__MSG__DETAIL__JOINT_POS_VEL__FUNCTIONS_H_
