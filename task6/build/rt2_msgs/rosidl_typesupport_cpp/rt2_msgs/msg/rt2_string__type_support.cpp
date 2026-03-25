// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from rt2_msgs:msg/RT2String.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rt2_msgs/msg/detail/rt2_string__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace rt2_msgs
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _RT2String_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RT2String_type_support_ids_t;

static const _RT2String_type_support_ids_t _RT2String_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _RT2String_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RT2String_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RT2String_type_support_symbol_names_t _RT2String_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rt2_msgs, msg, RT2String)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rt2_msgs, msg, RT2String)),
  }
};

typedef struct _RT2String_type_support_data_t
{
  void * data[2];
} _RT2String_type_support_data_t;

static _RT2String_type_support_data_t _RT2String_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RT2String_message_typesupport_map = {
  2,
  "rt2_msgs",
  &_RT2String_message_typesupport_ids.typesupport_identifier[0],
  &_RT2String_message_typesupport_symbol_names.symbol_name[0],
  &_RT2String_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RT2String_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RT2String_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace rt2_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rt2_msgs::msg::RT2String>()
{
  return &::rt2_msgs::msg::rosidl_typesupport_cpp::RT2String_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, rt2_msgs, msg, RT2String)() {
  return get_message_type_support_handle<rt2_msgs::msg::RT2String>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
