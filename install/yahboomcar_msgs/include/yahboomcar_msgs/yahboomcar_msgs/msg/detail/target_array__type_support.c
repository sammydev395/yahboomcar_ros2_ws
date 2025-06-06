// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yahboomcar_msgs:msg/TargetArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yahboomcar_msgs/msg/detail/target_array__rosidl_typesupport_introspection_c.h"
#include "yahboomcar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yahboomcar_msgs/msg/detail/target_array__functions.h"
#include "yahboomcar_msgs/msg/detail/target_array__struct.h"


// Include directives for member types
// Member `targets`
#include "yahboomcar_msgs/msg/target.h"
// Member `targets`
#include "yahboomcar_msgs/msg/detail/target__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yahboomcar_msgs__msg__TargetArray__init(message_memory);
}

void yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_fini_function(void * message_memory)
{
  yahboomcar_msgs__msg__TargetArray__fini(message_memory);
}

size_t yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__size_function__TargetArray__targets(
  const void * untyped_member)
{
  const yahboomcar_msgs__msg__Target__Sequence * member =
    (const yahboomcar_msgs__msg__Target__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__get_const_function__TargetArray__targets(
  const void * untyped_member, size_t index)
{
  const yahboomcar_msgs__msg__Target__Sequence * member =
    (const yahboomcar_msgs__msg__Target__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__get_function__TargetArray__targets(
  void * untyped_member, size_t index)
{
  yahboomcar_msgs__msg__Target__Sequence * member =
    (yahboomcar_msgs__msg__Target__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__fetch_function__TargetArray__targets(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const yahboomcar_msgs__msg__Target * item =
    ((const yahboomcar_msgs__msg__Target *)
    yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__get_const_function__TargetArray__targets(untyped_member, index));
  yahboomcar_msgs__msg__Target * value =
    (yahboomcar_msgs__msg__Target *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__assign_function__TargetArray__targets(
  void * untyped_member, size_t index, const void * untyped_value)
{
  yahboomcar_msgs__msg__Target * item =
    ((yahboomcar_msgs__msg__Target *)
    yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__get_function__TargetArray__targets(untyped_member, index));
  const yahboomcar_msgs__msg__Target * value =
    (const yahboomcar_msgs__msg__Target *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__resize_function__TargetArray__targets(
  void * untyped_member, size_t size)
{
  yahboomcar_msgs__msg__Target__Sequence * member =
    (yahboomcar_msgs__msg__Target__Sequence *)(untyped_member);
  yahboomcar_msgs__msg__Target__Sequence__fini(member);
  return yahboomcar_msgs__msg__Target__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_member_array[1] = {
  {
    "targets",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__TargetArray, targets),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__size_function__TargetArray__targets,  // size() function pointer
    yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__get_const_function__TargetArray__targets,  // get_const(index) function pointer
    yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__get_function__TargetArray__targets,  // get(index) function pointer
    yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__fetch_function__TargetArray__targets,  // fetch(index, &value) function pointer
    yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__assign_function__TargetArray__targets,  // assign(index, value) function pointer
    yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__resize_function__TargetArray__targets  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_members = {
  "yahboomcar_msgs__msg",  // message namespace
  "TargetArray",  // message name
  1,  // number of fields
  sizeof(yahboomcar_msgs__msg__TargetArray),
  yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_member_array,  // message members
  yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_init_function,  // function to initialize message memory (memory has to be allocated)
  yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_type_support_handle = {
  0,
  &yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yahboomcar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, msg, TargetArray)() {
  yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, msg, Target)();
  if (!yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_type_support_handle.typesupport_identifier) {
    yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yahboomcar_msgs__msg__TargetArray__rosidl_typesupport_introspection_c__TargetArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
