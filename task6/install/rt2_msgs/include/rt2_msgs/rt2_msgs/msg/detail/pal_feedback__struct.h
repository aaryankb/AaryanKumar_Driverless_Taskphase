// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rt2_msgs:msg/PalFeedback.idl
// generated code does not contain a copyright notice

#ifndef RT2_MSGS__MSG__DETAIL__PAL_FEEDBACK__STRUCT_H_
#define RT2_MSGS__MSG__DETAIL__PAL_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/PalFeedback in the package rt2_msgs.
typedef struct rt2_msgs__msg__PalFeedback
{
  rosidl_runtime_c__String data;
} rt2_msgs__msg__PalFeedback;

// Struct for a sequence of rt2_msgs__msg__PalFeedback.
typedef struct rt2_msgs__msg__PalFeedback__Sequence
{
  rt2_msgs__msg__PalFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rt2_msgs__msg__PalFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RT2_MSGS__MSG__DETAIL__PAL_FEEDBACK__STRUCT_H_
