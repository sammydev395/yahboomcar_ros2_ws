// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yahboomcar_msgs:srv/Kinematics.idl
// generated code does not contain a copyright notice

#ifndef YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__TRAITS_HPP_
#define YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yahboomcar_msgs/srv/detail/kinematics__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace yahboomcar_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Kinematics_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: kin_name
  {
    out << "kin_name: ";
    rosidl_generator_traits::value_to_yaml(msg.kin_name, out);
    out << ", ";
  }

  // member: src_pos
  {
    if (msg.src_pos.size() == 0) {
      out << "src_pos: []";
    } else {
      out << "src_pos: [";
      size_t pending_items = msg.src_pos.size();
      for (auto item : msg.src_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: src_joints
  {
    if (msg.src_joints.size() == 0) {
      out << "src_joints: []";
    } else {
      out << "src_joints: [";
      size_t pending_items = msg.src_joints.size();
      for (auto item : msg.src_joints) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Kinematics_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: kin_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kin_name: ";
    rosidl_generator_traits::value_to_yaml(msg.kin_name, out);
    out << "\n";
  }

  // member: src_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.src_pos.size() == 0) {
      out << "src_pos: []\n";
    } else {
      out << "src_pos:\n";
      for (auto item : msg.src_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: src_joints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.src_joints.size() == 0) {
      out << "src_joints: []\n";
    } else {
      out << "src_joints:\n";
      for (auto item : msg.src_joints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Kinematics_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace yahboomcar_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yahboomcar_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yahboomcar_msgs::srv::Kinematics_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  yahboomcar_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yahboomcar_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const yahboomcar_msgs::srv::Kinematics_Request & msg)
{
  return yahboomcar_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<yahboomcar_msgs::srv::Kinematics_Request>()
{
  return "yahboomcar_msgs::srv::Kinematics_Request";
}

template<>
inline const char * name<yahboomcar_msgs::srv::Kinematics_Request>()
{
  return "yahboomcar_msgs/srv/Kinematics_Request";
}

template<>
struct has_fixed_size<yahboomcar_msgs::srv::Kinematics_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yahboomcar_msgs::srv::Kinematics_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yahboomcar_msgs::srv::Kinematics_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace yahboomcar_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Kinematics_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_joints
  {
    if (msg.target_joints.size() == 0) {
      out << "target_joints: []";
    } else {
      out << "target_joints: [";
      size_t pending_items = msg.target_joints.size();
      for (auto item : msg.target_joints) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: target_pos
  {
    if (msg.target_pos.size() == 0) {
      out << "target_pos: []";
    } else {
      out << "target_pos: [";
      size_t pending_items = msg.target_pos.size();
      for (auto item : msg.target_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: joint_1
  {
    if (msg.joint_1.size() == 0) {
      out << "joint_1: []";
    } else {
      out << "joint_1: [";
      size_t pending_items = msg.joint_1.size();
      for (auto item : msg.joint_1) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_2
  {
    if (msg.joint_2.size() == 0) {
      out << "joint_2: []";
    } else {
      out << "joint_2: [";
      size_t pending_items = msg.joint_2.size();
      for (auto item : msg.joint_2) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_3
  {
    if (msg.joint_3.size() == 0) {
      out << "joint_3: []";
    } else {
      out << "joint_3: [";
      size_t pending_items = msg.joint_3.size();
      for (auto item : msg.joint_3) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_4
  {
    if (msg.joint_4.size() == 0) {
      out << "joint_4: []";
    } else {
      out << "joint_4: [";
      size_t pending_items = msg.joint_4.size();
      for (auto item : msg.joint_4) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_5
  {
    if (msg.joint_5.size() == 0) {
      out << "joint_5: []";
    } else {
      out << "joint_5: [";
      size_t pending_items = msg.joint_5.size();
      for (auto item : msg.joint_5) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Kinematics_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_joints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_joints.size() == 0) {
      out << "target_joints: []\n";
    } else {
      out << "target_joints:\n";
      for (auto item : msg.target_joints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: target_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_pos.size() == 0) {
      out << "target_pos: []\n";
    } else {
      out << "target_pos:\n";
      for (auto item : msg.target_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: joint_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_1.size() == 0) {
      out << "joint_1: []\n";
    } else {
      out << "joint_1:\n";
      for (auto item : msg.joint_1) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_2.size() == 0) {
      out << "joint_2: []\n";
    } else {
      out << "joint_2:\n";
      for (auto item : msg.joint_2) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_3.size() == 0) {
      out << "joint_3: []\n";
    } else {
      out << "joint_3:\n";
      for (auto item : msg.joint_3) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_4.size() == 0) {
      out << "joint_4: []\n";
    } else {
      out << "joint_4:\n";
      for (auto item : msg.joint_4) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_5.size() == 0) {
      out << "joint_5: []\n";
    } else {
      out << "joint_5:\n";
      for (auto item : msg.joint_5) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Kinematics_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace yahboomcar_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yahboomcar_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yahboomcar_msgs::srv::Kinematics_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  yahboomcar_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yahboomcar_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const yahboomcar_msgs::srv::Kinematics_Response & msg)
{
  return yahboomcar_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<yahboomcar_msgs::srv::Kinematics_Response>()
{
  return "yahboomcar_msgs::srv::Kinematics_Response";
}

template<>
inline const char * name<yahboomcar_msgs::srv::Kinematics_Response>()
{
  return "yahboomcar_msgs/srv/Kinematics_Response";
}

template<>
struct has_fixed_size<yahboomcar_msgs::srv::Kinematics_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yahboomcar_msgs::srv::Kinematics_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yahboomcar_msgs::srv::Kinematics_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<yahboomcar_msgs::srv::Kinematics>()
{
  return "yahboomcar_msgs::srv::Kinematics";
}

template<>
inline const char * name<yahboomcar_msgs::srv::Kinematics>()
{
  return "yahboomcar_msgs/srv/Kinematics";
}

template<>
struct has_fixed_size<yahboomcar_msgs::srv::Kinematics>
  : std::integral_constant<
    bool,
    has_fixed_size<yahboomcar_msgs::srv::Kinematics_Request>::value &&
    has_fixed_size<yahboomcar_msgs::srv::Kinematics_Response>::value
  >
{
};

template<>
struct has_bounded_size<yahboomcar_msgs::srv::Kinematics>
  : std::integral_constant<
    bool,
    has_bounded_size<yahboomcar_msgs::srv::Kinematics_Request>::value &&
    has_bounded_size<yahboomcar_msgs::srv::Kinematics_Response>::value
  >
{
};

template<>
struct is_service<yahboomcar_msgs::srv::Kinematics>
  : std::true_type
{
};

template<>
struct is_service_request<yahboomcar_msgs::srv::Kinematics_Request>
  : std::true_type
{
};

template<>
struct is_service_response<yahboomcar_msgs::srv::Kinematics_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // YAHBOOMCAR_MSGS__SRV__DETAIL__KINEMATICS__TRAITS_HPP_
