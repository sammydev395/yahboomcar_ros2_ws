// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yahboomcar_msgs:srv/RobotArmArray.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__TRAITS_HPP_
#define YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yahboomcar_msgs/srv/detail/robot_arm_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace yahboomcar_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotArmArray_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: apply
  {
    out << "apply: ";
    rosidl_generator_traits::value_to_yaml(msg.apply, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotArmArray_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: apply
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "apply: ";
    rosidl_generator_traits::value_to_yaml(msg.apply, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotArmArray_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace yahboomcar_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yahboomcar_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yahboomcar_msgs::srv::RobotArmArray_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  yahboomcar_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yahboomcar_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const yahboomcar_msgs::srv::RobotArmArray_Request & msg)
{
  return yahboomcar_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<yahboomcar_msgs::srv::RobotArmArray_Request>()
{
  return "yahboomcar_msgs::srv::RobotArmArray_Request";
}

template<>
inline const char * name<yahboomcar_msgs::srv::RobotArmArray_Request>()
{
  return "yahboomcar_msgs/srv/RobotArmArray_Request";
}

template<>
struct has_fixed_size<yahboomcar_msgs::srv::RobotArmArray_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yahboomcar_msgs::srv::RobotArmArray_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yahboomcar_msgs::srv::RobotArmArray_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace yahboomcar_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotArmArray_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: angles
  {
    if (msg.angles.size() == 0) {
      out << "angles: []";
    } else {
      out << "angles: [";
      size_t pending_items = msg.angles.size();
      for (auto item : msg.angles) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotArmArray_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.angles.size() == 0) {
      out << "angles: []\n";
    } else {
      out << "angles:\n";
      for (auto item : msg.angles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotArmArray_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace yahboomcar_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yahboomcar_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yahboomcar_msgs::srv::RobotArmArray_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  yahboomcar_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yahboomcar_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const yahboomcar_msgs::srv::RobotArmArray_Response & msg)
{
  return yahboomcar_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<yahboomcar_msgs::srv::RobotArmArray_Response>()
{
  return "yahboomcar_msgs::srv::RobotArmArray_Response";
}

template<>
inline const char * name<yahboomcar_msgs::srv::RobotArmArray_Response>()
{
  return "yahboomcar_msgs/srv/RobotArmArray_Response";
}

template<>
struct has_fixed_size<yahboomcar_msgs::srv::RobotArmArray_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yahboomcar_msgs::srv::RobotArmArray_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yahboomcar_msgs::srv::RobotArmArray_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<yahboomcar_msgs::srv::RobotArmArray>()
{
  return "yahboomcar_msgs::srv::RobotArmArray";
}

template<>
inline const char * name<yahboomcar_msgs::srv::RobotArmArray>()
{
  return "yahboomcar_msgs/srv/RobotArmArray";
}

template<>
struct has_fixed_size<yahboomcar_msgs::srv::RobotArmArray>
  : std::integral_constant<
    bool,
    has_fixed_size<yahboomcar_msgs::srv::RobotArmArray_Request>::value &&
    has_fixed_size<yahboomcar_msgs::srv::RobotArmArray_Response>::value
  >
{
};

template<>
struct has_bounded_size<yahboomcar_msgs::srv::RobotArmArray>
  : std::integral_constant<
    bool,
    has_bounded_size<yahboomcar_msgs::srv::RobotArmArray_Request>::value &&
    has_bounded_size<yahboomcar_msgs::srv::RobotArmArray_Response>::value
  >
{
};

template<>
struct is_service<yahboomcar_msgs::srv::RobotArmArray>
  : std::true_type
{
};

template<>
struct is_service_request<yahboomcar_msgs::srv::RobotArmArray_Request>
  : std::true_type
{
};

template<>
struct is_service_response<yahboomcar_msgs::srv::RobotArmArray_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__TRAITS_HPP_
