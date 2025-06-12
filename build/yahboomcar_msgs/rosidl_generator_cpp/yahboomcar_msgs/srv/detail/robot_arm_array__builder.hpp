// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yahboomcar_msgs:srv/RobotArmArray.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__BUILDER_HPP_
#define YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yahboomcar_msgs/srv/detail/robot_arm_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yahboomcar_msgs
{

namespace srv
{

namespace builder
{

class Init_RobotArmArray_Request_apply
{
public:
  Init_RobotArmArray_Request_apply()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yahboomcar_msgs::srv::RobotArmArray_Request apply(::yahboomcar_msgs::srv::RobotArmArray_Request::_apply_type arg)
  {
    msg_.apply = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yahboomcar_msgs::srv::RobotArmArray_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::yahboomcar_msgs::srv::RobotArmArray_Request>()
{
  return yahboomcar_msgs::srv::builder::Init_RobotArmArray_Request_apply();
}

}  // namespace yahboomcar_msgs


namespace yahboomcar_msgs
{

namespace srv
{

namespace builder
{

class Init_RobotArmArray_Response_angles
{
public:
  Init_RobotArmArray_Response_angles()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yahboomcar_msgs::srv::RobotArmArray_Response angles(::yahboomcar_msgs::srv::RobotArmArray_Response::_angles_type arg)
  {
    msg_.angles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yahboomcar_msgs::srv::RobotArmArray_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::yahboomcar_msgs::srv::RobotArmArray_Response>()
{
  return yahboomcar_msgs::srv::builder::Init_RobotArmArray_Response_angles();
}

}  // namespace yahboomcar_msgs

#endif  // YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__BUILDER_HPP_
