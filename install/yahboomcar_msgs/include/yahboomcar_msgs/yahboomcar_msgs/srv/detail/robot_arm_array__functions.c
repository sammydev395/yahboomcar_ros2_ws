// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yahboomcar_msgs:srv/RobotArmArray.idl
// generated code does not contain a copyright notice
#include "yahboomcar_msgs/srv/detail/robot_arm_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `apply`
#include "rosidl_runtime_c/string_functions.h"

bool
yahboomcar_msgs__srv__RobotArmArray_Request__init(yahboomcar_msgs__srv__RobotArmArray_Request * msg)
{
  if (!msg) {
    return false;
  }
  // apply
  if (!rosidl_runtime_c__String__init(&msg->apply)) {
    yahboomcar_msgs__srv__RobotArmArray_Request__fini(msg);
    return false;
  }
  return true;
}

void
yahboomcar_msgs__srv__RobotArmArray_Request__fini(yahboomcar_msgs__srv__RobotArmArray_Request * msg)
{
  if (!msg) {
    return;
  }
  // apply
  rosidl_runtime_c__String__fini(&msg->apply);
}

bool
yahboomcar_msgs__srv__RobotArmArray_Request__are_equal(const yahboomcar_msgs__srv__RobotArmArray_Request * lhs, const yahboomcar_msgs__srv__RobotArmArray_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // apply
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->apply), &(rhs->apply)))
  {
    return false;
  }
  return true;
}

bool
yahboomcar_msgs__srv__RobotArmArray_Request__copy(
  const yahboomcar_msgs__srv__RobotArmArray_Request * input,
  yahboomcar_msgs__srv__RobotArmArray_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // apply
  if (!rosidl_runtime_c__String__copy(
      &(input->apply), &(output->apply)))
  {
    return false;
  }
  return true;
}

yahboomcar_msgs__srv__RobotArmArray_Request *
yahboomcar_msgs__srv__RobotArmArray_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yahboomcar_msgs__srv__RobotArmArray_Request * msg = (yahboomcar_msgs__srv__RobotArmArray_Request *)allocator.allocate(sizeof(yahboomcar_msgs__srv__RobotArmArray_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yahboomcar_msgs__srv__RobotArmArray_Request));
  bool success = yahboomcar_msgs__srv__RobotArmArray_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yahboomcar_msgs__srv__RobotArmArray_Request__destroy(yahboomcar_msgs__srv__RobotArmArray_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yahboomcar_msgs__srv__RobotArmArray_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yahboomcar_msgs__srv__RobotArmArray_Request__Sequence__init(yahboomcar_msgs__srv__RobotArmArray_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yahboomcar_msgs__srv__RobotArmArray_Request * data = NULL;

  if (size) {
    data = (yahboomcar_msgs__srv__RobotArmArray_Request *)allocator.zero_allocate(size, sizeof(yahboomcar_msgs__srv__RobotArmArray_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yahboomcar_msgs__srv__RobotArmArray_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yahboomcar_msgs__srv__RobotArmArray_Request__fini(&data[i - 1]);
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
yahboomcar_msgs__srv__RobotArmArray_Request__Sequence__fini(yahboomcar_msgs__srv__RobotArmArray_Request__Sequence * array)
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
      yahboomcar_msgs__srv__RobotArmArray_Request__fini(&array->data[i]);
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

yahboomcar_msgs__srv__RobotArmArray_Request__Sequence *
yahboomcar_msgs__srv__RobotArmArray_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yahboomcar_msgs__srv__RobotArmArray_Request__Sequence * array = (yahboomcar_msgs__srv__RobotArmArray_Request__Sequence *)allocator.allocate(sizeof(yahboomcar_msgs__srv__RobotArmArray_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yahboomcar_msgs__srv__RobotArmArray_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yahboomcar_msgs__srv__RobotArmArray_Request__Sequence__destroy(yahboomcar_msgs__srv__RobotArmArray_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yahboomcar_msgs__srv__RobotArmArray_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yahboomcar_msgs__srv__RobotArmArray_Request__Sequence__are_equal(const yahboomcar_msgs__srv__RobotArmArray_Request__Sequence * lhs, const yahboomcar_msgs__srv__RobotArmArray_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yahboomcar_msgs__srv__RobotArmArray_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yahboomcar_msgs__srv__RobotArmArray_Request__Sequence__copy(
  const yahboomcar_msgs__srv__RobotArmArray_Request__Sequence * input,
  yahboomcar_msgs__srv__RobotArmArray_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yahboomcar_msgs__srv__RobotArmArray_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yahboomcar_msgs__srv__RobotArmArray_Request * data =
      (yahboomcar_msgs__srv__RobotArmArray_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yahboomcar_msgs__srv__RobotArmArray_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yahboomcar_msgs__srv__RobotArmArray_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yahboomcar_msgs__srv__RobotArmArray_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `joint_1`
// Member `joint_2`
// Member `joint_3`
// Member `joint_4`
// Member `joint_5`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
yahboomcar_msgs__srv__RobotArmArray_Response__init(yahboomcar_msgs__srv__RobotArmArray_Response * msg)
{
  if (!msg) {
    return false;
  }
  // joint_1
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint_1, 0)) {
    yahboomcar_msgs__srv__RobotArmArray_Response__fini(msg);
    return false;
  }
  // joint_2
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint_2, 0)) {
    yahboomcar_msgs__srv__RobotArmArray_Response__fini(msg);
    return false;
  }
  // joint_3
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint_3, 0)) {
    yahboomcar_msgs__srv__RobotArmArray_Response__fini(msg);
    return false;
  }
  // joint_4
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint_4, 0)) {
    yahboomcar_msgs__srv__RobotArmArray_Response__fini(msg);
    return false;
  }
  // joint_5
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint_5, 0)) {
    yahboomcar_msgs__srv__RobotArmArray_Response__fini(msg);
    return false;
  }
  // success
  return true;
}

void
yahboomcar_msgs__srv__RobotArmArray_Response__fini(yahboomcar_msgs__srv__RobotArmArray_Response * msg)
{
  if (!msg) {
    return;
  }
  // joint_1
  rosidl_runtime_c__float__Sequence__fini(&msg->joint_1);
  // joint_2
  rosidl_runtime_c__float__Sequence__fini(&msg->joint_2);
  // joint_3
  rosidl_runtime_c__float__Sequence__fini(&msg->joint_3);
  // joint_4
  rosidl_runtime_c__float__Sequence__fini(&msg->joint_4);
  // joint_5
  rosidl_runtime_c__float__Sequence__fini(&msg->joint_5);
  // success
}

bool
yahboomcar_msgs__srv__RobotArmArray_Response__are_equal(const yahboomcar_msgs__srv__RobotArmArray_Response * lhs, const yahboomcar_msgs__srv__RobotArmArray_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint_1
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->joint_1), &(rhs->joint_1)))
  {
    return false;
  }
  // joint_2
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->joint_2), &(rhs->joint_2)))
  {
    return false;
  }
  // joint_3
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->joint_3), &(rhs->joint_3)))
  {
    return false;
  }
  // joint_4
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->joint_4), &(rhs->joint_4)))
  {
    return false;
  }
  // joint_5
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->joint_5), &(rhs->joint_5)))
  {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
yahboomcar_msgs__srv__RobotArmArray_Response__copy(
  const yahboomcar_msgs__srv__RobotArmArray_Response * input,
  yahboomcar_msgs__srv__RobotArmArray_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // joint_1
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->joint_1), &(output->joint_1)))
  {
    return false;
  }
  // joint_2
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->joint_2), &(output->joint_2)))
  {
    return false;
  }
  // joint_3
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->joint_3), &(output->joint_3)))
  {
    return false;
  }
  // joint_4
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->joint_4), &(output->joint_4)))
  {
    return false;
  }
  // joint_5
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->joint_5), &(output->joint_5)))
  {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

yahboomcar_msgs__srv__RobotArmArray_Response *
yahboomcar_msgs__srv__RobotArmArray_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yahboomcar_msgs__srv__RobotArmArray_Response * msg = (yahboomcar_msgs__srv__RobotArmArray_Response *)allocator.allocate(sizeof(yahboomcar_msgs__srv__RobotArmArray_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yahboomcar_msgs__srv__RobotArmArray_Response));
  bool success = yahboomcar_msgs__srv__RobotArmArray_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yahboomcar_msgs__srv__RobotArmArray_Response__destroy(yahboomcar_msgs__srv__RobotArmArray_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yahboomcar_msgs__srv__RobotArmArray_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yahboomcar_msgs__srv__RobotArmArray_Response__Sequence__init(yahboomcar_msgs__srv__RobotArmArray_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yahboomcar_msgs__srv__RobotArmArray_Response * data = NULL;

  if (size) {
    data = (yahboomcar_msgs__srv__RobotArmArray_Response *)allocator.zero_allocate(size, sizeof(yahboomcar_msgs__srv__RobotArmArray_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yahboomcar_msgs__srv__RobotArmArray_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yahboomcar_msgs__srv__RobotArmArray_Response__fini(&data[i - 1]);
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
yahboomcar_msgs__srv__RobotArmArray_Response__Sequence__fini(yahboomcar_msgs__srv__RobotArmArray_Response__Sequence * array)
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
      yahboomcar_msgs__srv__RobotArmArray_Response__fini(&array->data[i]);
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

yahboomcar_msgs__srv__RobotArmArray_Response__Sequence *
yahboomcar_msgs__srv__RobotArmArray_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yahboomcar_msgs__srv__RobotArmArray_Response__Sequence * array = (yahboomcar_msgs__srv__RobotArmArray_Response__Sequence *)allocator.allocate(sizeof(yahboomcar_msgs__srv__RobotArmArray_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yahboomcar_msgs__srv__RobotArmArray_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yahboomcar_msgs__srv__RobotArmArray_Response__Sequence__destroy(yahboomcar_msgs__srv__RobotArmArray_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yahboomcar_msgs__srv__RobotArmArray_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yahboomcar_msgs__srv__RobotArmArray_Response__Sequence__are_equal(const yahboomcar_msgs__srv__RobotArmArray_Response__Sequence * lhs, const yahboomcar_msgs__srv__RobotArmArray_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yahboomcar_msgs__srv__RobotArmArray_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yahboomcar_msgs__srv__RobotArmArray_Response__Sequence__copy(
  const yahboomcar_msgs__srv__RobotArmArray_Response__Sequence * input,
  yahboomcar_msgs__srv__RobotArmArray_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yahboomcar_msgs__srv__RobotArmArray_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yahboomcar_msgs__srv__RobotArmArray_Response * data =
      (yahboomcar_msgs__srv__RobotArmArray_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yahboomcar_msgs__srv__RobotArmArray_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yahboomcar_msgs__srv__RobotArmArray_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yahboomcar_msgs__srv__RobotArmArray_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
