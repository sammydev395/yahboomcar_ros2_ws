// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yahboomcar_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__MSG__DETAIL__POSITION__TRAITS_HPP_
#define YAHBOOMCAR_MSGS__MSG__DETAIL__POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yahboomcar_msgs/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace yahboomcar_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Position & msg,
  std::ostream & out)
{
  out << "{";
  // member: angle_x
  {
    out << "angle_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_x, out);
    out << ", ";
  }

  // member: angle_y
  {
    out << "angle_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_y, out);
    out << ", ";
  }

  // member: angle_z
  {
    out << "angle_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: angle_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_x, out);
    out << "\n";
  }

  // member: angle_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_y, out);
    out << "\n";
  }

  // member: angle_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Position & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace yahboomcar_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yahboomcar_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yahboomcar_msgs::msg::Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  yahboomcar_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yahboomcar_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yahboomcar_msgs::msg::Position & msg)
{
  return yahboomcar_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yahboomcar_msgs::msg::Position>()
{
  return "yahboomcar_msgs::msg::Position";
}

template<>
inline const char * name<yahboomcar_msgs::msg::Position>()
{
  return "yahboomcar_msgs/msg/Position";
}

template<>
struct has_fixed_size<yahboomcar_msgs::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<yahboomcar_msgs::msg::Position>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<yahboomcar_msgs::msg::Position>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YAHBOOMCAR_MSGS__MSG__DETAIL__POSITION__TRAITS_HPP_
