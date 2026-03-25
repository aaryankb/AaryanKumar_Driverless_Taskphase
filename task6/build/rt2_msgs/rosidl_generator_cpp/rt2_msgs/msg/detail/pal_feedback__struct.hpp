// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rt2_msgs:msg/PalFeedback.idl
// generated code does not contain a copyright notice

#ifndef RT2_MSGS__MSG__DETAIL__PAL_FEEDBACK__STRUCT_HPP_
#define RT2_MSGS__MSG__DETAIL__PAL_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rt2_msgs__msg__PalFeedback __attribute__((deprecated))
#else
# define DEPRECATED__rt2_msgs__msg__PalFeedback __declspec(deprecated)
#endif

namespace rt2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PalFeedback_
{
  using Type = PalFeedback_<ContainerAllocator>;

  explicit PalFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = "";
    }
  }

  explicit PalFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = "";
    }
  }

  // field types and members
  using _data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rt2_msgs::msg::PalFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const rt2_msgs::msg::PalFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rt2_msgs::msg::PalFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rt2_msgs::msg::PalFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rt2_msgs::msg::PalFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rt2_msgs::msg::PalFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rt2_msgs::msg::PalFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rt2_msgs::msg::PalFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rt2_msgs::msg::PalFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rt2_msgs::msg::PalFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rt2_msgs__msg__PalFeedback
    std::shared_ptr<rt2_msgs::msg::PalFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rt2_msgs__msg__PalFeedback
    std::shared_ptr<rt2_msgs::msg::PalFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PalFeedback_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const PalFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PalFeedback_

// alias to use template instance with default allocator
using PalFeedback =
  rt2_msgs::msg::PalFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rt2_msgs

#endif  // RT2_MSGS__MSG__DETAIL__PAL_FEEDBACK__STRUCT_HPP_
