// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from flexiv_msgs:msg/JointPosVel.idl
// generated code does not contain a copyright notice
#include "flexiv_msgs/msg/detail/joint_pos_vel__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
flexiv_msgs__msg__JointPosVel__init(flexiv_msgs__msg__JointPosVel * msg)
{
  if (!msg) {
    return false;
  }
  // positions
  // velocities
  return true;
}

void
flexiv_msgs__msg__JointPosVel__fini(flexiv_msgs__msg__JointPosVel * msg)
{
  if (!msg) {
    return;
  }
  // positions
  // velocities
}

bool
flexiv_msgs__msg__JointPosVel__are_equal(const flexiv_msgs__msg__JointPosVel * lhs, const flexiv_msgs__msg__JointPosVel * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // positions
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->positions[i] != rhs->positions[i]) {
      return false;
    }
  }
  // velocities
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->velocities[i] != rhs->velocities[i]) {
      return false;
    }
  }
  return true;
}

bool
flexiv_msgs__msg__JointPosVel__copy(
  const flexiv_msgs__msg__JointPosVel * input,
  flexiv_msgs__msg__JointPosVel * output)
{
  if (!input || !output) {
    return false;
  }
  // positions
  for (size_t i = 0; i < 7; ++i) {
    output->positions[i] = input->positions[i];
  }
  // velocities
  for (size_t i = 0; i < 7; ++i) {
    output->velocities[i] = input->velocities[i];
  }
  return true;
}

flexiv_msgs__msg__JointPosVel *
flexiv_msgs__msg__JointPosVel__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flexiv_msgs__msg__JointPosVel * msg = (flexiv_msgs__msg__JointPosVel *)allocator.allocate(sizeof(flexiv_msgs__msg__JointPosVel), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(flexiv_msgs__msg__JointPosVel));
  bool success = flexiv_msgs__msg__JointPosVel__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
flexiv_msgs__msg__JointPosVel__destroy(flexiv_msgs__msg__JointPosVel * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    flexiv_msgs__msg__JointPosVel__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
flexiv_msgs__msg__JointPosVel__Sequence__init(flexiv_msgs__msg__JointPosVel__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flexiv_msgs__msg__JointPosVel * data = NULL;

  if (size) {
    data = (flexiv_msgs__msg__JointPosVel *)allocator.zero_allocate(size, sizeof(flexiv_msgs__msg__JointPosVel), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = flexiv_msgs__msg__JointPosVel__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        flexiv_msgs__msg__JointPosVel__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
flexiv_msgs__msg__JointPosVel__Sequence__fini(flexiv_msgs__msg__JointPosVel__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      flexiv_msgs__msg__JointPosVel__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

flexiv_msgs__msg__JointPosVel__Sequence *
flexiv_msgs__msg__JointPosVel__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flexiv_msgs__msg__JointPosVel__Sequence * array = (flexiv_msgs__msg__JointPosVel__Sequence *)allocator.allocate(sizeof(flexiv_msgs__msg__JointPosVel__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = flexiv_msgs__msg__JointPosVel__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
flexiv_msgs__msg__JointPosVel__Sequence__destroy(flexiv_msgs__msg__JointPosVel__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    flexiv_msgs__msg__JointPosVel__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
flexiv_msgs__msg__JointPosVel__Sequence__are_equal(const flexiv_msgs__msg__JointPosVel__Sequence * lhs, const flexiv_msgs__msg__JointPosVel__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!flexiv_msgs__msg__JointPosVel__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
flexiv_msgs__msg__JointPosVel__Sequence__copy(
  const flexiv_msgs__msg__JointPosVel__Sequence * input,
  flexiv_msgs__msg__JointPosVel__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(flexiv_msgs__msg__JointPosVel);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    flexiv_msgs__msg__JointPosVel * data =
      (flexiv_msgs__msg__JointPosVel *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!flexiv_msgs__msg__JointPosVel__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          flexiv_msgs__msg__JointPosVel__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!flexiv_msgs__msg__JointPosVel__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
