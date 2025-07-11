// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yahboomcar_msgs:srv/RobotArmArray.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__STRUCT_HPP_
#define YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__yahboomcar_msgs__srv__RobotArmArray_Request __attribute__((deprecated))
#else
# define DEPRECATED__yahboomcar_msgs__srv__RobotArmArray_Request __declspec(deprecated)
#endif

namespace yahboomcar_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RobotArmArray_Request_
{
  using Type = RobotArmArray_Request_<ContainerAllocator>;

  explicit RobotArmArray_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->apply = "";
    }
  }

  explicit RobotArmArray_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : apply(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->apply = "";
    }
  }

  // field types and members
  using _apply_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _apply_type apply;

  // setters for named parameter idiom
  Type & set__apply(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->apply = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yahboomcar_msgs__srv__RobotArmArray_Request
    std::shared_ptr<yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yahboomcar_msgs__srv__RobotArmArray_Request
    std::shared_ptr<yahboomcar_msgs::srv::RobotArmArray_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotArmArray_Request_ & other) const
  {
    if (this->apply != other.apply) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotArmArray_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotArmArray_Request_

// alias to use template instance with default allocator
using RobotArmArray_Request =
  yahboomcar_msgs::srv::RobotArmArray_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace yahboomcar_msgs


#ifndef _WIN32
# define DEPRECATED__yahboomcar_msgs__srv__RobotArmArray_Response __attribute__((deprecated))
#else
# define DEPRECATED__yahboomcar_msgs__srv__RobotArmArray_Response __declspec(deprecated)
#endif

namespace yahboomcar_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RobotArmArray_Response_
{
  using Type = RobotArmArray_Response_<ContainerAllocator>;

  explicit RobotArmArray_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit RobotArmArray_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _angles_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _angles_type angles;

  // setters for named parameter idiom
  Type & set__angles(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->angles = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yahboomcar_msgs__srv__RobotArmArray_Response
    std::shared_ptr<yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yahboomcar_msgs__srv__RobotArmArray_Response
    std::shared_ptr<yahboomcar_msgs::srv::RobotArmArray_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotArmArray_Response_ & other) const
  {
    if (this->angles != other.angles) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotArmArray_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotArmArray_Response_

// alias to use template instance with default allocator
using RobotArmArray_Response =
  yahboomcar_msgs::srv::RobotArmArray_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace yahboomcar_msgs

namespace yahboomcar_msgs
{

namespace srv
{

struct RobotArmArray
{
  using Request = yahboomcar_msgs::srv::RobotArmArray_Request;
  using Response = yahboomcar_msgs::srv::RobotArmArray_Response;
};

}  // namespace srv

}  // namespace yahboomcar_msgs

#endif  // YAHBOOMCAR_MSGS__SRV__DETAIL__ROBOT_ARM_ARRAY__STRUCT_HPP_
