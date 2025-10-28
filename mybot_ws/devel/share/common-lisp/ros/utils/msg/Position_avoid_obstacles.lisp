; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude Position_avoid_obstacles.msg.html

(cl:defclass <Position_avoid_obstacles> (roslisp-msg-protocol:ros-message)
  ((position_avoid_x
    :reader position_avoid_x
    :initarg :position_avoid_x
    :type cl:float
    :initform 0.0)
   (position_avoid_y
    :reader position_avoid_y
    :initarg :position_avoid_y
    :type cl:float
    :initform 0.0)
   (obstacles
    :reader obstacles
    :initarg :obstacles
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Position_avoid_obstacles (<Position_avoid_obstacles>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Position_avoid_obstacles>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Position_avoid_obstacles)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<Position_avoid_obstacles> is deprecated: use utils-msg:Position_avoid_obstacles instead.")))

(cl:ensure-generic-function 'position_avoid_x-val :lambda-list '(m))
(cl:defmethod position_avoid_x-val ((m <Position_avoid_obstacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:position_avoid_x-val is deprecated.  Use utils-msg:position_avoid_x instead.")
  (position_avoid_x m))

(cl:ensure-generic-function 'position_avoid_y-val :lambda-list '(m))
(cl:defmethod position_avoid_y-val ((m <Position_avoid_obstacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:position_avoid_y-val is deprecated.  Use utils-msg:position_avoid_y instead.")
  (position_avoid_y m))

(cl:ensure-generic-function 'obstacles-val :lambda-list '(m))
(cl:defmethod obstacles-val ((m <Position_avoid_obstacles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:obstacles-val is deprecated.  Use utils-msg:obstacles instead.")
  (obstacles m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Position_avoid_obstacles>) ostream)
  "Serializes a message object of type '<Position_avoid_obstacles>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'position_avoid_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'position_avoid_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'obstacles) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Position_avoid_obstacles>) istream)
  "Deserializes a message object of type '<Position_avoid_obstacles>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position_avoid_x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position_avoid_y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:slot-value msg 'obstacles) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Position_avoid_obstacles>)))
  "Returns string type for a message object of type '<Position_avoid_obstacles>"
  "utils/Position_avoid_obstacles")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Position_avoid_obstacles)))
  "Returns string type for a message object of type 'Position_avoid_obstacles"
  "utils/Position_avoid_obstacles")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Position_avoid_obstacles>)))
  "Returns md5sum for a message object of type '<Position_avoid_obstacles>"
  "323d00985a22ae750436ee67965d415b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Position_avoid_obstacles)))
  "Returns md5sum for a message object of type 'Position_avoid_obstacles"
  "323d00985a22ae750436ee67965d415b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Position_avoid_obstacles>)))
  "Returns full string definition for message of type '<Position_avoid_obstacles>"
  (cl:format cl:nil "float64 position_avoid_x~%float64 position_avoid_y~%~%bool obstacles ~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Position_avoid_obstacles)))
  "Returns full string definition for message of type 'Position_avoid_obstacles"
  (cl:format cl:nil "float64 position_avoid_x~%float64 position_avoid_y~%~%bool obstacles ~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Position_avoid_obstacles>))
  (cl:+ 0
     8
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Position_avoid_obstacles>))
  "Converts a ROS message object to a list"
  (cl:list 'Position_avoid_obstacles
    (cl:cons ':position_avoid_x (position_avoid_x msg))
    (cl:cons ':position_avoid_y (position_avoid_y msg))
    (cl:cons ':obstacles (obstacles msg))
))
