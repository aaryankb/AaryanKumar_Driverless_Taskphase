// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rt2_msgs:msg/RT2String.idl
// generated code does not contain a copyright notice
#include "rt2_msgs/msg/detail/rt2_string__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/string_functions.h"

bool
rt2_msgs__msg__RT2String__init(rt2_msgs__msg__RT2String * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__init(&msg->data)) {
    rt2_msgs__msg__RT2String__fini(msg);
    return false;
  }
  return true;
}

void
rt2_msgs__msg__RT2String__fini(rt2_msgs__msg__RT2String * msg)
{
  if (!msg) {
    return;
  }
  // data
  rosidl_runtime_c__String__fini(&msg->data);
}

bool
rt2_msgs__msg__RT2String__are_equal(const rt2_msgs__msg__RT2String * lhs, const rt2_msgs__msg__RT2String * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
rt2_msgs__msg__RT2String__copy(
  const rt2_msgs__msg__RT2String * input,
  rt2_msgs__msg__RT2String * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

rt2_msgs__msg__RT2String *
rt2_msgs__msg__RT2String__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rt2_msgs__msg__RT2String * msg = (rt2_msgs__msg__RT2String *)allocator.allocate(sizeof(rt2_msgs__msg__RT2String), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rt2_msgs__msg__RT2String));
  bool success = rt2_msgs__msg__RT2String__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rt2_msgs__msg__RT2String__destroy(rt2_msgs__msg__RT2String * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rt2_msgs__msg__RT2String__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rt2_msgs__msg__RT2String__Sequence__init(rt2_msgs__msg__RT2String__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rt2_msgs__msg__RT2String * data = NULL;

  if (size) {
    data = (rt2_msgs__msg__RT2String *)allocator.zero_allocate(size, sizeof(rt2_msgs__msg__RT2String), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rt2_msgs__msg__RT2String__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rt2_msgs__msg__RT2String__fini(&data[i - 1]);
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
rt2_msgs__msg__RT2String__Sequence__fini(rt2_msgs__msg__RT2String__Sequence * array)
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
      rt2_msgs__msg__RT2String__fini(&array->data[i]);
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

rt2_msgs__msg__RT2String__Sequence *
rt2_msgs__msg__RT2String__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rt2_msgs__msg__RT2String__Sequence * array = (rt2_msgs__msg__RT2String__Sequence *)allocator.allocate(sizeof(rt2_msgs__msg__RT2String__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rt2_msgs__msg__RT2String__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rt2_msgs__msg__RT2String__Sequence__destroy(rt2_msgs__msg__RT2String__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rt2_msgs__msg__RT2String__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rt2_msgs__msg__RT2String__Sequence__are_equal(const rt2_msgs__msg__RT2String__Sequence * lhs, const rt2_msgs__msg__RT2String__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rt2_msgs__msg__RT2String__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rt2_msgs__msg__RT2String__Sequence__copy(
  const rt2_msgs__msg__RT2String__Sequence * input,
  rt2_msgs__msg__RT2String__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rt2_msgs__msg__RT2String);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rt2_msgs__msg__RT2String * data =
      (rt2_msgs__msg__RT2String *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rt2_msgs__msg__RT2String__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rt2_msgs__msg__RT2String__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rt2_msgs__msg__RT2String__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
