// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yahboomcar_msgs:srv/Kinematics.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__STRUCT_H_
#define YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'kin_name'
#include "rosidl_runtime_c/string.h"
// Member 'src_pos'
// Member 'src_joints'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/Kinematics in the package yahboomcar_msgs.
typedef struct yahboomcar_msgs__srv__Kinematics_Request
{
  rosidl_runtime_c__String kin_name;
  rosidl_runtime_c__double__Sequence src_pos;
  rosidl_runtime_c__double__Sequence src_joints;
} yahboomcar_msgs__srv__Kinematics_Request;

// Struct for a sequence of yahboomcar_msgs__srv__Kinematics_Request.
typedef struct yahboomcar_msgs__srv__Kinematics_Request__Sequence
{
  yahboomcar_msgs__srv__Kinematics_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yahboomcar_msgs__srv__Kinematics_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'target_joints'
// Member 'target_pos'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/Kinematics in the package yahboomcar_msgs.
typedef struct yahboomcar_msgs__srv__Kinematics_Response
{
  rosidl_runtime_c__double__Sequence target_joints;
  rosidl_runtime_c__double__Sequence target_pos;
} yahboomcar_msgs__srv__Kinematics_Response;

// Struct for a sequence of yahboomcar_msgs__srv__Kinematics_Response.
typedef struct yahboomcar_msgs__srv__Kinematics_Response__Sequence
{
  yahboomcar_msgs__srv__Kinematics_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yahboomcar_msgs__srv__Kinematics_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__STRUCT_H_
