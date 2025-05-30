// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yahboomcar_msgs:srv/RobotArmArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yahboomcar_msgs/srv/detail/robot_arm_array__rosidl_typesupport_introspection_c.h"
#include "yahboomcar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yahboomcar_msgs/srv/detail/robot_arm_array__functions.h"
#include "yahboomcar_msgs/srv/detail/robot_arm_array__struct.h"


// Include directives for member types
// Member `apply`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yahboomcar_msgs__srv__RobotArmArray_Request__init(message_memory);
}

void yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_fini_function(void * message_memory)
{
  yahboomcar_msgs__srv__RobotArmArray_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_message_member_array[1] = {
  {
    "apply",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__srv__RobotArmArray_Request, apply),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_message_members = {
  "yahboomcar_msgs__srv",  // message namespace
  "RobotArmArray_Request",  // message name
  1,  // number of fields
  sizeof(yahboomcar_msgs__srv__RobotArmArray_Request),
  yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_message_member_array,  // message members
  yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_message_type_support_handle = {
  0,
  &yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yahboomcar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, srv, RobotArmArray_Request)() {
  if (!yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_message_type_support_handle.typesupport_identifier) {
    yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yahboomcar_msgs__srv__RobotArmArray_Request__rosidl_typesupport_introspection_c__RobotArmArray_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "yahboomcar_msgs/srv/detail/robot_arm_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "yahboomcar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "yahboomcar_msgs/srv/detail/robot_arm_array__functions.h"
// already included above
// #include "yahboomcar_msgs/srv/detail/robot_arm_array__struct.h"


// Include directives for member types
// Member `joint_1`
// Member `joint_2`
// Member `joint_3`
// Member `joint_4`
// Member `joint_5`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yahboomcar_msgs__srv__RobotArmArray_Response__init(message_memory);
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_fini_function(void * message_memory)
{
  yahboomcar_msgs__srv__RobotArmArray_Response__fini(message_memory);
}

size_t yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_1(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_1(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_1(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_1(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_1(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_1(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_1(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_1(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_2(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_2(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_2(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_2(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_2(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_2(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_2(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_2(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_3(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_3(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_3(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_3(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_3(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_3(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_3(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_3(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_4(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_4(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_4(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_4(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_4(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_4(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_4(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_4(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_5(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_5(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_5(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_5(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_5(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_5(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_5(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_5(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_message_member_array[6] = {
  {
    "joint_1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__srv__RobotArmArray_Response, joint_1),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_1,  // size() function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_1,  // get_const(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_1,  // get(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_1,  // fetch(index, &value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_1,  // assign(index, value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_1  // resize(index) function pointer
  },
  {
    "joint_2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__srv__RobotArmArray_Response, joint_2),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_2,  // size() function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_2,  // get_const(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_2,  // get(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_2,  // fetch(index, &value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_2,  // assign(index, value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_2  // resize(index) function pointer
  },
  {
    "joint_3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__srv__RobotArmArray_Response, joint_3),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_3,  // size() function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_3,  // get_const(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_3,  // get(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_3,  // fetch(index, &value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_3,  // assign(index, value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_3  // resize(index) function pointer
  },
  {
    "joint_4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__srv__RobotArmArray_Response, joint_4),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_4,  // size() function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_4,  // get_const(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_4,  // get(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_4,  // fetch(index, &value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_4,  // assign(index, value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_4  // resize(index) function pointer
  },
  {
    "joint_5",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__srv__RobotArmArray_Response, joint_5),  // bytes offset in struct
    NULL,  // default value
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__size_function__RobotArmArray_Response__joint_5,  // size() function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_const_function__RobotArmArray_Response__joint_5,  // get_const(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__get_function__RobotArmArray_Response__joint_5,  // get(index) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__fetch_function__RobotArmArray_Response__joint_5,  // fetch(index, &value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__assign_function__RobotArmArray_Response__joint_5,  // assign(index, value) function pointer
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__resize_function__RobotArmArray_Response__joint_5  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs__srv__RobotArmArray_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_message_members = {
  "yahboomcar_msgs__srv",  // message namespace
  "RobotArmArray_Response",  // message name
  6,  // number of fields
  sizeof(yahboomcar_msgs__srv__RobotArmArray_Response),
  yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_message_member_array,  // message members
  yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_message_type_support_handle = {
  0,
  &yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yahboomcar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, srv, RobotArmArray_Response)() {
  if (!yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_message_type_support_handle.typesupport_identifier) {
    yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yahboomcar_msgs__srv__RobotArmArray_Response__rosidl_typesupport_introspection_c__RobotArmArray_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "yahboomcar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "yahboomcar_msgs/srv/detail/robot_arm_array__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers yahboomcar_msgs__srv__detail__robot_arm_array__rosidl_typesupport_introspection_c__RobotArmArray_service_members = {
  "yahboomcar_msgs__srv",  // service namespace
  "RobotArmArray",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // yahboomcar_msgs__srv__detail__robot_arm_array__rosidl_typesupport_introspection_c__RobotArmArray_Request_message_type_support_handle,
  NULL  // response message
  // yahboomcar_msgs__srv__detail__robot_arm_array__rosidl_typesupport_introspection_c__RobotArmArray_Response_message_type_support_handle
};

static rosidl_service_type_support_t yahboomcar_msgs__srv__detail__robot_arm_array__rosidl_typesupport_introspection_c__RobotArmArray_service_type_support_handle = {
  0,
  &yahboomcar_msgs__srv__detail__robot_arm_array__rosidl_typesupport_introspection_c__RobotArmArray_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, srv, RobotArmArray_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, srv, RobotArmArray_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yahboomcar_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, srv, RobotArmArray)() {
  if (!yahboomcar_msgs__srv__detail__robot_arm_array__rosidl_typesupport_introspection_c__RobotArmArray_service_type_support_handle.typesupport_identifier) {
    yahboomcar_msgs__srv__detail__robot_arm_array__rosidl_typesupport_introspection_c__RobotArmArray_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)yahboomcar_msgs__srv__detail__robot_arm_array__rosidl_typesupport_introspection_c__RobotArmArray_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, srv, RobotArmArray_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yahboomcar_msgs, srv, RobotArmArray_Response)()->data;
  }

  return &yahboomcar_msgs__srv__detail__robot_arm_array__rosidl_typesupport_introspection_c__RobotArmArray_service_type_support_handle;
}
