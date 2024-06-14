// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flexiv_msgs:msg/RobotStates.idl
// generated code does not contain a copyright notice

#ifndef FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__TRAITS_HPP_
#define FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flexiv_msgs/msg/detail/robot_states__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'tcp_pose'
// Member 'tcp_pose_des'
// Member 'cam_pose'
// Member 'flange_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'tcp_vel'
#include "geometry_msgs/msg/detail/accel__traits.hpp"
// Member 'ft_sensor_raw'
// Member 'ext_wrench_tcp_frame'
// Member 'ext_wrench_base_frame'
#include "geometry_msgs/msg/detail/wrench__traits.hpp"

namespace flexiv_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStates & msg,
  std::ostream & out)
{
  out << "{";
  // member: q
  {
    if (msg.q.size() == 0) {
      out << "q: []";
    } else {
      out << "q: [";
      size_t pending_items = msg.q.size();
      for (auto item : msg.q) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: theta
  {
    if (msg.theta.size() == 0) {
      out << "theta: []";
    } else {
      out << "theta: [";
      size_t pending_items = msg.theta.size();
      for (auto item : msg.theta) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: dq
  {
    if (msg.dq.size() == 0) {
      out << "dq: []";
    } else {
      out << "dq: [";
      size_t pending_items = msg.dq.size();
      for (auto item : msg.dq) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: dtheta
  {
    if (msg.dtheta.size() == 0) {
      out << "dtheta: []";
    } else {
      out << "dtheta: [";
      size_t pending_items = msg.dtheta.size();
      for (auto item : msg.dtheta) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tau
  {
    if (msg.tau.size() == 0) {
      out << "tau: []";
    } else {
      out << "tau: [";
      size_t pending_items = msg.tau.size();
      for (auto item : msg.tau) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tau_des
  {
    if (msg.tau_des.size() == 0) {
      out << "tau_des: []";
    } else {
      out << "tau_des: [";
      size_t pending_items = msg.tau_des.size();
      for (auto item : msg.tau_des) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tau_dot
  {
    if (msg.tau_dot.size() == 0) {
      out << "tau_dot: []";
    } else {
      out << "tau_dot: [";
      size_t pending_items = msg.tau_dot.size();
      for (auto item : msg.tau_dot) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tau_ext
  {
    if (msg.tau_ext.size() == 0) {
      out << "tau_ext: []";
    } else {
      out << "tau_ext: [";
      size_t pending_items = msg.tau_ext.size();
      for (auto item : msg.tau_ext) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tcp_pose
  {
    out << "tcp_pose: ";
    to_flow_style_yaml(msg.tcp_pose, out);
    out << ", ";
  }

  // member: tcp_pose_des
  {
    out << "tcp_pose_des: ";
    to_flow_style_yaml(msg.tcp_pose_des, out);
    out << ", ";
  }

  // member: tcp_vel
  {
    out << "tcp_vel: ";
    to_flow_style_yaml(msg.tcp_vel, out);
    out << ", ";
  }

  // member: cam_pose
  {
    out << "cam_pose: ";
    to_flow_style_yaml(msg.cam_pose, out);
    out << ", ";
  }

  // member: flange_pose
  {
    out << "flange_pose: ";
    to_flow_style_yaml(msg.flange_pose, out);
    out << ", ";
  }

  // member: ft_sensor_raw
  {
    out << "ft_sensor_raw: ";
    to_flow_style_yaml(msg.ft_sensor_raw, out);
    out << ", ";
  }

  // member: ext_wrench_tcp_frame
  {
    out << "ext_wrench_tcp_frame: ";
    to_flow_style_yaml(msg.ext_wrench_tcp_frame, out);
    out << ", ";
  }

  // member: ext_wrench_base_frame
  {
    out << "ext_wrench_base_frame: ";
    to_flow_style_yaml(msg.ext_wrench_base_frame, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: q
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.q.size() == 0) {
      out << "q: []\n";
    } else {
      out << "q:\n";
      for (auto item : msg.q) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.theta.size() == 0) {
      out << "theta: []\n";
    } else {
      out << "theta:\n";
      for (auto item : msg.theta) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: dq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dq.size() == 0) {
      out << "dq: []\n";
    } else {
      out << "dq:\n";
      for (auto item : msg.dq) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: dtheta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dtheta.size() == 0) {
      out << "dtheta: []\n";
    } else {
      out << "dtheta:\n";
      for (auto item : msg.dtheta) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tau
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tau.size() == 0) {
      out << "tau: []\n";
    } else {
      out << "tau:\n";
      for (auto item : msg.tau) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tau_des
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tau_des.size() == 0) {
      out << "tau_des: []\n";
    } else {
      out << "tau_des:\n";
      for (auto item : msg.tau_des) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tau_dot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tau_dot.size() == 0) {
      out << "tau_dot: []\n";
    } else {
      out << "tau_dot:\n";
      for (auto item : msg.tau_dot) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tau_ext
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tau_ext.size() == 0) {
      out << "tau_ext: []\n";
    } else {
      out << "tau_ext:\n";
      for (auto item : msg.tau_ext) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tcp_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tcp_pose:\n";
    to_block_style_yaml(msg.tcp_pose, out, indentation + 2);
  }

  // member: tcp_pose_des
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tcp_pose_des:\n";
    to_block_style_yaml(msg.tcp_pose_des, out, indentation + 2);
  }

  // member: tcp_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tcp_vel:\n";
    to_block_style_yaml(msg.tcp_vel, out, indentation + 2);
  }

  // member: cam_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cam_pose:\n";
    to_block_style_yaml(msg.cam_pose, out, indentation + 2);
  }

  // member: flange_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flange_pose:\n";
    to_block_style_yaml(msg.flange_pose, out, indentation + 2);
  }

  // member: ft_sensor_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ft_sensor_raw:\n";
    to_block_style_yaml(msg.ft_sensor_raw, out, indentation + 2);
  }

  // member: ext_wrench_tcp_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ext_wrench_tcp_frame:\n";
    to_block_style_yaml(msg.ext_wrench_tcp_frame, out, indentation + 2);
  }

  // member: ext_wrench_base_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ext_wrench_base_frame:\n";
    to_block_style_yaml(msg.ext_wrench_base_frame, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStates & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace flexiv_msgs

namespace rosidl_generator_traits
{

[[deprecated("use flexiv_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const flexiv_msgs::msg::RobotStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  flexiv_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flexiv_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const flexiv_msgs::msg::RobotStates & msg)
{
  return flexiv_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flexiv_msgs::msg::RobotStates>()
{
  return "flexiv_msgs::msg::RobotStates";
}

template<>
inline const char * name<flexiv_msgs::msg::RobotStates>()
{
  return "flexiv_msgs/msg/RobotStates";
}

template<>
struct has_fixed_size<flexiv_msgs::msg::RobotStates>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Accel>::value && has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<geometry_msgs::msg::Wrench>::value> {};

template<>
struct has_bounded_size<flexiv_msgs::msg::RobotStates>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Accel>::value && has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<geometry_msgs::msg::Wrench>::value> {};

template<>
struct is_message<flexiv_msgs::msg::RobotStates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLEXIV_MSGS__MSG__DETAIL__ROBOT_STATES__TRAITS_HPP_
