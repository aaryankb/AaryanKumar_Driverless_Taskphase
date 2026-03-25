// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rt2_msgs:msg/PalCheck.idl
// generated code does not contain a copyright notice
#include "rt2_msgs/msg/detail/pal_check__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rt2_msgs__msg__PalCheck__init(rt2_msgs__msg__PalCheck * msg)
{
  if (!msg) {
    return false;
  }
  // data
  return true;
}

void
rt2_msgs__msg__PalCheck__fini(rt2_msgs__msg__PalCheck * msg)
{
  if (!msg) {
    return;
  }
  // data
}

bool
rt2_msgs__msg__PalCheck__are_equal(const rt2_msgs__msg__PalCheck * lhs, const rt2_msgs__msg__PalCheck * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (lhs->data != rhs->data) {
    return false;
  }
  return true;
}

bool
rt2_msgs__msg__PalCheck__copy(
  const rt2_msgs__msg__PalCheck * input,
  rt2_msgs__msg__PalCheck * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  output->data = input->data;
  return true;
}

rt2_msgs__msg__PalCheck *
rt2_msgs__msg__PalCheck__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rt2_msgs__msg__PalCheck * msg = (rt2_msgs__msg__PalCheck *)allocator.allocate(sizeof(rt2_msgs__msg__PalCheck), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rt2_msgs__msg__PalCheck));
  bool success = rt2_msgs__msg__PalCheck__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rt2_msgs__msg__PalCheck__destroy(rt2_msgs__msg__PalCheck * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rt2_msgs__msg__PalCheck__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rt2_msgs__msg__PalCheck__Sequence__init(rt2_msgs__msg__PalCheck__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rt2_msgs__msg__PalCheck * data = NULL;

  if (size) {
    data = (rt2_msgs__msg__PalCheck *)allocator.zero_allocate(size, sizeof(rt2_msgs__msg__PalCheck), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rt2_msgs__msg__PalCheck__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rt2_msgs__msg__PalCheck__fini(&data[i - 1]);
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
rt2_msgs__msg__PalCheck__Sequence__fini(rt2_msgs__msg__PalCheck__Sequence * array)
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
      rt2_msgs__msg__PalCheck__fini(&array->data[i]);
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

rt2_msgs__msg__PalCheck__Sequence *
rt2_msgs__msg__PalCheck__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rt2_msgs__msg__PalCheck__Sequence * array = (rt2_msgs__msg__PalCheck__Sequence *)allocator.allocate(sizeof(rt2_msgs__msg__PalCheck__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rt2_msgs__msg__PalCheck__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rt2_msgs__msg__PalCheck__Sequence__destroy(rt2_msgs__msg__PalCheck__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rt2_msgs__msg__PalCheck__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rt2_msgs__msg__PalCheck__Sequence__are_equal(const rt2_msgs__msg__PalCheck__Sequence * lhs, const rt2_msgs__msg__PalCheck__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rt2_msgs__msg__PalCheck__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rt2_msgs__msg__PalCheck__Sequence__copy(
  const rt2_msgs__msg__PalCheck__Sequence * input,
  rt2_msgs__msg__PalCheck__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rt2_msgs__msg__PalCheck);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rt2_msgs__msg__PalCheck * data =
      (rt2_msgs__msg__PalCheck *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rt2_msgs__msg__PalCheck__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rt2_msgs__msg__PalCheck__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rt2_msgs__msg__PalCheck__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
