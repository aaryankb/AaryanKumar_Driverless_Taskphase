// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rt2_msgs:msg/RT2String.idl
// generated code does not contain a copyright notice

#ifndef RT2_MSGS__MSG__DETAIL__RT2_STRING__STRUCT_H_
#define RT2_MSGS__MSG__DETAIL__RT2_STRING__STRUCT_H_

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

/// Struct defined in msg/RT2String in the package rt2_msgs.
typedef struct rt2_msgs__msg__RT2String
{
  rosidl_runtime_c__String data;
} rt2_msgs__msg__RT2String;

// Struct for a sequence of rt2_msgs__msg__RT2String.
typedef struct rt2_msgs__msg__RT2String__Sequence
{
  rt2_msgs__msg__RT2String * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rt2_msgs__msg__RT2String__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RT2_MSGS__MSG__DETAIL__RT2_STRING__STRUCT_H_
