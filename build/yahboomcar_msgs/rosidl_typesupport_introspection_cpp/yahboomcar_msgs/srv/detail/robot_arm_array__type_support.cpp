// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from yahboomcar_msgs:srv/RobotArmArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "yahboomcar_msgs/srv/detail/robot_arm_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace yahboomcar_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void RobotArmArray_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) yahboomcar_msgs::srv::RobotArmArray_Request(_init);
}

void RobotArmArray_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<yahboomcar_msgs::srv::RobotArmArray_Request *>(message_memory);
  typed_message->~RobotArmArray_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotArmArray_Request_message_member_array[1] = {
  {
    "apply",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs::srv::RobotArmArray_Request, apply),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotArmArray_Request_message_members = {
  "yahboomcar_msgs::srv",  // message namespace
  "RobotArmArray_Request",  // message name
  1,  // number of fields
  sizeof(yahboomcar_msgs::srv::RobotArmArray_Request),
  RobotArmArray_Request_message_member_array,  // message members
  RobotArmArray_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotArmArray_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotArmArray_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotArmArray_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace yahboomcar_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<yahboomcar_msgs::srv::RobotArmArray_Request>()
{
  return &::yahboomcar_msgs::srv::rosidl_typesupport_introspection_cpp::RobotArmArray_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, yahboomcar_msgs, srv, RobotArmArray_Request)() {
  return &::yahboomcar_msgs::srv::rosidl_typesupport_introspection_cpp::RobotArmArray_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "yahboomcar_msgs/srv/detail/robot_arm_array__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace yahboomcar_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void RobotArmArray_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) yahboomcar_msgs::srv::RobotArmArray_Response(_init);
}

void RobotArmArray_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<yahboomcar_msgs::srv::RobotArmArray_Response *>(message_memory);
  typed_message->~RobotArmArray_Response();
}

size_t size_function__RobotArmArray_Response__angles(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RobotArmArray_Response__angles(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotArmArray_Response__angles(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotArmArray_Response__angles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__RobotArmArray_Response__angles(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__RobotArmArray_Response__angles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__RobotArmArray_Response__angles(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__RobotArmArray_Response__angles(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotArmArray_Response_message_member_array[1] = {
  {
    "angles",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yahboomcar_msgs::srv::RobotArmArray_Response, angles),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotArmArray_Response__angles,  // size() function pointer
    get_const_function__RobotArmArray_Response__angles,  // get_const(index) function pointer
    get_function__RobotArmArray_Response__angles,  // get(index) function pointer
    fetch_function__RobotArmArray_Response__angles,  // fetch(index, &value) function pointer
    assign_function__RobotArmArray_Response__angles,  // assign(index, value) function pointer
    resize_function__RobotArmArray_Response__angles  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotArmArray_Response_message_members = {
  "yahboomcar_msgs::srv",  // message namespace
  "RobotArmArray_Response",  // message name
  1,  // number of fields
  sizeof(yahboomcar_msgs::srv::RobotArmArray_Response),
  RobotArmArray_Response_message_member_array,  // message members
  RobotArmArray_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotArmArray_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotArmArray_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotArmArray_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace yahboomcar_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<yahboomcar_msgs::srv::RobotArmArray_Response>()
{
  return &::yahboomcar_msgs::srv::rosidl_typesupport_introspection_cpp::RobotArmArray_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, yahboomcar_msgs, srv, RobotArmArray_Response)() {
  return &::yahboomcar_msgs::srv::rosidl_typesupport_introspection_cpp::RobotArmArray_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "yahboomcar_msgs/srv/detail/robot_arm_array__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace yahboomcar_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers RobotArmArray_service_members = {
  "yahboomcar_msgs::srv",  // service namespace
  "RobotArmArray",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<yahboomcar_msgs::srv::RobotArmArray>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t RobotArmArray_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotArmArray_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace yahboomcar_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<yahboomcar_msgs::srv::RobotArmArray>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::yahboomcar_msgs::srv::rosidl_typesupport_introspection_cpp::RobotArmArray_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::yahboomcar_msgs::srv::RobotArmArray_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::yahboomcar_msgs::srv::RobotArmArray_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, yahboomcar_msgs, srv, RobotArmArray)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<yahboomcar_msgs::srv::RobotArmArray>();
}

#ifdef __cplusplus
}
#endif
