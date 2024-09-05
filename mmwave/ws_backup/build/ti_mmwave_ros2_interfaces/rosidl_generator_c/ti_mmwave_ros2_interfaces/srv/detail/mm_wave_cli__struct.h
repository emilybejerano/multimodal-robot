// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ti_mmwave_ros2_interfaces:srv/MMWaveCLI.idl
// generated code does not contain a copyright notice

#ifndef TI_MMWAVE_ROS2_INTERFACES__SRV__DETAIL__MM_WAVE_CLI__STRUCT_H_
#define TI_MMWAVE_ROS2_INTERFACES__SRV__DETAIL__MM_WAVE_CLI__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'comm'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/MMWaveCLI in the package ti_mmwave_ros2_interfaces.
typedef struct ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request
{
  rosidl_runtime_c__String comm;
} ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request;

// Struct for a sequence of ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request.
typedef struct ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence
{
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'resp'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/MMWaveCLI in the package ti_mmwave_ros2_interfaces.
typedef struct ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response
{
  rosidl_runtime_c__String resp;
} ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response;

// Struct for a sequence of ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response.
typedef struct ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence
{
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TI_MMWAVE_ROS2_INTERFACES__SRV__DETAIL__MM_WAVE_CLI__STRUCT_H_
