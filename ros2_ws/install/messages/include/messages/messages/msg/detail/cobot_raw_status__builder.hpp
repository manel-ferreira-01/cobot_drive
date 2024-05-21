// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/CobotRawStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/cobot_raw_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_CobotRawStatus_status
{
public:
  explicit Init_CobotRawStatus_status(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  ::messages::msg::CobotRawStatus status(::messages::msg::CobotRawStatus::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_v_batt
{
public:
  explicit Init_CobotRawStatus_v_batt(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_status v_batt(::messages::msg::CobotRawStatus::_v_batt_type arg)
  {
    msg_.v_batt = std::move(arg);
    return Init_CobotRawStatus_status(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_vy
{
public:
  explicit Init_CobotRawStatus_vy(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_v_batt vy(::messages::msg::CobotRawStatus::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_CobotRawStatus_v_batt(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_vx
{
public:
  explicit Init_CobotRawStatus_vx(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_vy vx(::messages::msg::CobotRawStatus::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_CobotRawStatus_vy(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_vr
{
public:
  explicit Init_CobotRawStatus_vr(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_vx vr(::messages::msg::CobotRawStatus::_vr_type arg)
  {
    msg_.vr = std::move(arg);
    return Init_CobotRawStatus_vx(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_v3
{
public:
  explicit Init_CobotRawStatus_v3(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_vr v3(::messages::msg::CobotRawStatus::_v3_type arg)
  {
    msg_.v3 = std::move(arg);
    return Init_CobotRawStatus_vr(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_v2
{
public:
  explicit Init_CobotRawStatus_v2(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_v3 v2(::messages::msg::CobotRawStatus::_v2_type arg)
  {
    msg_.v2 = std::move(arg);
    return Init_CobotRawStatus_v3(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_v1
{
public:
  explicit Init_CobotRawStatus_v1(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_v2 v1(::messages::msg::CobotRawStatus::_v1_type arg)
  {
    msg_.v1 = std::move(arg);
    return Init_CobotRawStatus_v2(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_v0
{
public:
  explicit Init_CobotRawStatus_v0(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_v1 v0(::messages::msg::CobotRawStatus::_v0_type arg)
  {
    msg_.v0 = std::move(arg);
    return Init_CobotRawStatus_v1(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_dy
{
public:
  explicit Init_CobotRawStatus_dy(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_v0 dy(::messages::msg::CobotRawStatus::_dy_type arg)
  {
    msg_.dy = std::move(arg);
    return Init_CobotRawStatus_v0(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_dx
{
public:
  explicit Init_CobotRawStatus_dx(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_dy dx(::messages::msg::CobotRawStatus::_dx_type arg)
  {
    msg_.dx = std::move(arg);
    return Init_CobotRawStatus_dy(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_dr
{
public:
  explicit Init_CobotRawStatus_dr(::messages::msg::CobotRawStatus & msg)
  : msg_(msg)
  {}
  Init_CobotRawStatus_dx dr(::messages::msg::CobotRawStatus::_dr_type arg)
  {
    msg_.dr = std::move(arg);
    return Init_CobotRawStatus_dx(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

class Init_CobotRawStatus_header
{
public:
  Init_CobotRawStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CobotRawStatus_dr header(::messages::msg::CobotRawStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CobotRawStatus_dr(msg_);
  }

private:
  ::messages::msg::CobotRawStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::CobotRawStatus>()
{
  return messages::msg::builder::Init_CobotRawStatus_header();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__BUILDER_HPP_
