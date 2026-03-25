// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rt2_msgs:msg/PalCheck.idl
// generated code does not contain a copyright notice

#ifndef RT2_MSGS__MSG__DETAIL__PAL_CHECK__STRUCT_H_
#define RT2_MSGS__MSG__DETAIL__PAL_CHECK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PalCheck in the package rt2_msgs.
typedef struct rt2_msgs__msg__PalCheck
{
  int8_t data;
} rt2_msgs__msg__PalCheck;

// Struct for a sequence of rt2_msgs__msg__PalCheck.
typedef struct rt2_msgs__msg__PalCheck__Sequence
{
  rt2_msgs__msg__PalCheck * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rt2_msgs__msg__PalCheck__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RT2_MSGS__MSG__DETAIL__PAL_CHECK__STRUCT_H_
