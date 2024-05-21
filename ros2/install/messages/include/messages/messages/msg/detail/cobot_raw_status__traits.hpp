// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/CobotRawStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/cobot_raw_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const CobotRawStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: dr
  {
    out << "dr: ";
    rosidl_generator_traits::value_to_yaml(msg.dr, out);
    out << ", ";
  }

  // member: dx
  {
    out << "dx: ";
    rosidl_generator_traits::value_to_yaml(msg.dx, out);
    out << ", ";
  }

  // member: dy
  {
    out << "dy: ";
    rosidl_generator_traits::value_to_yaml(msg.dy, out);
    out << ", ";
  }

  // member: v0
  {
    out << "v0: ";
    rosidl_generator_traits::value_to_yaml(msg.v0, out);
    out << ", ";
  }

  // member: v1
  {
    out << "v1: ";
    rosidl_generator_traits::value_to_yaml(msg.v1, out);
    out << ", ";
  }

  // member: v2
  {
    out << "v2: ";
    rosidl_generator_traits::value_to_yaml(msg.v2, out);
    out << ", ";
  }

  // member: v3
  {
    out << "v3: ";
    rosidl_generator_traits::value_to_yaml(msg.v3, out);
    out << ", ";
  }

  // member: vr
  {
    out << "vr: ";
    rosidl_generator_traits::value_to_yaml(msg.vr, out);
    out << ", ";
  }

  // member: vx
  {
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << ", ";
  }

  // member: vy
  {
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << ", ";
  }

  // member: v_batt
  {
    out << "v_batt: ";
    rosidl_generator_traits::value_to_yaml(msg.v_batt, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CobotRawStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: dr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dr: ";
    rosidl_generator_traits::value_to_yaml(msg.dr, out);
    out << "\n";
  }

  // member: dx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dx: ";
    rosidl_generator_traits::value_to_yaml(msg.dx, out);
    out << "\n";
  }

  // member: dy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dy: ";
    rosidl_generator_traits::value_to_yaml(msg.dy, out);
    out << "\n";
  }

  // member: v0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v0: ";
    rosidl_generator_traits::value_to_yaml(msg.v0, out);
    out << "\n";
  }

  // member: v1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v1: ";
    rosidl_generator_traits::value_to_yaml(msg.v1, out);
    out << "\n";
  }

  // member: v2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v2: ";
    rosidl_generator_traits::value_to_yaml(msg.v2, out);
    out << "\n";
  }

  // member: v3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v3: ";
    rosidl_generator_traits::value_to_yaml(msg.v3, out);
    out << "\n";
  }

  // member: vr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vr: ";
    rosidl_generator_traits::value_to_yaml(msg.vr, out);
    out << "\n";
  }

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << "\n";
  }

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << "\n";
  }

  // member: v_batt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_batt: ";
    rosidl_generator_traits::value_to_yaml(msg.v_batt, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CobotRawStatus & msg, bool use_flow_style = false)
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

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::msg::CobotRawStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::CobotRawStatus & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::CobotRawStatus>()
{
  return "messages::msg::CobotRawStatus";
}

template<>
inline const char * name<messages::msg::CobotRawStatus>()
{
  return "messages/msg/CobotRawStatus";
}

template<>
struct has_fixed_size<messages::msg::CobotRawStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<messages::msg::CobotRawStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<messages::msg::CobotRawStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__TRAITS_HPP_
