// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rt2_msgs:msg/RT2String.idl
// generated code does not contain a copyright notice

#ifndef RT2_MSGS__MSG__DETAIL__RT2_STRING__FUNCTIONS_H_
#define RT2_MSGS__MSG__DETAIL__RT2_STRING__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rt2_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rt2_msgs/msg/detail/rt2_string__struct.h"

/// Initialize msg/RT2String message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rt2_msgs__msg__RT2String
 * )) before or use
 * rt2_msgs__msg__RT2String__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
bool
rt2_msgs__msg__RT2String__init(rt2_msgs__msg__RT2String * msg);

/// Finalize msg/RT2String message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
void
rt2_msgs__msg__RT2String__fini(rt2_msgs__msg__RT2String * msg);

/// Create msg/RT2String message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rt2_msgs__msg__RT2String__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
rt2_msgs__msg__RT2String *
rt2_msgs__msg__RT2String__create();

/// Destroy msg/RT2String message.
/**
 * It calls
 * rt2_msgs__msg__RT2String__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
void
rt2_msgs__msg__RT2String__destroy(rt2_msgs__msg__RT2String * msg);

/// Check for msg/RT2String message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
bool
rt2_msgs__msg__RT2String__are_equal(const rt2_msgs__msg__RT2String * lhs, const rt2_msgs__msg__RT2String * rhs);

/// Copy a msg/RT2String message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
bool
rt2_msgs__msg__RT2String__copy(
  const rt2_msgs__msg__RT2String * input,
  rt2_msgs__msg__RT2String * output);

/// Initialize array of msg/RT2String messages.
/**
 * It allocates the memory for the number of elements and calls
 * rt2_msgs__msg__RT2String__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
bool
rt2_msgs__msg__RT2String__Sequence__init(rt2_msgs__msg__RT2String__Sequence * array, size_t size);

/// Finalize array of msg/RT2String messages.
/**
 * It calls
 * rt2_msgs__msg__RT2String__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
void
rt2_msgs__msg__RT2String__Sequence__fini(rt2_msgs__msg__RT2String__Sequence * array);

/// Create array of msg/RT2String messages.
/**
 * It allocates the memory for the array and calls
 * rt2_msgs__msg__RT2String__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
rt2_msgs__msg__RT2String__Sequence *
rt2_msgs__msg__RT2String__Sequence__create(size_t size);

/// Destroy array of msg/RT2String messages.
/**
 * It calls
 * rt2_msgs__msg__RT2String__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
void
rt2_msgs__msg__RT2String__Sequence__destroy(rt2_msgs__msg__RT2String__Sequence * array);

/// Check for msg/RT2String message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
bool
rt2_msgs__msg__RT2String__Sequence__are_equal(const rt2_msgs__msg__RT2String__Sequence * lhs, const rt2_msgs__msg__RT2String__Sequence * rhs);

/// Copy an array of msg/RT2String messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rt2_msgs
bool
rt2_msgs__msg__RT2String__Sequence__copy(
  const rt2_msgs__msg__RT2String__Sequence * input,
  rt2_msgs__msg__RT2String__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RT2_MSGS__MSG__DETAIL__RT2_STRING__FUNCTIONS_H_
