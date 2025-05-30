// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yahboomcar_msgs:msg/PointArray.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__MSG__DETAIL__POINT_ARRAY__STRUCT_H_
#define YAHBOOMCAR_MSGS__MSG__DETAIL__POINT_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x'
// Member 'y'
// Member 'z'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PointArray in the package yahboomcar_msgs.
/**
  * An array of points
 */
typedef struct yahboomcar_msgs__msg__PointArray
{
  rosidl_runtime_c__float__Sequence x;
  rosidl_runtime_c__float__Sequence y;
  rosidl_runtime_c__float__Sequence z;
} yahboomcar_msgs__msg__PointArray;

// Struct for a sequence of yahboomcar_msgs__msg__PointArray.
typedef struct yahboomcar_msgs__msg__PointArray__Sequence
{
  yahboomcar_msgs__msg__PointArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yahboomcar_msgs__msg__PointArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YAHBOOMCAR_MSGS__MSG__DETAIL__POINT_ARRAY__STRUCT_H_
