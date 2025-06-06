// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yahboomcar_msgs:msg/ImageMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yahboomcar_msgs/msg/detail/image_msg__rosidl_typesupport_introspection_c.h"
#include "yahboomcar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yahboomcar_msgs/msg/detail/image_msg__functions.h"
#include "yahboomcar_msgs/msg/detail/image_msg__struct.h"


// Include directives for member types
// Member `image_path`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yahboomcar_msgs__msg__ImageMsg__init(message_memory);
}

void yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_fini_function(void * message_memory)
{
  yahboomcar_msgs__msg__ImageMsg__fini(message_memory);
}

size_t yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__size_function__ImageMsg__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_const_function__ImageMsg__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_function__ImageMsg__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__fetch_function__ImageMsg__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_const_function__ImageMsg__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__assign_function__ImageMsg__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_function__ImageMsg__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__resize_function__ImageMsg__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_member_array[7] = {
  {
    "image_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__ImageMsg, image_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__ImageMsg, image_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image_score",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__ImageMsg, image_score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__ImageMsg, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__ImageMsg, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "channels",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__ImageMsg, channels),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__msg__ImageMsg, data),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__size_function__ImageMsg__data,  // size() function pointer
    yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_const_function__ImageMsg__data,  // get_const(index) function pointer
    yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__get_function__ImageMsg__data,  // get(index) function pointer
    yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__fetch_function__ImageMsg__data,  // fetch(index, &value) function pointer
    yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__assign_function__ImageMsg__data,  // assign(index, value) function pointer
    yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__resize_function__ImageMsg__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_members = {
  "yahboomcar_msgs__msg",  // message namespace
  "ImageMsg",  // message name
  7,  // number of fields
  sizeof(yahboomcar_msgs__msg__ImageMsg),
  yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_member_array,  // message members
  yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_type_support_handle = {
  0,
  &yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yahboomcar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, msg, ImageMsg)() {
  if (!yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_type_support_handle.typesupport_identifier) {
    yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yahboomcar_msgs__msg__ImageMsg__rosidl_typesupport_introspection_c__ImageMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
