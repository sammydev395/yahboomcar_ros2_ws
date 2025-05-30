// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yahboomcar_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_
#define YAHBOOMCAR_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yahboomcar_msgs/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yahboomcar_msgs
{

namespace msg
{

namespace builder
{

class Init_Position_angle_z
{
public:
  explicit Init_Position_angle_z(::yahboomcar_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  ::yahboomcar_msgs::msg::Position angle_z(::yahboomcar_msgs::msg::Position::_angle_z_type arg)
  {
    msg_.angle_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yahboomcar_msgs::msg::Position msg_;
};

class Init_Position_angle_y
{
public:
  explicit Init_Position_angle_y(::yahboomcar_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_angle_z angle_y(::yahboomcar_msgs::msg::Position::_angle_y_type arg)
  {
    msg_.angle_y = std::move(arg);
    return Init_Position_angle_z(msg_);
  }

private:
  ::yahboomcar_msgs::msg::Position msg_;
};

class Init_Position_angle_x
{
public:
  Init_Position_angle_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_angle_y angle_x(::yahboomcar_msgs::msg::Position::_angle_x_type arg)
  {
    msg_.angle_x = std::move(arg);
    return Init_Position_angle_y(msg_);
  }

private:
  ::yahboomcar_msgs::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yahboomcar_msgs::msg::Position>()
{
  return yahboomcar_msgs::msg::builder::Init_Position_angle_x();
}

}  // namespace yahboomcar_msgs

#endif  // YAHBOOMCAR_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_
