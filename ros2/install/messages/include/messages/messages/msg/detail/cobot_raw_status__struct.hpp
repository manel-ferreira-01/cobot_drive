// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/CobotRawStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__messages__msg__CobotRawStatus __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__CobotRawStatus __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CobotRawStatus_
{
  using Type = CobotRawStatus_<ContainerAllocator>;

  explicit CobotRawStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dr = 0.0f;
      this->dx = 0.0f;
      this->dy = 0.0f;
      this->v0 = 0.0f;
      this->v1 = 0.0f;
      this->v2 = 0.0f;
      this->v3 = 0.0f;
      this->vr = 0.0f;
      this->vx = 0.0f;
      this->vy = 0.0f;
      this->v_batt = 0.0f;
      this->status = 0l;
    }
  }

  explicit CobotRawStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dr = 0.0f;
      this->dx = 0.0f;
      this->dy = 0.0f;
      this->v0 = 0.0f;
      this->v1 = 0.0f;
      this->v2 = 0.0f;
      this->v3 = 0.0f;
      this->vr = 0.0f;
      this->vx = 0.0f;
      this->vy = 0.0f;
      this->v_batt = 0.0f;
      this->status = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _dr_type =
    float;
  _dr_type dr;
  using _dx_type =
    float;
  _dx_type dx;
  using _dy_type =
    float;
  _dy_type dy;
  using _v0_type =
    float;
  _v0_type v0;
  using _v1_type =
    float;
  _v1_type v1;
  using _v2_type =
    float;
  _v2_type v2;
  using _v3_type =
    float;
  _v3_type v3;
  using _vr_type =
    float;
  _vr_type vr;
  using _vx_type =
    float;
  _vx_type vx;
  using _vy_type =
    float;
  _vy_type vy;
  using _v_batt_type =
    float;
  _v_batt_type v_batt;
  using _status_type =
    int32_t;
  _status_type status;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__dr(
    const float & _arg)
  {
    this->dr = _arg;
    return *this;
  }
  Type & set__dx(
    const float & _arg)
  {
    this->dx = _arg;
    return *this;
  }
  Type & set__dy(
    const float & _arg)
  {
    this->dy = _arg;
    return *this;
  }
  Type & set__v0(
    const float & _arg)
  {
    this->v0 = _arg;
    return *this;
  }
  Type & set__v1(
    const float & _arg)
  {
    this->v1 = _arg;
    return *this;
  }
  Type & set__v2(
    const float & _arg)
  {
    this->v2 = _arg;
    return *this;
  }
  Type & set__v3(
    const float & _arg)
  {
    this->v3 = _arg;
    return *this;
  }
  Type & set__vr(
    const float & _arg)
  {
    this->vr = _arg;
    return *this;
  }
  Type & set__vx(
    const float & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const float & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__v_batt(
    const float & _arg)
  {
    this->v_batt = _arg;
    return *this;
  }
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::CobotRawStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::CobotRawStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::CobotRawStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::CobotRawStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::CobotRawStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::CobotRawStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::CobotRawStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::CobotRawStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::CobotRawStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::CobotRawStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__CobotRawStatus
    std::shared_ptr<messages::msg::CobotRawStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__CobotRawStatus
    std::shared_ptr<messages::msg::CobotRawStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CobotRawStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->dr != other.dr) {
      return false;
    }
    if (this->dx != other.dx) {
      return false;
    }
    if (this->dy != other.dy) {
      return false;
    }
    if (this->v0 != other.v0) {
      return false;
    }
    if (this->v1 != other.v1) {
      return false;
    }
    if (this->v2 != other.v2) {
      return false;
    }
    if (this->v3 != other.v3) {
      return false;
    }
    if (this->vr != other.vr) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->v_batt != other.v_batt) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const CobotRawStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CobotRawStatus_

// alias to use template instance with default allocator
using CobotRawStatus =
  messages::msg::CobotRawStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__STRUCT_HPP_
