# generated from rosidl_generator_py/resource/_idl.py.em
# with input from yahboomcar_msgs:srv/Kinematics.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'src_pos'
# Member 'src_joints'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Kinematics_Request(type):
    """Metaclass of message 'Kinematics_Request'."""

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
                'yahboomcar_msgs.srv.Kinematics_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__kinematics__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__kinematics__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__kinematics__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__kinematics__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__kinematics__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Kinematics_Request(metaclass=Metaclass_Kinematics_Request):
    """Message class 'Kinematics_Request'."""

    __slots__ = [
        '_kin_name',
        '_src_pos',
        '_src_joints',
    ]

    _fields_and_field_types = {
        'kin_name': 'string',
        'src_pos': 'sequence<double>',
        'src_joints': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.kin_name = kwargs.get('kin_name', str())
        self.src_pos = array.array('d', kwargs.get('src_pos', []))
        self.src_joints = array.array('d', kwargs.get('src_joints', []))

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
        if self.kin_name != other.kin_name:
            return False
        if self.src_pos != other.src_pos:
            return False
        if self.src_joints != other.src_joints:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def kin_name(self):
        """Message field 'kin_name'."""
        return self._kin_name

    @kin_name.setter
    def kin_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'kin_name' field must be of type 'str'"
        self._kin_name = value

    @builtins.property
    def src_pos(self):
        """Message field 'src_pos'."""
        return self._src_pos

    @src_pos.setter
    def src_pos(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'src_pos' array.array() must have the type code of 'd'"
            self._src_pos = value
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
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'src_pos' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._src_pos = array.array('d', value)

    @builtins.property
    def src_joints(self):
        """Message field 'src_joints'."""
        return self._src_joints

    @src_joints.setter
    def src_joints(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'src_joints' array.array() must have the type code of 'd'"
            self._src_joints = value
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
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'src_joints' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._src_joints = array.array('d', value)


# Import statements for member types

# Member 'target_joints'
# Member 'target_pos'
# already imported above
# import array

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_Kinematics_Response(type):
    """Metaclass of message 'Kinematics_Response'."""

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
                'yahboomcar_msgs.srv.Kinematics_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__kinematics__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__kinematics__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__kinematics__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__kinematics__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__kinematics__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Kinematics_Response(metaclass=Metaclass_Kinematics_Response):
    """Message class 'Kinematics_Response'."""

    __slots__ = [
        '_target_joints',
        '_target_pos',
    ]

    _fields_and_field_types = {
        'target_joints': 'sequence<double>',
        'target_pos': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.target_joints = array.array('d', kwargs.get('target_joints', []))
        self.target_pos = array.array('d', kwargs.get('target_pos', []))

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
        if self.target_joints != other.target_joints:
            return False
        if self.target_pos != other.target_pos:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_joints(self):
        """Message field 'target_joints'."""
        return self._target_joints

    @target_joints.setter
    def target_joints(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'target_joints' array.array() must have the type code of 'd'"
            self._target_joints = value
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
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'target_joints' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._target_joints = array.array('d', value)

    @builtins.property
    def target_pos(self):
        """Message field 'target_pos'."""
        return self._target_pos

    @target_pos.setter
    def target_pos(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'target_pos' array.array() must have the type code of 'd'"
            self._target_pos = value
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
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'target_pos' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._target_pos = array.array('d', value)


class Metaclass_Kinematics(type):
    """Metaclass of service 'Kinematics'."""

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
                'yahboomcar_msgs.srv.Kinematics')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__kinematics

            from yahboomcar_msgs.srv import _kinematics
            if _kinematics.Metaclass_Kinematics_Request._TYPE_SUPPORT is None:
                _kinematics.Metaclass_Kinematics_Request.__import_type_support__()
            if _kinematics.Metaclass_Kinematics_Response._TYPE_SUPPORT is None:
                _kinematics.Metaclass_Kinematics_Response.__import_type_support__()


class Kinematics(metaclass=Metaclass_Kinematics):
    from yahboomcar_msgs.srv._kinematics import Kinematics_Request as Request
    from yahboomcar_msgs.srv._kinematics import Kinematics_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
