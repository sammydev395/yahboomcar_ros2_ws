// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yahboomcar_msgs:msg/PointArray.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__MSG__DETAIL__POINT_ARRAY__BUILDER_HPP_
#define YAHBOOMCAR_MSGS__MSG__DETAIL__POINT_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yahboomcar_msgs/msg/detail/point_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yahboomcar_msgs
{

namespace msg
{

namespace builder
{

class Init_PointArray_z
{
public:
  explicit Init_PointArray_z(::yahboomcar_msgs::msg::PointArray & msg)
  : msg_(msg)
  {}
  ::yahboomcar_msgs::msg::PointArray z(::yahboomcar_msgs::msg::PointArray::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yahboomcar_msgs::msg::PointArray msg_;
};

class Init_PointArray_y
{
public:
  explicit Init_PointArray_y(::yahboomcar_msgs::msg::PointArray & msg)
  : msg_(msg)
  {}
  Init_PointArray_z y(::yahboomcar_msgs::msg::PointArray::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PointArray_z(msg_);
  }

private:
  ::yahboomcar_msgs::msg::PointArray msg_;
};

class Init_PointArray_x
{
public:
  Init_PointArray_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PointArray_y x(::yahboomcar_msgs::msg::PointArray::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PointArray_y(msg_);
  }

private:
  ::yahboomcar_msgs::msg::PointArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yahboomcar_msgs::msg::PointArray>()
{
  return yahboomcar_msgs::msg::builder::Init_PointArray_x();
}

}  // namespace yahboomcar_msgs

#endif  // YAHBOOMCAR_MSGS__MSG__DETAIL__POINT_ARRAY__BUILDER_HPP_
