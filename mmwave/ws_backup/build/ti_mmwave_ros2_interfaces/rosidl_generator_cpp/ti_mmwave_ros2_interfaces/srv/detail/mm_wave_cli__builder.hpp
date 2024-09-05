// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ti_mmwave_ros2_interfaces:srv/MMWaveCLI.idl
// generated code does not contain a copyright notice

#ifndef TI_MMWAVE_ROS2_INTERFACES__SRV__DETAIL__MM_WAVE_CLI__BUILDER_HPP_
#define TI_MMWAVE_ROS2_INTERFACES__SRV__DETAIL__MM_WAVE_CLI__BUILDER_HPP_

#include "ti_mmwave_ros2_interfaces/srv/detail/mm_wave_cli__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ti_mmwave_ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_MMWaveCLI_Request_comm
{
public:
  Init_MMWaveCLI_Request_comm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request comm(::ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request::_comm_type arg)
  {
    msg_.comm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request>()
{
  return ti_mmwave_ros2_interfaces::srv::builder::Init_MMWaveCLI_Request_comm();
}

}  // namespace ti_mmwave_ros2_interfaces


namespace ti_mmwave_ros2_interfaces
{

namespace srv
{

namespace builder
{

class Init_MMWaveCLI_Response_resp
{
public:
  Init_MMWaveCLI_Response_resp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response resp(::ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response::_resp_type arg)
  {
    msg_.resp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response>()
{
  return ti_mmwave_ros2_interfaces::srv::builder::Init_MMWaveCLI_Response_resp();
}

}  // namespace ti_mmwave_ros2_interfaces

#endif  // TI_MMWAVE_ROS2_INTERFACES__SRV__DETAIL__MM_WAVE_CLI__BUILDER_HPP_
