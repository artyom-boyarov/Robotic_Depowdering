// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from flexiv_msgs:msg/GPIOStates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "flexiv_msgs/msg/detail/gpio_states__rosidl_typesupport_introspection_c.h"
#include "flexiv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "flexiv_msgs/msg/detail/gpio_states__functions.h"
#include "flexiv_msgs/msg/detail/gpio_states__struct.h"


// Include directives for member types
// Member `states`
#include "flexiv_msgs/msg/digital.h"
// Member `states`
#include "flexiv_msgs/msg/detail/digital__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  flexiv_msgs__msg__GPIOStates__init(message_memory);
}

void flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_fini_function(void * message_memory)
{
  flexiv_msgs__msg__GPIOStates__fini(message_memory);
}

size_t flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__size_function__GPIOStates__states(
  const void * untyped_member)
{
  const flexiv_msgs__msg__Digital__Sequence * member =
    (const flexiv_msgs__msg__Digital__Sequence *)(untyped_member);
  return member->size;
}

const void * flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__get_const_function__GPIOStates__states(
  const void * untyped_member, size_t index)
{
  const flexiv_msgs__msg__Digital__Sequence * member =
    (const flexiv_msgs__msg__Digital__Sequence *)(untyped_member);
  return &member->data[index];
}

void * flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__get_function__GPIOStates__states(
  void * untyped_member, size_t index)
{
  flexiv_msgs__msg__Digital__Sequence * member =
    (flexiv_msgs__msg__Digital__Sequence *)(untyped_member);
  return &member->data[index];
}

void flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__fetch_function__GPIOStates__states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const flexiv_msgs__msg__Digital * item =
    ((const flexiv_msgs__msg__Digital *)
    flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__get_const_function__GPIOStates__states(untyped_member, index));
  flexiv_msgs__msg__Digital * value =
    (flexiv_msgs__msg__Digital *)(untyped_value);
  *value = *item;
}

void flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__assign_function__GPIOStates__states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  flexiv_msgs__msg__Digital * item =
    ((flexiv_msgs__msg__Digital *)
    flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__get_function__GPIOStates__states(untyped_member, index));
  const flexiv_msgs__msg__Digital * value =
    (const flexiv_msgs__msg__Digital *)(untyped_value);
  *item = *value;
}

bool flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__resize_function__GPIOStates__states(
  void * untyped_member, size_t size)
{
  flexiv_msgs__msg__Digital__Sequence * member =
    (flexiv_msgs__msg__Digital__Sequence *)(untyped_member);
  flexiv_msgs__msg__Digital__Sequence__fini(member);
  return flexiv_msgs__msg__Digital__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_message_member_array[1] = {
  {
    "states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flexiv_msgs__msg__GPIOStates, states),  // bytes offset in struct
    NULL,  // default value
    flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__size_function__GPIOStates__states,  // size() function pointer
    flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__get_const_function__GPIOStates__states,  // get_const(index) function pointer
    flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__get_function__GPIOStates__states,  // get(index) function pointer
    flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__fetch_function__GPIOStates__states,  // fetch(index, &value) function pointer
    flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__assign_function__GPIOStates__states,  // assign(index, value) function pointer
    flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__resize_function__GPIOStates__states  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_message_members = {
  "flexiv_msgs__msg",  // message namespace
  "GPIOStates",  // message name
  1,  // number of fields
  sizeof(flexiv_msgs__msg__GPIOStates),
  flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_message_member_array,  // message members
  flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_init_function,  // function to initialize message memory (memory has to be allocated)
  flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_message_type_support_handle = {
  0,
  &flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flexiv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flexiv_msgs, msg, GPIOStates)() {
  flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flexiv_msgs, msg, Digital)();
  if (!flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_message_type_support_handle.typesupport_identifier) {
    flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &flexiv_msgs__msg__GPIOStates__rosidl_typesupport_introspection_c__GPIOStates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
