; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude Setpoint.msg.html

(cl:defclass <Setpoint> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (child_frame_id
    :reader child_frame_id
    :initarg :child_frame_id
    :type cl:string
    :initform "")
   (position
    :reader position
    :initarg :position
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (orientation
    :reader orientation
    :initarg :orientation
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (linear_velocity
    :reader linear_velocity
    :initarg :linear_velocity
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (angular_velocity
    :reader angular_velocity
    :initarg :angular_velocity
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (linear_acceleration
    :reader linear_acceleration
    :initarg :linear_acceleration
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (angular_acceleration
    :reader angular_acceleration
    :initarg :angular_acceleration
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3)))
)

(cl:defclass Setpoint (<Setpoint>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Setpoint>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Setpoint)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<Setpoint> is deprecated: use utils-msg:Setpoint instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Setpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:header-val is deprecated.  Use utils-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'child_frame_id-val :lambda-list '(m))
(cl:defmethod child_frame_id-val ((m <Setpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:child_frame_id-val is deprecated.  Use utils-msg:child_frame_id instead.")
  (child_frame_id m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <Setpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:position-val is deprecated.  Use utils-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'orientation-val :lambda-list '(m))
(cl:defmethod orientation-val ((m <Setpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:orientation-val is deprecated.  Use utils-msg:orientation instead.")
  (orientation m))

(cl:ensure-generic-function 'linear_velocity-val :lambda-list '(m))
(cl:defmethod linear_velocity-val ((m <Setpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:linear_velocity-val is deprecated.  Use utils-msg:linear_velocity instead.")
  (linear_velocity m))

(cl:ensure-generic-function 'angular_velocity-val :lambda-list '(m))
(cl:defmethod angular_velocity-val ((m <Setpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:angular_velocity-val is deprecated.  Use utils-msg:angular_velocity instead.")
  (angular_velocity m))

(cl:ensure-generic-function 'linear_acceleration-val :lambda-list '(m))
(cl:defmethod linear_acceleration-val ((m <Setpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:linear_acceleration-val is deprecated.  Use utils-msg:linear_acceleration instead.")
  (linear_acceleration m))

(cl:ensure-generic-function 'angular_acceleration-val :lambda-list '(m))
(cl:defmethod angular_acceleration-val ((m <Setpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:angular_acceleration-val is deprecated.  Use utils-msg:angular_acceleration instead.")
  (angular_acceleration m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Setpoint>) ostream)
  "Serializes a message object of type '<Setpoint>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'child_frame_id))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'child_frame_id))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'position) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'orientation) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'linear_velocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'angular_velocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'linear_acceleration) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'angular_acceleration) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Setpoint>) istream)
  "Deserializes a message object of type '<Setpoint>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'child_frame_id) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'child_frame_id) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'position) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'orientation) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'linear_velocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'angular_velocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'linear_acceleration) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'angular_acceleration) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Setpoint>)))
  "Returns string type for a message object of type '<Setpoint>"
  "utils/Setpoint")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Setpoint)))
  "Returns string type for a message object of type 'Setpoint"
  "utils/Setpoint")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Setpoint>)))
  "Returns md5sum for a message object of type '<Setpoint>"
  "4e43f668bc03be1729626be3bcf6bee3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Setpoint)))
  "Returns md5sum for a message object of type 'Setpoint"
  "4e43f668bc03be1729626be3bcf6bee3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Setpoint>)))
  "Returns full string definition for message of type '<Setpoint>"
  (cl:format cl:nil "Header header~%string child_frame_id~%~%geometry_msgs/Vector3 position~%geometry_msgs/Vector3 orientation~%~%geometry_msgs/Vector3 linear_velocity~%geometry_msgs/Vector3 angular_velocity~%~%geometry_msgs/Vector3 linear_acceleration~%geometry_msgs/Vector3 angular_acceleration~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Setpoint)))
  "Returns full string definition for message of type 'Setpoint"
  (cl:format cl:nil "Header header~%string child_frame_id~%~%geometry_msgs/Vector3 position~%geometry_msgs/Vector3 orientation~%~%geometry_msgs/Vector3 linear_velocity~%geometry_msgs/Vector3 angular_velocity~%~%geometry_msgs/Vector3 linear_acceleration~%geometry_msgs/Vector3 angular_acceleration~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Setpoint>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'child_frame_id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'position))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'orientation))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'linear_velocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'angular_velocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'linear_acceleration))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'angular_acceleration))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Setpoint>))
  "Converts a ROS message object to a list"
  (cl:list 'Setpoint
    (cl:cons ':header (header msg))
    (cl:cons ':child_frame_id (child_frame_id msg))
    (cl:cons ':position (position msg))
    (cl:cons ':orientation (orientation msg))
    (cl:cons ':linear_velocity (linear_velocity msg))
    (cl:cons ':angular_velocity (angular_velocity msg))
    (cl:cons ':linear_acceleration (linear_acceleration msg))
    (cl:cons ':angular_acceleration (angular_acceleration msg))
))
