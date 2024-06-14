# generated from rosidl_generator_py/resource/_idl.py.em
# with input from flexiv_msgs:msg/RobotStates.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'q'
# Member 'theta'
# Member 'dq'
# Member 'dtheta'
# Member 'tau'
# Member 'tau_des'
# Member 'tau_dot'
# Member 'tau_ext'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotStates(type):
    """Metaclass of message 'RobotStates'."""

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
            module = import_type_support('flexiv_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'flexiv_msgs.msg.RobotStates')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_states
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_states
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_states
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_states
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_states

            from geometry_msgs.msg import Accel
            if Accel.__class__._TYPE_SUPPORT is None:
                Accel.__class__.__import_type_support__()

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

            from geometry_msgs.msg import Wrench
            if Wrench.__class__._TYPE_SUPPORT is None:
                Wrench.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotStates(metaclass=Metaclass_RobotStates):
    """Message class 'RobotStates'."""

    __slots__ = [
        '_q',
        '_theta',
        '_dq',
        '_dtheta',
        '_tau',
        '_tau_des',
        '_tau_dot',
        '_tau_ext',
        '_tcp_pose',
        '_tcp_pose_des',
        '_tcp_vel',
        '_cam_pose',
        '_flange_pose',
        '_ft_sensor_raw',
        '_ext_wrench_tcp_frame',
        '_ext_wrench_base_frame',
    ]

    _fields_and_field_types = {
        'q': 'double[7]',
        'theta': 'double[7]',
        'dq': 'double[7]',
        'dtheta': 'double[7]',
        'tau': 'double[7]',
        'tau_des': 'double[7]',
        'tau_dot': 'double[7]',
        'tau_ext': 'double[7]',
        'tcp_pose': 'geometry_msgs/Pose',
        'tcp_pose_des': 'geometry_msgs/Pose',
        'tcp_vel': 'geometry_msgs/Accel',
        'cam_pose': 'geometry_msgs/Pose',
        'flange_pose': 'geometry_msgs/Pose',
        'ft_sensor_raw': 'geometry_msgs/Wrench',
        'ext_wrench_tcp_frame': 'geometry_msgs/Wrench',
        'ext_wrench_base_frame': 'geometry_msgs/Wrench',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Accel'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Wrench'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Wrench'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Wrench'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'q' not in kwargs:
            self.q = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.q = numpy.array(kwargs.get('q'), dtype=numpy.float64)
            assert self.q.shape == (7, )
        if 'theta' not in kwargs:
            self.theta = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.theta = numpy.array(kwargs.get('theta'), dtype=numpy.float64)
            assert self.theta.shape == (7, )
        if 'dq' not in kwargs:
            self.dq = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.dq = numpy.array(kwargs.get('dq'), dtype=numpy.float64)
            assert self.dq.shape == (7, )
        if 'dtheta' not in kwargs:
            self.dtheta = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.dtheta = numpy.array(kwargs.get('dtheta'), dtype=numpy.float64)
            assert self.dtheta.shape == (7, )
        if 'tau' not in kwargs:
            self.tau = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.tau = numpy.array(kwargs.get('tau'), dtype=numpy.float64)
            assert self.tau.shape == (7, )
        if 'tau_des' not in kwargs:
            self.tau_des = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.tau_des = numpy.array(kwargs.get('tau_des'), dtype=numpy.float64)
            assert self.tau_des.shape == (7, )
        if 'tau_dot' not in kwargs:
            self.tau_dot = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.tau_dot = numpy.array(kwargs.get('tau_dot'), dtype=numpy.float64)
            assert self.tau_dot.shape == (7, )
        if 'tau_ext' not in kwargs:
            self.tau_ext = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.tau_ext = numpy.array(kwargs.get('tau_ext'), dtype=numpy.float64)
            assert self.tau_ext.shape == (7, )
        from geometry_msgs.msg import Pose
        self.tcp_pose = kwargs.get('tcp_pose', Pose())
        from geometry_msgs.msg import Pose
        self.tcp_pose_des = kwargs.get('tcp_pose_des', Pose())
        from geometry_msgs.msg import Accel
        self.tcp_vel = kwargs.get('tcp_vel', Accel())
        from geometry_msgs.msg import Pose
        self.cam_pose = kwargs.get('cam_pose', Pose())
        from geometry_msgs.msg import Pose
        self.flange_pose = kwargs.get('flange_pose', Pose())
        from geometry_msgs.msg import Wrench
        self.ft_sensor_raw = kwargs.get('ft_sensor_raw', Wrench())
        from geometry_msgs.msg import Wrench
        self.ext_wrench_tcp_frame = kwargs.get('ext_wrench_tcp_frame', Wrench())
        from geometry_msgs.msg import Wrench
        self.ext_wrench_base_frame = kwargs.get('ext_wrench_base_frame', Wrench())

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
        if all(self.q != other.q):
            return False
        if all(self.theta != other.theta):
            return False
        if all(self.dq != other.dq):
            return False
        if all(self.dtheta != other.dtheta):
            return False
        if all(self.tau != other.tau):
            return False
        if all(self.tau_des != other.tau_des):
            return False
        if all(self.tau_dot != other.tau_dot):
            return False
        if all(self.tau_ext != other.tau_ext):
            return False
        if self.tcp_pose != other.tcp_pose:
            return False
        if self.tcp_pose_des != other.tcp_pose_des:
            return False
        if self.tcp_vel != other.tcp_vel:
            return False
        if self.cam_pose != other.cam_pose:
            return False
        if self.flange_pose != other.flange_pose:
            return False
        if self.ft_sensor_raw != other.ft_sensor_raw:
            return False
        if self.ext_wrench_tcp_frame != other.ext_wrench_tcp_frame:
            return False
        if self.ext_wrench_base_frame != other.ext_wrench_base_frame:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def q(self):
        """Message field 'q'."""
        return self._q

    @q.setter
    def q(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'q' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'q' numpy.ndarray() must have a size of 7"
            self._q = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'q' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._q = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def theta(self):
        """Message field 'theta'."""
        return self._theta

    @theta.setter
    def theta(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'theta' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'theta' numpy.ndarray() must have a size of 7"
            self._theta = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'theta' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._theta = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def dq(self):
        """Message field 'dq'."""
        return self._dq

    @dq.setter
    def dq(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'dq' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'dq' numpy.ndarray() must have a size of 7"
            self._dq = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'dq' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._dq = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def dtheta(self):
        """Message field 'dtheta'."""
        return self._dtheta

    @dtheta.setter
    def dtheta(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'dtheta' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'dtheta' numpy.ndarray() must have a size of 7"
            self._dtheta = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'dtheta' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._dtheta = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def tau(self):
        """Message field 'tau'."""
        return self._tau

    @tau.setter
    def tau(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'tau' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'tau' numpy.ndarray() must have a size of 7"
            self._tau = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'tau' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._tau = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def tau_des(self):
        """Message field 'tau_des'."""
        return self._tau_des

    @tau_des.setter
    def tau_des(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'tau_des' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'tau_des' numpy.ndarray() must have a size of 7"
            self._tau_des = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'tau_des' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._tau_des = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def tau_dot(self):
        """Message field 'tau_dot'."""
        return self._tau_dot

    @tau_dot.setter
    def tau_dot(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'tau_dot' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'tau_dot' numpy.ndarray() must have a size of 7"
            self._tau_dot = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'tau_dot' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._tau_dot = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def tau_ext(self):
        """Message field 'tau_ext'."""
        return self._tau_ext

    @tau_ext.setter
    def tau_ext(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'tau_ext' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'tau_ext' numpy.ndarray() must have a size of 7"
            self._tau_ext = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'tau_ext' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._tau_ext = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def tcp_pose(self):
        """Message field 'tcp_pose'."""
        return self._tcp_pose

    @tcp_pose.setter
    def tcp_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'tcp_pose' field must be a sub message of type 'Pose'"
        self._tcp_pose = value

    @builtins.property
    def tcp_pose_des(self):
        """Message field 'tcp_pose_des'."""
        return self._tcp_pose_des

    @tcp_pose_des.setter
    def tcp_pose_des(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'tcp_pose_des' field must be a sub message of type 'Pose'"
        self._tcp_pose_des = value

    @builtins.property
    def tcp_vel(self):
        """Message field 'tcp_vel'."""
        return self._tcp_vel

    @tcp_vel.setter
    def tcp_vel(self, value):
        if __debug__:
            from geometry_msgs.msg import Accel
            assert \
                isinstance(value, Accel), \
                "The 'tcp_vel' field must be a sub message of type 'Accel'"
        self._tcp_vel = value

    @builtins.property
    def cam_pose(self):
        """Message field 'cam_pose'."""
        return self._cam_pose

    @cam_pose.setter
    def cam_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'cam_pose' field must be a sub message of type 'Pose'"
        self._cam_pose = value

    @builtins.property
    def flange_pose(self):
        """Message field 'flange_pose'."""
        return self._flange_pose

    @flange_pose.setter
    def flange_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'flange_pose' field must be a sub message of type 'Pose'"
        self._flange_pose = value

    @builtins.property
    def ft_sensor_raw(self):
        """Message field 'ft_sensor_raw'."""
        return self._ft_sensor_raw

    @ft_sensor_raw.setter
    def ft_sensor_raw(self, value):
        if __debug__:
            from geometry_msgs.msg import Wrench
            assert \
                isinstance(value, Wrench), \
                "The 'ft_sensor_raw' field must be a sub message of type 'Wrench'"
        self._ft_sensor_raw = value

    @builtins.property
    def ext_wrench_tcp_frame(self):
        """Message field 'ext_wrench_tcp_frame'."""
        return self._ext_wrench_tcp_frame

    @ext_wrench_tcp_frame.setter
    def ext_wrench_tcp_frame(self, value):
        if __debug__:
            from geometry_msgs.msg import Wrench
            assert \
                isinstance(value, Wrench), \
                "The 'ext_wrench_tcp_frame' field must be a sub message of type 'Wrench'"
        self._ext_wrench_tcp_frame = value

    @builtins.property
    def ext_wrench_base_frame(self):
        """Message field 'ext_wrench_base_frame'."""
        return self._ext_wrench_base_frame

    @ext_wrench_base_frame.setter
    def ext_wrench_base_frame(self, value):
        if __debug__:
            from geometry_msgs.msg import Wrench
            assert \
                isinstance(value, Wrench), \
                "The 'ext_wrench_base_frame' field must be a sub message of type 'Wrench'"
        self._ext_wrench_base_frame = value
