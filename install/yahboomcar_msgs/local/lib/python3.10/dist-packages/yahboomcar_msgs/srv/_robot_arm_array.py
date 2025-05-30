# generated from rosidl_generator_py/resource/_idl.py.em
# with input from yahboomcar_msgs:srv/RobotArmArray.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotArmArray_Request(type):
    """Metaclass of message 'RobotArmArray_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('yahboomcar_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yahboomcar_msgs.srv.RobotArmArray_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__robot_arm_array__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__robot_arm_array__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__robot_arm_array__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__robot_arm_array__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__robot_arm_array__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotArmArray_Request(metaclass=Metaclass_RobotArmArray_Request):
    """Message class 'RobotArmArray_Request'."""

    __slots__ = [
        '_apply',
    ]

    _fields_and_field_types = {
        'apply': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.apply = kwargs.get('apply', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.apply != other.apply:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def apply(self):
        """Message field 'apply'."""
        return self._apply

    @apply.setter
    def apply(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'apply' field must be of type 'str'"
        self._apply = value


# Import statements for member types

# Member 'joint_1'
# Member 'joint_2'
# Member 'joint_3'
# Member 'joint_4'
# Member 'joint_5'
import array  # noqa: E402, I100

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotArmArray_Response(type):
    """Metaclass of message 'RobotArmArray_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('yahboomcar_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yahboomcar_msgs.srv.RobotArmArray_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__robot_arm_array__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__robot_arm_array__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__robot_arm_array__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__robot_arm_array__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__robot_arm_array__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotArmArray_Response(metaclass=Metaclass_RobotArmArray_Response):
    """Message class 'RobotArmArray_Response'."""

    __slots__ = [
        '_joint_1',
        '_joint_2',
        '_joint_3',
        '_joint_4',
        '_joint_5',
        '_success',
    ]

    _fields_and_field_types = {
        'joint_1': 'sequence<float>',
        'joint_2': 'sequence<float>',
        'joint_3': 'sequence<float>',
        'joint_4': 'sequence<float>',
        'joint_5': 'sequence<float>',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.joint_1 = array.array('f', kwargs.get('joint_1', []))
        self.joint_2 = array.array('f', kwargs.get('joint_2', []))
        self.joint_3 = array.array('f', kwargs.get('joint_3', []))
        self.joint_4 = array.array('f', kwargs.get('joint_4', []))
        self.joint_5 = array.array('f', kwargs.get('joint_5', []))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.joint_1 != other.joint_1:
            return False
        if self.joint_2 != other.joint_2:
            return False
        if self.joint_3 != other.joint_3:
            return False
        if self.joint_4 != other.joint_4:
            return False
        if self.joint_5 != other.joint_5:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def joint_1(self):
        """Message field 'joint_1'."""
        return self._joint_1

    @joint_1.setter
    def joint_1(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'joint_1' array.array() must have the type code of 'f'"
            self._joint_1 = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'joint_1' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._joint_1 = array.array('f', value)

    @builtins.property
    def joint_2(self):
        """Message field 'joint_2'."""
        return self._joint_2

    @joint_2.setter
    def joint_2(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'joint_2' array.array() must have the type code of 'f'"
            self._joint_2 = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'joint_2' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._joint_2 = array.array('f', value)

    @builtins.property
    def joint_3(self):
        """Message field 'joint_3'."""
        return self._joint_3

    @joint_3.setter
    def joint_3(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'joint_3' array.array() must have the type code of 'f'"
            self._joint_3 = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'joint_3' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._joint_3 = array.array('f', value)

    @builtins.property
    def joint_4(self):
        """Message field 'joint_4'."""
        return self._joint_4

    @joint_4.setter
    def joint_4(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'joint_4' array.array() must have the type code of 'f'"
            self._joint_4 = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'joint_4' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._joint_4 = array.array('f', value)

    @builtins.property
    def joint_5(self):
        """Message field 'joint_5'."""
        return self._joint_5

    @joint_5.setter
    def joint_5(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'joint_5' array.array() must have the type code of 'f'"
            self._joint_5 = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'joint_5' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._joint_5 = array.array('f', value)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_RobotArmArray(type):
    """Metaclass of service 'RobotArmArray'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('yahboomcar_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yahboomcar_msgs.srv.RobotArmArray')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__robot_arm_array

            from yahboomcar_msgs.srv import _robot_arm_array
            if _robot_arm_array.Metaclass_RobotArmArray_Request._TYPE_SUPPORT is None:
                _robot_arm_array.Metaclass_RobotArmArray_Request.__import_type_support__()
            if _robot_arm_array.Metaclass_RobotArmArray_Response._TYPE_SUPPORT is None:
                _robot_arm_array.Metaclass_RobotArmArray_Response.__import_type_support__()


class RobotArmArray(metaclass=Metaclass_RobotArmArray):
    from yahboomcar_msgs.srv._robot_arm_array import RobotArmArray_Request as Request
    from yahboomcar_msgs.srv._robot_arm_array import RobotArmArray_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
