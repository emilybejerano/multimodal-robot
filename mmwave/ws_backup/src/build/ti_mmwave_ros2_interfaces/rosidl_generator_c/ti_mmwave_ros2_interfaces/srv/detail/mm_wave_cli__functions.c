// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ti_mmwave_ros2_interfaces:srv/MMWaveCLI.idl
// generated code does not contain a copyright notice
#include "ti_mmwave_ros2_interfaces/srv/detail/mm_wave_cli__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `comm`
#include "rosidl_runtime_c/string_functions.h"

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__init(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * msg)
{
  if (!msg) {
    return false;
  }
  // comm
  if (!rosidl_runtime_c__String__init(&msg->comm)) {
    ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__fini(msg);
    return false;
  }
  return true;
}

void
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__fini(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * msg)
{
  if (!msg) {
    return;
  }
  // comm
  rosidl_runtime_c__String__fini(&msg->comm);
}

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__are_equal(const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * lhs, const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // comm
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->comm), &(rhs->comm)))
  {
    return false;
  }
  return true;
}

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__copy(
  const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * input,
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // comm
  if (!rosidl_runtime_c__String__copy(
      &(input->comm), &(output->comm)))
  {
    return false;
  }
  return true;
}

ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request *
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__create()
{
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * msg = (ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request *)malloc(sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request));
  bool success = ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__destroy(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * msg)
{
  if (msg) {
    ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__fini(msg);
  }
  free(msg);
}


bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence__init(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * data = NULL;
  if (size) {
    data = (ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request *)calloc(size, sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence__fini(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence *
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence__create(size_t size)
{
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence * array = (ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence *)malloc(sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence__destroy(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence * array)
{
  if (array) {
    ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence__fini(array);
  }
  free(array);
}

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence__are_equal(const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence * lhs, const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence__copy(
  const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence * input,
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request);
    ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request * data =
      (ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `resp`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__init(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * msg)
{
  if (!msg) {
    return false;
  }
  // resp
  if (!rosidl_runtime_c__String__init(&msg->resp)) {
    ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__fini(msg);
    return false;
  }
  return true;
}

void
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__fini(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * msg)
{
  if (!msg) {
    return;
  }
  // resp
  rosidl_runtime_c__String__fini(&msg->resp);
}

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__are_equal(const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * lhs, const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // resp
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->resp), &(rhs->resp)))
  {
    return false;
  }
  return true;
}

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__copy(
  const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * input,
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // resp
  if (!rosidl_runtime_c__String__copy(
      &(input->resp), &(output->resp)))
  {
    return false;
  }
  return true;
}

ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response *
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__create()
{
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * msg = (ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response *)malloc(sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response));
  bool success = ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__destroy(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * msg)
{
  if (msg) {
    ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__fini(msg);
  }
  free(msg);
}


bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence__init(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * data = NULL;
  if (size) {
    data = (ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response *)calloc(size, sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence__fini(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence *
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence__create(size_t size)
{
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence * array = (ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence *)malloc(sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence__destroy(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence * array)
{
  if (array) {
    ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence__fini(array);
  }
  free(array);
}

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence__are_equal(const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence * lhs, const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence__copy(
  const ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence * input,
  ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response);
    ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response * data =
      (ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ti_mmwave_ros2_interfaces__srv__MMWaveCLI_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
