; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude distance_msgs.msg.html

(cl:defclass <distance_msgs> (roslisp-msg-protocol:ros-message)
  ((dis_x
    :reader dis_x
    :initarg :dis_x
    :type cl:float
    :initform 0.0)
   (dis_y
    :reader dis_y
    :initarg :dis_y
    :type cl:float
    :initform 0.0)
   (orient_z
    :reader orient_z
    :initarg :orient_z
    :type cl:float
    :initform 0.0)
   (orient_w
    :reader orient_w
    :initarg :orient_w
    :type cl:float
    :initform 0.0))
)

(cl:defclass distance_msgs (<distance_msgs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <distance_msgs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'distance_msgs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<distance_msgs> is deprecated: use utils-msg:distance_msgs instead.")))

(cl:ensure-generic-function 'dis_x-val :lambda-list '(m))
(cl:defmethod dis_x-val ((m <distance_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:dis_x-val is deprecated.  Use utils-msg:dis_x instead.")
  (dis_x m))

(cl:ensure-generic-function 'dis_y-val :lambda-list '(m))
(cl:defmethod dis_y-val ((m <distance_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:dis_y-val is deprecated.  Use utils-msg:dis_y instead.")
  (dis_y m))

(cl:ensure-generic-function 'orient_z-val :lambda-list '(m))
(cl:defmethod orient_z-val ((m <distance_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:orient_z-val is deprecated.  Use utils-msg:orient_z instead.")
  (orient_z m))

(cl:ensure-generic-function 'orient_w-val :lambda-list '(m))
(cl:defmethod orient_w-val ((m <distance_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:orient_w-val is deprecated.  Use utils-msg:orient_w instead.")
  (orient_w m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <distance_msgs>) ostream)
  "Serializes a message object of type '<distance_msgs>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dis_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dis_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'orient_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'orient_w))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <distance_msgs>) istream)
  "Deserializes a message object of type '<distance_msgs>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dis_x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dis_y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'orient_z) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'orient_w) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<distance_msgs>)))
  "Returns string type for a message object of type '<distance_msgs>"
  "utils/distance_msgs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'distance_msgs)))
  "Returns string type for a message object of type 'distance_msgs"
  "utils/distance_msgs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<distance_msgs>)))
  "Returns md5sum for a message object of type '<distance_msgs>"
  "755117db4347f5445de21da69b3fd8c0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'distance_msgs)))
  "Returns md5sum for a message object of type 'distance_msgs"
  "755117db4347f5445de21da69b3fd8c0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<distance_msgs>)))
  "Returns full string definition for message of type '<distance_msgs>"
  (cl:format cl:nil "float64 dis_x~%float64 dis_y~%float64 orient_z ~%float64 orient_w~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'distance_msgs)))
  "Returns full string definition for message of type 'distance_msgs"
  (cl:format cl:nil "float64 dis_x~%float64 dis_y~%float64 orient_z ~%float64 orient_w~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <distance_msgs>))
  (cl:+ 0
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <distance_msgs>))
  "Converts a ROS message object to a list"
  (cl:list 'distance_msgs
    (cl:cons ':dis_x (dis_x msg))
    (cl:cons ':dis_y (dis_y msg))
    (cl:cons ':orient_z (orient_z msg))
    (cl:cons ':orient_w (orient_w msg))
))
