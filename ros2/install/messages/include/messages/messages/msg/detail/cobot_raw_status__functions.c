// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/CobotRawStatus.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/cobot_raw_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
messages__msg__CobotRawStatus__init(messages__msg__CobotRawStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    messages__msg__CobotRawStatus__fini(msg);
    return false;
  }
  // dr
  // dx
  // dy
  // v0
  // v1
  // v2
  // v3
  // vr
  // vx
  // vy
  // v_batt
  // status
  return true;
}

void
messages__msg__CobotRawStatus__fini(messages__msg__CobotRawStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // dr
  // dx
  // dy
  // v0
  // v1
  // v2
  // v3
  // vr
  // vx
  // vy
  // v_batt
  // status
}

bool
messages__msg__CobotRawStatus__are_equal(const messages__msg__CobotRawStatus * lhs, const messages__msg__CobotRawStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // dr
  if (lhs->dr != rhs->dr) {
    return false;
  }
  // dx
  if (lhs->dx != rhs->dx) {
    return false;
  }
  // dy
  if (lhs->dy != rhs->dy) {
    return false;
  }
  // v0
  if (lhs->v0 != rhs->v0) {
    return false;
  }
  // v1
  if (lhs->v1 != rhs->v1) {
    return false;
  }
  // v2
  if (lhs->v2 != rhs->v2) {
    return false;
  }
  // v3
  if (lhs->v3 != rhs->v3) {
    return false;
  }
  // vr
  if (lhs->vr != rhs->vr) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // v_batt
  if (lhs->v_batt != rhs->v_batt) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  return true;
}

bool
messages__msg__CobotRawStatus__copy(
  const messages__msg__CobotRawStatus * input,
  messages__msg__CobotRawStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // dr
  output->dr = input->dr;
  // dx
  output->dx = input->dx;
  // dy
  output->dy = input->dy;
  // v0
  output->v0 = input->v0;
  // v1
  output->v1 = input->v1;
  // v2
  output->v2 = input->v2;
  // v3
  output->v3 = input->v3;
  // vr
  output->vr = input->vr;
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // v_batt
  output->v_batt = input->v_batt;
  // status
  output->status = input->status;
  return true;
}

messages__msg__CobotRawStatus *
messages__msg__CobotRawStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__CobotRawStatus * msg = (messages__msg__CobotRawStatus *)allocator.allocate(sizeof(messages__msg__CobotRawStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__CobotRawStatus));
  bool success = messages__msg__CobotRawStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__CobotRawStatus__destroy(messages__msg__CobotRawStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__CobotRawStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__CobotRawStatus__Sequence__init(messages__msg__CobotRawStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__CobotRawStatus * data = NULL;

  if (size) {
    data = (messages__msg__CobotRawStatus *)allocator.zero_allocate(size, sizeof(messages__msg__CobotRawStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__CobotRawStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__CobotRawStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
messages__msg__CobotRawStatus__Sequence__fini(messages__msg__CobotRawStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      messages__msg__CobotRawStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

messages__msg__CobotRawStatus__Sequence *
messages__msg__CobotRawStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__CobotRawStatus__Sequence * array = (messages__msg__CobotRawStatus__Sequence *)allocator.allocate(sizeof(messages__msg__CobotRawStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__CobotRawStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__CobotRawStatus__Sequence__destroy(messages__msg__CobotRawStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__CobotRawStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__CobotRawStatus__Sequence__are_equal(const messages__msg__CobotRawStatus__Sequence * lhs, const messages__msg__CobotRawStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__CobotRawStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__CobotRawStatus__Sequence__copy(
  const messages__msg__CobotRawStatus__Sequence * input,
  messages__msg__CobotRawStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__CobotRawStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__CobotRawStatus * data =
      (messages__msg__CobotRawStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__CobotRawStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__CobotRawStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__CobotRawStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
