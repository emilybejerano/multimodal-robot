// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ti_mmwave_ros2_interfaces:srv/MMWaveCLI.idl
// generated code does not contain a copyright notice
#include "ti_mmwave_ros2_interfaces/srv/detail/mm_wave_cli__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ti_mmwave_ros2_interfaces/srv/detail/mm_wave_cli__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ti_mmwave_ros2_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ti_mmwave_ros2_interfaces
cdr_serialize(
  const ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: comm
  cdr << ros_message.comm;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ti_mmwave_ros2_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request & ros_message)
{
  // Member: comm
  cdr >> ros_message.comm;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ti_mmwave_ros2_interfaces
get_serialized_size(
  const ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: comm
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.comm.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ti_mmwave_ros2_interfaces
max_serialized_size_MMWaveCLI_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: comm
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _MMWaveCLI_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MMWaveCLI_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MMWaveCLI_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MMWaveCLI_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MMWaveCLI_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _MMWaveCLI_Request__callbacks = {
  "ti_mmwave_ros2_interfaces::srv",
  "MMWaveCLI_Request",
  _MMWaveCLI_Request__cdr_serialize,
  _MMWaveCLI_Request__cdr_deserialize,
  _MMWaveCLI_Request__get_serialized_size,
  _MMWaveCLI_Request__max_serialized_size
};

static rosidl_message_type_support_t _MMWaveCLI_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MMWaveCLI_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ti_mmwave_ros2_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ti_mmwave_ros2_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Request>()
{
  return &ti_mmwave_ros2_interfaces::srv::typesupport_fastrtps_cpp::_MMWaveCLI_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ti_mmwave_ros2_interfaces, srv, MMWaveCLI_Request)() {
  return &ti_mmwave_ros2_interfaces::srv::typesupport_fastrtps_cpp::_MMWaveCLI_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ti_mmwave_ros2_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ti_mmwave_ros2_interfaces
cdr_serialize(
  const ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: resp
  cdr << ros_message.resp;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ti_mmwave_ros2_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response & ros_message)
{
  // Member: resp
  cdr >> ros_message.resp;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ti_mmwave_ros2_interfaces
get_serialized_size(
  const ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: resp
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.resp.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ti_mmwave_ros2_interfaces
max_serialized_size_MMWaveCLI_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: resp
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _MMWaveCLI_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MMWaveCLI_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MMWaveCLI_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MMWaveCLI_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MMWaveCLI_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _MMWaveCLI_Response__callbacks = {
  "ti_mmwave_ros2_interfaces::srv",
  "MMWaveCLI_Response",
  _MMWaveCLI_Response__cdr_serialize,
  _MMWaveCLI_Response__cdr_deserialize,
  _MMWaveCLI_Response__get_serialized_size,
  _MMWaveCLI_Response__max_serialized_size
};

static rosidl_message_type_support_t _MMWaveCLI_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MMWaveCLI_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ti_mmwave_ros2_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ti_mmwave_ros2_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<ti_mmwave_ros2_interfaces::srv::MMWaveCLI_Response>()
{
  return &ti_mmwave_ros2_interfaces::srv::typesupport_fastrtps_cpp::_MMWaveCLI_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ti_mmwave_ros2_interfaces, srv, MMWaveCLI_Response)() {
  return &ti_mmwave_ros2_interfaces::srv::typesupport_fastrtps_cpp::_MMWaveCLI_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace ti_mmwave_ros2_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _MMWaveCLI__callbacks = {
  "ti_mmwave_ros2_interfaces::srv",
  "MMWaveCLI",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ti_mmwave_ros2_interfaces, srv, MMWaveCLI_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ti_mmwave_ros2_interfaces, srv, MMWaveCLI_Response)(),
};

static rosidl_service_type_support_t _MMWaveCLI__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MMWaveCLI__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ti_mmwave_ros2_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ti_mmwave_ros2_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<ti_mmwave_ros2_interfaces::srv::MMWaveCLI>()
{
  return &ti_mmwave_ros2_interfaces::srv::typesupport_fastrtps_cpp::_MMWaveCLI__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ti_mmwave_ros2_interfaces, srv, MMWaveCLI)() {
  return &ti_mmwave_ros2_interfaces::srv::typesupport_fastrtps_cpp::_MMWaveCLI__handle;
}

#ifdef __cplusplus
}
#endif
