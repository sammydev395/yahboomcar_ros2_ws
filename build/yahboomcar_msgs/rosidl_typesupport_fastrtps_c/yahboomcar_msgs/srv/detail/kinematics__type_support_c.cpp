// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from yahboomcar_msgs:srv/Kinematics.idl
// generated code does not contain a copyright notice
#include "yahboomcar_msgs/srv/detail/kinematics__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "yahboomcar_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yahboomcar_msgs/srv/detail/kinematics__struct.h"
#include "yahboomcar_msgs/srv/detail/kinematics__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // src_joints, src_pos
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // src_joints, src_pos
#include "rosidl_runtime_c/string.h"  // kin_name
#include "rosidl_runtime_c/string_functions.h"  // kin_name

// forward declare type support functions


using _Kinematics_Request__ros_msg_type = yahboomcar_msgs__srv__Kinematics_Request;

static bool _Kinematics_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Kinematics_Request__ros_msg_type * ros_message = static_cast<const _Kinematics_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: kin_name
  {
    const rosidl_runtime_c__String * str = &ros_message->kin_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: src_pos
  {
    size_t size = ros_message->src_pos.size;
    auto array_ptr = ros_message->src_pos.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: src_joints
  {
    size_t size = ros_message->src_joints.size;
    auto array_ptr = ros_message->src_joints.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _Kinematics_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Kinematics_Request__ros_msg_type * ros_message = static_cast<_Kinematics_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: kin_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->kin_name.data) {
      rosidl_runtime_c__String__init(&ros_message->kin_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->kin_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'kin_name'\n");
      return false;
    }
  }

  // Field name: src_pos
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->src_pos.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->src_pos);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->src_pos, size)) {
      fprintf(stderr, "failed to create array for field 'src_pos'");
      return false;
    }
    auto array_ptr = ros_message->src_pos.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: src_joints
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->src_joints.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->src_joints);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->src_joints, size)) {
      fprintf(stderr, "failed to create array for field 'src_joints'");
      return false;
    }
    auto array_ptr = ros_message->src_joints.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yahboomcar_msgs
size_t get_serialized_size_yahboomcar_msgs__srv__Kinematics_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Kinematics_Request__ros_msg_type * ros_message = static_cast<const _Kinematics_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name kin_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->kin_name.size + 1);
  // field.name src_pos
  {
    size_t array_size = ros_message->src_pos.size;
    auto array_ptr = ros_message->src_pos.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name src_joints
  {
    size_t array_size = ros_message->src_joints.size;
    auto array_ptr = ros_message->src_joints.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Kinematics_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_yahboomcar_msgs__srv__Kinematics_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yahboomcar_msgs
size_t max_serialized_size_yahboomcar_msgs__srv__Kinematics_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: kin_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: src_pos
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: src_joints
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = yahboomcar_msgs__srv__Kinematics_Request;
    is_plain =
      (
      offsetof(DataType, src_joints) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Kinematics_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_yahboomcar_msgs__srv__Kinematics_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Kinematics_Request = {
  "yahboomcar_msgs::srv",
  "Kinematics_Request",
  _Kinematics_Request__cdr_serialize,
  _Kinematics_Request__cdr_deserialize,
  _Kinematics_Request__get_serialized_size,
  _Kinematics_Request__max_serialized_size
};

static rosidl_message_type_support_t _Kinematics_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Kinematics_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yahboomcar_msgs, srv, Kinematics_Request)() {
  return &_Kinematics_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "yahboomcar_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "yahboomcar_msgs/srv/detail/kinematics__struct.h"
// already included above
// #include "yahboomcar_msgs/srv/detail/kinematics__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // joint_1, joint_2, joint_3, joint_4, joint_5, target_joints, target_pos
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // joint_1, joint_2, joint_3, joint_4, joint_5, target_joints, target_pos

// forward declare type support functions


using _Kinematics_Response__ros_msg_type = yahboomcar_msgs__srv__Kinematics_Response;

static bool _Kinematics_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Kinematics_Response__ros_msg_type * ros_message = static_cast<const _Kinematics_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: target_joints
  {
    size_t size = ros_message->target_joints.size;
    auto array_ptr = ros_message->target_joints.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: target_pos
  {
    size_t size = ros_message->target_pos.size;
    auto array_ptr = ros_message->target_pos.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: roll
  {
    cdr << ros_message->roll;
  }

  // Field name: pitch
  {
    cdr << ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  // Field name: joint_1
  {
    size_t size = ros_message->joint_1.size;
    auto array_ptr = ros_message->joint_1.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: joint_2
  {
    size_t size = ros_message->joint_2.size;
    auto array_ptr = ros_message->joint_2.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: joint_3
  {
    size_t size = ros_message->joint_3.size;
    auto array_ptr = ros_message->joint_3.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: joint_4
  {
    size_t size = ros_message->joint_4.size;
    auto array_ptr = ros_message->joint_4.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: joint_5
  {
    size_t size = ros_message->joint_5.size;
    auto array_ptr = ros_message->joint_5.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _Kinematics_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Kinematics_Response__ros_msg_type * ros_message = static_cast<_Kinematics_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: target_joints
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->target_joints.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->target_joints);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->target_joints, size)) {
      fprintf(stderr, "failed to create array for field 'target_joints'");
      return false;
    }
    auto array_ptr = ros_message->target_joints.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: target_pos
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->target_pos.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->target_pos);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->target_pos, size)) {
      fprintf(stderr, "failed to create array for field 'target_pos'");
      return false;
    }
    auto array_ptr = ros_message->target_pos.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: z
  {
    cdr >> ros_message->z;
  }

  // Field name: roll
  {
    cdr >> ros_message->roll;
  }

  // Field name: pitch
  {
    cdr >> ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr >> ros_message->yaw;
  }

  // Field name: joint_1
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->joint_1.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->joint_1);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->joint_1, size)) {
      fprintf(stderr, "failed to create array for field 'joint_1'");
      return false;
    }
    auto array_ptr = ros_message->joint_1.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: joint_2
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->joint_2.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->joint_2);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->joint_2, size)) {
      fprintf(stderr, "failed to create array for field 'joint_2'");
      return false;
    }
    auto array_ptr = ros_message->joint_2.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: joint_3
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->joint_3.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->joint_3);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->joint_3, size)) {
      fprintf(stderr, "failed to create array for field 'joint_3'");
      return false;
    }
    auto array_ptr = ros_message->joint_3.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: joint_4
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->joint_4.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->joint_4);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->joint_4, size)) {
      fprintf(stderr, "failed to create array for field 'joint_4'");
      return false;
    }
    auto array_ptr = ros_message->joint_4.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: joint_5
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->joint_5.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->joint_5);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->joint_5, size)) {
      fprintf(stderr, "failed to create array for field 'joint_5'");
      return false;
    }
    auto array_ptr = ros_message->joint_5.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yahboomcar_msgs
size_t get_serialized_size_yahboomcar_msgs__srv__Kinematics_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Kinematics_Response__ros_msg_type * ros_message = static_cast<const _Kinematics_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name target_joints
  {
    size_t array_size = ros_message->target_joints.size;
    auto array_ptr = ros_message->target_joints.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_pos
  {
    size_t array_size = ros_message->target_pos.size;
    auto array_ptr = ros_message->target_pos.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name roll
  {
    size_t item_size = sizeof(ros_message->roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch
  {
    size_t item_size = sizeof(ros_message->pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw
  {
    size_t item_size = sizeof(ros_message->yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_1
  {
    size_t array_size = ros_message->joint_1.size;
    auto array_ptr = ros_message->joint_1.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_2
  {
    size_t array_size = ros_message->joint_2.size;
    auto array_ptr = ros_message->joint_2.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_3
  {
    size_t array_size = ros_message->joint_3.size;
    auto array_ptr = ros_message->joint_3.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_4
  {
    size_t array_size = ros_message->joint_4.size;
    auto array_ptr = ros_message->joint_4.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_5
  {
    size_t array_size = ros_message->joint_5.size;
    auto array_ptr = ros_message->joint_5.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Kinematics_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_yahboomcar_msgs__srv__Kinematics_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yahboomcar_msgs
size_t max_serialized_size_yahboomcar_msgs__srv__Kinematics_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: target_joints
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: target_pos
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: joint_1
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: joint_2
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: joint_3
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: joint_4
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: joint_5
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = yahboomcar_msgs__srv__Kinematics_Response;
    is_plain =
      (
      offsetof(DataType, joint_5) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Kinematics_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_yahboomcar_msgs__srv__Kinematics_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Kinematics_Response = {
  "yahboomcar_msgs::srv",
  "Kinematics_Response",
  _Kinematics_Response__cdr_serialize,
  _Kinematics_Response__cdr_deserialize,
  _Kinematics_Response__get_serialized_size,
  _Kinematics_Response__max_serialized_size
};

static rosidl_message_type_support_t _Kinematics_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Kinematics_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yahboomcar_msgs, srv, Kinematics_Response)() {
  return &_Kinematics_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "yahboomcar_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yahboomcar_msgs/srv/kinematics.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Kinematics__callbacks = {
  "yahboomcar_msgs::srv",
  "Kinematics",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yahboomcar_msgs, srv, Kinematics_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yahboomcar_msgs, srv, Kinematics_Response)(),
};

static rosidl_service_type_support_t Kinematics__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Kinematics__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yahboomcar_msgs, srv, Kinematics)() {
  return &Kinematics__handle;
}

#if defined(__cplusplus)
}
#endif
