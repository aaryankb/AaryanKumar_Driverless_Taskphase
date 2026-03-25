// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rt2_msgs:msg/PalCheck.idl
// generated code does not contain a copyright notice

#ifndef RT2_MSGS__MSG__DETAIL__PAL_CHECK__STRUCT_HPP_
#define RT2_MSGS__MSG__DETAIL__PAL_CHECK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rt2_msgs__msg__PalCheck __attribute__((deprecated))
#else
# define DEPRECATED__rt2_msgs__msg__PalCheck __declspec(deprecated)
#endif

namespace rt2_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PalCheck_
{
  using Type = PalCheck_<ContainerAllocator>;

  explicit PalCheck_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = 0;
    }
  }

  explicit PalCheck_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = 0;
    }
  }

  // field types and members
  using _data_type =
    int8_t;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const int8_t & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rt2_msgs::msg::PalCheck_<ContainerAllocator> *;
  using ConstRawPtr =
    const rt2_msgs::msg::PalCheck_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rt2_msgs::msg::PalCheck_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rt2_msgs::msg::PalCheck_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rt2_msgs::msg::PalCheck_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rt2_msgs::msg::PalCheck_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rt2_msgs::msg::PalCheck_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rt2_msgs::msg::PalCheck_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rt2_msgs::msg::PalCheck_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rt2_msgs::msg::PalCheck_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rt2_msgs__msg__PalCheck
    std::shared_ptr<rt2_msgs::msg::PalCheck_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rt2_msgs__msg__PalCheck
    std::shared_ptr<rt2_msgs::msg::PalCheck_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PalCheck_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const PalCheck_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PalCheck_

// alias to use template instance with default allocator
using PalCheck =
  rt2_msgs::msg::PalCheck_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rt2_msgs

#endif  // RT2_MSGS__MSG__DETAIL__PAL_CHECK__STRUCT_HPP_
