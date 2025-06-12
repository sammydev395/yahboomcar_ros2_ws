// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yahboomcar_msgs:srv/Kinematics.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__BUILDER_HPP_
#define YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yahboomcar_msgs/srv/detail/kinematics__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yahboomcar_msgs
{

namespace srv
{

namespace builder
{

class Init_Kinematics_Request_src_joints
{
public:
  explicit Init_Kinematics_Request_src_joints(::yahboomcar_msgs::srv::Kinematics_Request & msg)
  : msg_(msg)
  {}
  ::yahboomcar_msgs::srv::Kinematics_Request src_joints(::yahboomcar_msgs::srv::Kinematics_Request::_src_joints_type arg)
  {
    msg_.src_joints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yahboomcar_msgs::srv::Kinematics_Request msg_;
};

class Init_Kinematics_Request_src_pos
{
public:
  explicit Init_Kinematics_Request_src_pos(::yahboomcar_msgs::srv::Kinematics_Request & msg)
  : msg_(msg)
  {}
  Init_Kinematics_Request_src_joints src_pos(::yahboomcar_msgs::srv::Kinematics_Request::_src_pos_type arg)
  {
    msg_.src_pos = std::move(arg);
    return Init_Kinematics_Request_src_joints(msg_);
  }

private:
  ::yahboomcar_msgs::srv::Kinematics_Request msg_;
};

class Init_Kinematics_Request_kin_name
{
public:
  Init_Kinematics_Request_kin_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Kinematics_Request_src_pos kin_name(::yahboomcar_msgs::srv::Kinematics_Request::_kin_name_type arg)
  {
    msg_.kin_name = std::move(arg);
    return Init_Kinematics_Request_src_pos(msg_);
  }

private:
  ::yahboomcar_msgs::srv::Kinematics_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::yahboomcar_msgs::srv::Kinematics_Request>()
{
  return yahboomcar_msgs::srv::builder::Init_Kinematics_Request_kin_name();
}

}  // namespace yahboomcar_msgs


namespace yahboomcar_msgs
{

namespace srv
{

namespace builder
{

class Init_Kinematics_Response_target_pos
{
public:
  explicit Init_Kinematics_Response_target_pos(::yahboomcar_msgs::srv::Kinematics_Response & msg)
  : msg_(msg)
  {}
  ::yahboomcar_msgs::srv::Kinematics_Response target_pos(::yahboomcar_msgs::srv::Kinematics_Response::_target_pos_type arg)
  {
    msg_.target_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yahboomcar_msgs::srv::Kinematics_Response msg_;
};

class Init_Kinematics_Response_target_joints
{
public:
  Init_Kinematics_Response_target_joints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Kinematics_Response_target_pos target_joints(::yahboomcar_msgs::srv::Kinematics_Response::_target_joints_type arg)
  {
    msg_.target_joints = std::move(arg);
    return Init_Kinematics_Response_target_pos(msg_);
  }

private:
  ::yahboomcar_msgs::srv::Kinematics_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::yahboomcar_msgs::srv::Kinematics_Response>()
{
  return yahboomcar_msgs::srv::builder::Init_Kinematics_Response_target_joints();
}

}  // namespace yahboomcar_msgs

#endif  // YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__BUILDER_HPP_
