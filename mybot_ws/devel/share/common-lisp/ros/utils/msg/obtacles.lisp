; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude obtacles.msg.html

(cl:defclass <obtacles> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (sonar_left
    :reader sonar_left
    :initarg :sonar_left
    :type cl:boolean
    :initform cl:nil)
   (sonar_right
    :reader sonar_right
    :initarg :sonar_right
    :type cl:boolean
    :initform cl:nil)
   (left_dis_sonar
    :reader left_dis_sonar
    :initarg :left_dis_sonar
    :type cl:float
    :initform 0.0)
   (right_dis_sonar
    :reader right_dis_sonar
    :initarg :right_dis_sonar
    :type cl:float
    :initform 0.0)
   (lidar
    :reader lidar
    :initarg :lidar
    :type cl:boolean
    :initform cl:nil)
   (left_ver_lidar
    :reader left_ver_lidar
    :initarg :left_ver_lidar
    :type cl:float
    :initform 0.0)
   (right_ver_lidar
    :reader right_ver_lidar
    :initarg :right_ver_lidar
    :type cl:float
    :initform 0.0)
   (angle_avoid_lidar
    :reader angle_avoid_lidar
    :initarg :angle_avoid_lidar
    :type cl:float
    :initform 0.0))
)

(cl:defclass obtacles (<obtacles>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <obtacles>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'obtacles)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<obtacles> is deprecated: use utils-msg:obtacles instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <obtacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:header-val is deprecated.  Use utils-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'sonar_left-val :lambda-list '(m))
(cl:defmethod sonar_left-val ((m <obtacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:sonar_left-val is deprecated.  Use utils-msg:sonar_left instead.")
  (sonar_left m))

(cl:ensure-generic-function 'sonar_right-val :lambda-list '(m))
(cl:defmethod sonar_right-val ((m <obtacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:sonar_right-val is deprecated.  Use utils-msg:sonar_right instead.")
  (sonar_right m))

(cl:ensure-generic-function 'left_dis_sonar-val :lambda-list '(m))
(cl:defmethod left_dis_sonar-val ((m <obtacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:left_dis_sonar-val is deprecated.  Use utils-msg:left_dis_sonar instead.")
  (left_dis_sonar m))

(cl:ensure-generic-function 'right_dis_sonar-val :lambda-list '(m))
(cl:defmethod right_dis_sonar-val ((m <obtacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:right_dis_sonar-val is deprecated.  Use utils-msg:right_dis_sonar instead.")
  (right_dis_sonar m))

(cl:ensure-generic-function 'lidar-val :lambda-list '(m))
(cl:defmethod lidar-val ((m <obtacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:lidar-val is deprecated.  Use utils-msg:lidar instead.")
  (lidar m))

(cl:ensure-generic-function 'left_ver_lidar-val :lambda-list '(m))
(cl:defmethod left_ver_lidar-val ((m <obtacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:left_ver_lidar-val is deprecated.  Use utils-msg:left_ver_lidar instead.")
  (left_ver_lidar m))

(cl:ensure-generic-function 'right_ver_lidar-val :lambda-list '(m))
(cl:defmethod right_ver_lidar-val ((m <obtacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:right_ver_lidar-val is deprecated.  Use utils-msg:right_ver_lidar instead.")
  (right_ver_lidar m))

(cl:ensure-generic-function 'angle_avoid_lidar-val :lambda-list '(m))
(cl:defmethod angle_avoid_lidar-val ((m <obtacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:angle_avoid_lidar-val is deprecated.  Use utils-msg:angle_avoid_lidar instead.")
  (angle_avoid_lidar m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <obtacles>) ostream)
  "Serializes a message object of type '<obtacles>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'sonar_left) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'sonar_right) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_dis_sonar))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_dis_sonar))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'lidar) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_ver_lidar))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_ver_lidar))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle_avoid_lidar))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <obtacles>) istream)
  "Deserializes a message object of type '<obtacles>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:slot-value msg 'sonar_left) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'sonar_right) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_dis_sonar) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_dis_sonar) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'lidar) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_ver_lidar) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_ver_lidar) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle_avoid_lidar) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<obtacles>)))
  "Returns string type for a message object of type '<obtacles>"
  "utils/obtacles")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'obtacles)))
  "Returns string type for a message object of type 'obtacles"
  "utils/obtacles")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<obtacles>)))
  "Returns md5sum for a message object of type '<obtacles>"
  "9f846863e66577b5d671e0a2f062d383")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'obtacles)))
  "Returns md5sum for a message object of type 'obtacles"
  "9f846863e66577b5d671e0a2f062d383")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<obtacles>)))
  "Returns full string definition for message of type '<obtacles>"
  (cl:format cl:nil "Header header~%~%bool sonar_left~%bool sonar_right~%~%float32 left_dis_sonar~%float32 right_dis_sonar~%~%bool lidar~%float32 left_ver_lidar~%float32 right_ver_lidar~%float32 angle_avoid_lidar~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'obtacles)))
  "Returns full string definition for message of type 'obtacles"
  (cl:format cl:nil "Header header~%~%bool sonar_left~%bool sonar_right~%~%float32 left_dis_sonar~%float32 right_dis_sonar~%~%bool lidar~%float32 left_ver_lidar~%float32 right_ver_lidar~%float32 angle_avoid_lidar~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <obtacles>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     4
     4
     1
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <obtacles>))
  "Converts a ROS message object to a list"
  (cl:list 'obtacles
    (cl:cons ':header (header msg))
    (cl:cons ':sonar_left (sonar_left msg))
    (cl:cons ':sonar_right (sonar_right msg))
    (cl:cons ':left_dis_sonar (left_dis_sonar msg))
    (cl:cons ':right_dis_sonar (right_dis_sonar msg))
    (cl:cons ':lidar (lidar msg))
    (cl:cons ':left_ver_lidar (left_ver_lidar msg))
    (cl:cons ':right_ver_lidar (right_ver_lidar msg))
    (cl:cons ':angle_avoid_lidar (angle_avoid_lidar msg))
))
