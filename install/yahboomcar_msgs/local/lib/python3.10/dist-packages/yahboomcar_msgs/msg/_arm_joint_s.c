// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from yahboomcar_msgs:msg/ArmJoint.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "yahboomcar_msgs/msg/detail/arm_joint__struct.h"
#include "yahboomcar_msgs/msg/detail/arm_joint__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool yahboomcar_msgs__msg__arm_joint__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("yahboomcar_msgs.msg._arm_joint.ArmJoint", full_classname_dest, 39) == 0);
  }
  yahboomcar_msgs__msg__ArmJoint * ros_message = _ros_message;
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // run_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "run_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->run_time = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // joint_1
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->joint_1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // joint_2
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->joint_2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // joint_3
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->joint_3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // joint_4
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_4");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->joint_4 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // joint_5
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_5");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->joint_5 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * yahboomcar_msgs__msg__arm_joint__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ArmJoint */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("yahboomcar_msgs.msg._arm_joint");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ArmJoint");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  yahboomcar_msgs__msg__ArmJoint * ros_message = (yahboomcar_msgs__msg__ArmJoint *)raw_ros_message;
  {  // id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // run_time
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->run_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "run_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // joint_1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->joint_1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "joint_1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // joint_2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->joint_2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "joint_2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // joint_3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->joint_3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "joint_3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // joint_4
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->joint_4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "joint_4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // joint_5
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->joint_5);
    {
      int rc = PyObject_SetAttrString(_pymessage, "joint_5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
