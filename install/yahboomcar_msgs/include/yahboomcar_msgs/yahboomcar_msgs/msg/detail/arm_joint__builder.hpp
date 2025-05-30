// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yahboomcar_msgs:msg/ArmJoint.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__MSG__DETAIL__ARM_JOINT__BUILDER_HPP_
#define YAHBOOMCAR_MSGS__MSG__DETAIL__ARM_JOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yahboomcar_msgs/msg/detail/arm_joint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yahboomcar_msgs
{

namespace msg
{

namespace builder
{

class Init_ArmJoint_joint_5
{
public:
  explicit Init_ArmJoint_joint_5(::yahboomcar_msgs::msg::ArmJoint & msg)
  : msg_(msg)
  {}
  ::yahboomcar_msgs::msg::ArmJoint joint_5(::yahboomcar_msgs::msg::ArmJoint::_joint_5_type arg)
  {
    msg_.joint_5 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ArmJoint msg_;
};

class Init_ArmJoint_joint_4
{
public:
  explicit Init_ArmJoint_joint_4(::yahboomcar_msgs::msg::ArmJoint & msg)
  : msg_(msg)
  {}
  Init_ArmJoint_joint_5 joint_4(::yahboomcar_msgs::msg::ArmJoint::_joint_4_type arg)
  {
    msg_.joint_4 = std::move(arg);
    return Init_ArmJoint_joint_5(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ArmJoint msg_;
};

class Init_ArmJoint_joint_3
{
public:
  explicit Init_ArmJoint_joint_3(::yahboomcar_msgs::msg::ArmJoint & msg)
  : msg_(msg)
  {}
  Init_ArmJoint_joint_4 joint_3(::yahboomcar_msgs::msg::ArmJoint::_joint_3_type arg)
  {
    msg_.joint_3 = std::move(arg);
    return Init_ArmJoint_joint_4(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ArmJoint msg_;
};

class Init_ArmJoint_joint_2
{
public:
  explicit Init_ArmJoint_joint_2(::yahboomcar_msgs::msg::ArmJoint & msg)
  : msg_(msg)
  {}
  Init_ArmJoint_joint_3 joint_2(::yahboomcar_msgs::msg::ArmJoint::_joint_2_type arg)
  {
    msg_.joint_2 = std::move(arg);
    return Init_ArmJoint_joint_3(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ArmJoint msg_;
};

class Init_ArmJoint_joint_1
{
public:
  explicit Init_ArmJoint_joint_1(::yahboomcar_msgs::msg::ArmJoint & msg)
  : msg_(msg)
  {}
  Init_ArmJoint_joint_2 joint_1(::yahboomcar_msgs::msg::ArmJoint::_joint_1_type arg)
  {
    msg_.joint_1 = std::move(arg);
    return Init_ArmJoint_joint_2(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ArmJoint msg_;
};

class Init_ArmJoint_angle
{
public:
  explicit Init_ArmJoint_angle(::yahboomcar_msgs::msg::ArmJoint & msg)
  : msg_(msg)
  {}
  Init_ArmJoint_joint_1 angle(::yahboomcar_msgs::msg::ArmJoint::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_ArmJoint_joint_1(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ArmJoint msg_;
};

class Init_ArmJoint_run_time
{
public:
  explicit Init_ArmJoint_run_time(::yahboomcar_msgs::msg::ArmJoint & msg)
  : msg_(msg)
  {}
  Init_ArmJoint_angle run_time(::yahboomcar_msgs::msg::ArmJoint::_run_time_type arg)
  {
    msg_.run_time = std::move(arg);
    return Init_ArmJoint_angle(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ArmJoint msg_;
};

class Init_ArmJoint_id
{
public:
  Init_ArmJoint_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmJoint_run_time id(::yahboomcar_msgs::msg::ArmJoint::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ArmJoint_run_time(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ArmJoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yahboomcar_msgs::msg::ArmJoint>()
{
  return yahboomcar_msgs::msg::builder::Init_ArmJoint_id();
}

}  // namespace yahboomcar_msgs

#endif  // YAHBOOMCAR_MSGS__MSG__DETAIL__ARM_JOINT__BUILDER_HPP_
