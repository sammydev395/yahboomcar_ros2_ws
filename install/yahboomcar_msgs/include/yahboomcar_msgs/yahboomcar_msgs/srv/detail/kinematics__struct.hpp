// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yahboomcar_msgs:srv/Kinematics.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__STRUCT_HPP_
#define YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__yahboomcar_msgs__srv__Kinematics_Request __attribute__((deprecated))
#else
# define DEPRECATED__yahboomcar_msgs__srv__Kinematics_Request __declspec(deprecated)
#endif

namespace yahboomcar_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Kinematics_Request_
{
  using Type = Kinematics_Request_<ContainerAllocator>;

  explicit Kinematics_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->kin_name = "";
    }
  }

  explicit Kinematics_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : kin_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->kin_name = "";
    }
  }

  // field types and members
  using _kin_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _kin_name_type kin_name;
  using _src_pos_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _src_pos_type src_pos;
  using _src_joints_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _src_joints_type src_joints;

  // setters for named parameter idiom
  Type & set__kin_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->kin_name = _arg;
    return *this;
  }
  Type & set__src_pos(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->src_pos = _arg;
    return *this;
  }
  Type & set__src_joints(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->src_joints = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yahboomcar_msgs__srv__Kinematics_Request
    std::shared_ptr<yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yahboomcar_msgs__srv__Kinematics_Request
    std::shared_ptr<yahboomcar_msgs::srv::Kinematics_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Kinematics_Request_ & other) const
  {
    if (this->kin_name != other.kin_name) {
      return false;
    }
    if (this->src_pos != other.src_pos) {
      return false;
    }
    if (this->src_joints != other.src_joints) {
      return false;
    }
    return true;
  }
  bool operator!=(const Kinematics_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Kinematics_Request_

// alias to use template instance with default allocator
using Kinematics_Request =
  yahboomcar_msgs::srv::Kinematics_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace yahboomcar_msgs


#ifndef _WIN32
# define DEPRECATED__yahboomcar_msgs__srv__Kinematics_Response __attribute__((deprecated))
#else
# define DEPRECATED__yahboomcar_msgs__srv__Kinematics_Response __declspec(deprecated)
#endif

namespace yahboomcar_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Kinematics_Response_
{
  using Type = Kinematics_Response_<ContainerAllocator>;

  explicit Kinematics_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Kinematics_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _target_joints_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _target_joints_type target_joints;
  using _target_pos_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _target_pos_type target_pos;

  // setters for named parameter idiom
  Type & set__target_joints(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->target_joints = _arg;
    return *this;
  }
  Type & set__target_pos(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->target_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yahboomcar_msgs__srv__Kinematics_Response
    std::shared_ptr<yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yahboomcar_msgs__srv__Kinematics_Response
    std::shared_ptr<yahboomcar_msgs::srv::Kinematics_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Kinematics_Response_ & other) const
  {
    if (this->target_joints != other.target_joints) {
      return false;
    }
    if (this->target_pos != other.target_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const Kinematics_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Kinematics_Response_

// alias to use template instance with default allocator
using Kinematics_Response =
  yahboomcar_msgs::srv::Kinematics_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace yahboomcar_msgs

namespace yahboomcar_msgs
{

namespace srv
{

struct Kinematics
{
  using Request = yahboomcar_msgs::srv::Kinematics_Request;
  using Response = yahboomcar_msgs::srv::Kinematics_Response;
};

}  // namespace srv

}  // namespace yahboomcar_msgs

#endif  // YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__STRUCT_HPP_
