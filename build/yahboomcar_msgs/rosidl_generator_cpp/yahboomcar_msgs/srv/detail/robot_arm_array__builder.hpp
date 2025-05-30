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

class Init_RobotArmArray_Response_success
{
public:
  explicit Init_RobotArmArray_Response_success(::yahboomcar_msgs::srv::RobotArmArray_Response & msg)
  : msg_(msg)
  {}
  ::yahboomcar_msgs::srv::RobotArmArray_Response success(::yahboomcar_msgs::srv::RobotArmArray_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yahboomcar_msgs::srv::RobotArmArray_Response msg_;
};

class Init_RobotArmArray_Response_joint_5
{
public:
  explicit Init_RobotArmArray_Response_joint_5(::yahboomcar_msgs::srv::RobotArmArray_Response & msg)
  : msg_(msg)
  {}
  Init_RobotArmArray_Response_success joint_5(::yahboomcar_msgs::srv::RobotArmArray_Response::_joint_5_type arg)
  {
    msg_.joint_5 = std::move(arg);
    return Init_RobotArmArray_Response_success(msg_);
  }

private:
  ::yahboomcar_msgs::srv::RobotArmArray_Response msg_;
};

class Init_RobotArmArray_Response_joint_4
{
public:
  explicit Init_RobotArmArray_Response_joint_4(::yahboomcar_msgs::srv::RobotArmArray_Response & msg)
  : msg_(msg)
  {}
  Init_RobotArmArray_Response_joint_5 joint_4(::yahboomcar_msgs::srv::RobotArmArray_Response::_joint_4_type arg)
  {
    msg_.joint_4 = std::move(arg);
    return Init_RobotArmArray_Response_joint_5(msg_);
  }

private:
  ::yahboomcar_msgs::srv::RobotArmArray_Response msg_;
};

class Init_RobotArmArray_Response_joint_3
{
public:
  explicit Init_RobotArmArray_Response_joint_3(::yahboomcar_msgs::srv::RobotArmArray_Response & msg)
  : msg_(msg)
  {}
  Init_RobotArmArray_Response_joint_4 joint_3(::yahboomcar_msgs::srv::RobotArmArray_Response::_joint_3_type arg)
  {
    msg_.joint_3 = std::move(arg);
    return Init_RobotArmArray_Response_joint_4(msg_);
  }

private:
  ::yahboomcar_msgs::srv::RobotArmArray_Response msg_;
};

class Init_RobotArmArray_Response_joint_2
{
public:
  explicit Init_RobotArmArray_Response_joint_2(::yahboomcar_msgs::srv::RobotArmArray_Response & msg)
  : msg_(msg)
  {}
  Init_RobotArmArray_Response_joint_3 joint_2(::yahboomcar_msgs::srv::RobotArmArray_Response::_joint_2_type arg)
  {
    msg_.joint_2 = std::move(arg);
    return Init_RobotArmArray_Response_joint_3(msg_);
  }

private:
  ::yahboomcar_msgs::srv::RobotArmArray_Response msg_;
};

class Init_RobotArmArray_Response_joint_1
{
public:
  Init_RobotArmArray_Response_joint_1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotArmArray_Response_joint_2 joint_1(::yahboomcar_msgs::srv::RobotArmArray_Response::_joint_1_type arg)
  {
    msg_.joint_1 = std::move(arg);
    return Init_RobotArmArray_Response_joint_2(msg_);
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
  return yahboomcar_msgs::srv::builder::Init_RobotArmArray_Response_joint_1();
}

}  // namespace yahboomcar_msgs

#endif  // YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__BUILDER_HPP_
