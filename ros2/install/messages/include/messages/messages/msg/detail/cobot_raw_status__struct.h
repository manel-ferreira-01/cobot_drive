// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/CobotRawStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__STRUCT_H_
#define MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/CobotRawStatus in the package messages.
typedef struct messages__msg__CobotRawStatus
{
  std_msgs__msg__Header header;
  float dr;
  float dx;
  float dy;
  float v0;
  float v1;
  float v2;
  float v3;
  float vr;
  float vx;
  float vy;
  float v_batt;
  int32_t status;
} messages__msg__CobotRawStatus;

// Struct for a sequence of messages__msg__CobotRawStatus.
typedef struct messages__msg__CobotRawStatus__Sequence
{
  messages__msg__CobotRawStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__CobotRawStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__COBOT_RAW_STATUS__STRUCT_H_
