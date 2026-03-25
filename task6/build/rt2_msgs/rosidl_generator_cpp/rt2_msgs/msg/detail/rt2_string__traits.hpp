// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rt2_msgs:msg/RT2String.idl
// generated code does not contain a copyright notice

#ifndef RT2_MSGS__MSG__DETAIL__RT2_STRING__TRAITS_HPP_
#define RT2_MSGS__MSG__DETAIL__RT2_STRING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rt2_msgs/msg/detail/rt2_string__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rt2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RT2String & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RT2String & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RT2String & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rt2_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rt2_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rt2_msgs::msg::RT2String & msg,
  std::ostream & out, size_t indentation = 0)
{
  rt2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rt2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rt2_msgs::msg::RT2String & msg)
{
  return rt2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rt2_msgs::msg::RT2String>()
{
  return "rt2_msgs::msg::RT2String";
}

template<>
inline const char * name<rt2_msgs::msg::RT2String>()
{
  return "rt2_msgs/msg/RT2String";
}

template<>
struct has_fixed_size<rt2_msgs::msg::RT2String>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rt2_msgs::msg::RT2String>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rt2_msgs::msg::RT2String>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RT2_MSGS__MSG__DETAIL__RT2_STRING__TRAITS_HPP_
