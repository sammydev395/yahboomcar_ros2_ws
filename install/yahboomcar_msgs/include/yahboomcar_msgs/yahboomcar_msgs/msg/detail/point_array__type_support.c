// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yahboomcar_msgs:msg/PointArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yahboomcar_msgs/msg/detail/point_array__rosidl_typesupport_introspection_c.h"
#include "yahboomcar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yahboomcar_msgs/msg/detail/point_array__functions.h"
#include "yahboomcar_msgs/msg/detail/point_array__struct.h"


// Include directives for member types
// Member `x`
// Member `y`
// Member `z`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yahboomcar_msgs__msg__PointArray__init(message_memory);
}

void yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_fini_function(void * message_memory)
{
  yahboomcar_msgs__msg__PointArray__fini(message_memory);
}

size_t yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__size_function__PointArray__x(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_const_function__PointArray__x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_function__PointArray__x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__fetch_function__PointArray__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_const_function__PointArray__x(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__assign_function__PointArray__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_function__PointArray__x(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__resize_function__PointArray__x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__size_function__PointArray__y(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_const_function__PointArray__y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_function__PointArray__y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__fetch_function__PointArray__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_const_function__PointArray__y(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__assign_function__PointArray__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_function__PointArray__y(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__resize_function__PointArray__y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__size_function__PointArray__z(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_const_function__PointArray__z(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_function__PointArray__z(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__fetch_function__PointArray__z(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_const_function__PointArray__z(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__assign_function__PointArray__z(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_function__PointArray__z(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__resize_function__PointArray__z(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__PointArray, x),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__size_function__PointArray__x,  // size() function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_const_function__PointArray__x,  // get_const(index) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_function__PointArray__x,  // get(index) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__fetch_function__PointArray__x,  // fetch(index, &value) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__assign_function__PointArray__x,  // assign(index, value) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__resize_function__PointArray__x  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__PointArray, y),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__size_function__PointArray__y,  // size() function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_const_function__PointArray__y,  // get_const(index) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_function__PointArray__y,  // get(index) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__fetch_function__PointArray__y,  // fetch(index, &value) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__assign_function__PointArray__y,  // assign(index, value) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__resize_function__PointArray__y  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__PointArray, z),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__size_function__PointArray__z,  // size() function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_const_function__PointArray__z,  // get_const(index) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__get_function__PointArray__z,  // get(index) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__fetch_function__PointArray__z,  // fetch(index, &value) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__assign_function__PointArray__z,  // assign(index, value) function pointer
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__resize_function__PointArray__z  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_message_members = {
  "yahboomcar_msgs__msg",  // message namespace
  "PointArray",  // message name
  3,  // number of fields
  sizeof(yahboomcar_msgs__msg__PointArray),
  yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_message_member_array,  // message members
  yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_init_function,  // function to initialize message memory (memory has to be allocated)
  yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_message_type_support_handle = {
  0,
  &yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yahboomcar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, msg, PointArray)() {
  if (!yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_message_type_support_handle.typesupport_identifier) {
    yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yahboomcar_msgs__msg__PointArray__rosidl_typesupport_introspection_c__PointArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
