// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yahboomcar_msgs:msg/ImageMsg.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__MSG__DETAIL__IMAGE_MSG__BUILDER_HPP_
#define YAHBOOMCAR_MSGS__MSG__DETAIL__IMAGE_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yahboomcar_msgs/msg/detail/image_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yahboomcar_msgs
{

namespace msg
{

namespace builder
{

class Init_ImageMsg_data
{
public:
  explicit Init_ImageMsg_data(::yahboomcar_msgs::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  ::yahboomcar_msgs::msg::ImageMsg data(::yahboomcar_msgs::msg::ImageMsg::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ImageMsg msg_;
};

class Init_ImageMsg_channels
{
public:
  explicit Init_ImageMsg_channels(::yahboomcar_msgs::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_data channels(::yahboomcar_msgs::msg::ImageMsg::_channels_type arg)
  {
    msg_.channels = std::move(arg);
    return Init_ImageMsg_data(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ImageMsg msg_;
};

class Init_ImageMsg_width
{
public:
  explicit Init_ImageMsg_width(::yahboomcar_msgs::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_channels width(::yahboomcar_msgs::msg::ImageMsg::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ImageMsg_channels(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ImageMsg msg_;
};

class Init_ImageMsg_height
{
public:
  explicit Init_ImageMsg_height(::yahboomcar_msgs::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_width height(::yahboomcar_msgs::msg::ImageMsg::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ImageMsg_width(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ImageMsg msg_;
};

class Init_ImageMsg_image_score
{
public:
  explicit Init_ImageMsg_image_score(::yahboomcar_msgs::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_height image_score(::yahboomcar_msgs::msg::ImageMsg::_image_score_type arg)
  {
    msg_.image_score = std::move(arg);
    return Init_ImageMsg_height(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ImageMsg msg_;
};

class Init_ImageMsg_image_id
{
public:
  explicit Init_ImageMsg_image_id(::yahboomcar_msgs::msg::ImageMsg & msg)
  : msg_(msg)
  {}
  Init_ImageMsg_image_score image_id(::yahboomcar_msgs::msg::ImageMsg::_image_id_type arg)
  {
    msg_.image_id = std::move(arg);
    return Init_ImageMsg_image_score(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ImageMsg msg_;
};

class Init_ImageMsg_image_path
{
public:
  Init_ImageMsg_image_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageMsg_image_id image_path(::yahboomcar_msgs::msg::ImageMsg::_image_path_type arg)
  {
    msg_.image_path = std::move(arg);
    return Init_ImageMsg_image_id(msg_);
  }

private:
  ::yahboomcar_msgs::msg::ImageMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yahboomcar_msgs::msg::ImageMsg>()
{
  return yahboomcar_msgs::msg::builder::Init_ImageMsg_image_path();
}

}  // namespace yahboomcar_msgs

#endif  // YAHBOOMCAR_MSGS__MSG__DETAIL__IMAGE_MSG__BUILDER_HPP_
