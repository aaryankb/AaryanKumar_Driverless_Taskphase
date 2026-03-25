// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rt2_msgs:msg/PalCheck.idl
// generated code does not contain a copyright notice

#ifndef RT2_MSGS__MSG__DETAIL__PAL_CHECK__BUILDER_HPP_
#define RT2_MSGS__MSG__DETAIL__PAL_CHECK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rt2_msgs/msg/detail/pal_check__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rt2_msgs
{

namespace msg
{

namespace builder
{

class Init_PalCheck_data
{
public:
  Init_PalCheck_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rt2_msgs::msg::PalCheck data(::rt2_msgs::msg::PalCheck::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rt2_msgs::msg::PalCheck msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rt2_msgs::msg::PalCheck>()
{
  return rt2_msgs::msg::builder::Init_PalCheck_data();
}

}  // namespace rt2_msgs

#endif  // RT2_MSGS__MSG__DETAIL__PAL_CHECK__BUILDER_HPP_
