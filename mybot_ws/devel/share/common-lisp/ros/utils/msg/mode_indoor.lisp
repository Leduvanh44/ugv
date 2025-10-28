; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude mode_indoor.msg.html

(cl:defclass <mode_indoor> (roslisp-msg-protocol:ros-message)
  ((mode_indoor
    :reader mode_indoor
    :initarg :mode_indoor
    :type cl:fixnum
    :initform 0)
   (set_complete_indoor
    :reader set_complete_indoor
    :initarg :set_complete_indoor
    :type cl:boolean
    :initform cl:nil)
   (abc
    :reader abc
    :initarg :abc
    :type cl:float
    :initform 0.0))
)

(cl:defclass mode_indoor (<mode_indoor>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <mode_indoor>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'mode_indoor)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<mode_indoor> is deprecated: use utils-msg:mode_indoor instead.")))

(cl:ensure-generic-function 'mode_indoor-val :lambda-list '(m))
(cl:defmethod mode_indoor-val ((m <mode_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:mode_indoor-val is deprecated.  Use utils-msg:mode_indoor instead.")
  (mode_indoor m))

(cl:ensure-generic-function 'set_complete_indoor-val :lambda-list '(m))
(cl:defmethod set_complete_indoor-val ((m <mode_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:set_complete_indoor-val is deprecated.  Use utils-msg:set_complete_indoor instead.")
  (set_complete_indoor m))

(cl:ensure-generic-function 'abc-val :lambda-list '(m))
(cl:defmethod abc-val ((m <mode_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:abc-val is deprecated.  Use utils-msg:abc instead.")
  (abc m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <mode_indoor>) ostream)
  "Serializes a message object of type '<mode_indoor>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode_indoor)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'set_complete_indoor) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'abc))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <mode_indoor>) istream)
  "Deserializes a message object of type '<mode_indoor>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode_indoor)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'set_complete_indoor) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'abc) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<mode_indoor>)))
  "Returns string type for a message object of type '<mode_indoor>"
  "utils/mode_indoor")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'mode_indoor)))
  "Returns string type for a message object of type 'mode_indoor"
  "utils/mode_indoor")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<mode_indoor>)))
  "Returns md5sum for a message object of type '<mode_indoor>"
  "dcef5ac4b0e09704e023b93597e3b078")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'mode_indoor)))
  "Returns md5sum for a message object of type 'mode_indoor"
  "dcef5ac4b0e09704e023b93597e3b078")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<mode_indoor>)))
  "Returns full string definition for message of type '<mode_indoor>"
  (cl:format cl:nil "uint8 mode_indoor~%bool set_complete_indoor~%float64 abc~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'mode_indoor)))
  "Returns full string definition for message of type 'mode_indoor"
  (cl:format cl:nil "uint8 mode_indoor~%bool set_complete_indoor~%float64 abc~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <mode_indoor>))
  (cl:+ 0
     1
     1
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <mode_indoor>))
  "Converts a ROS message object to a list"
  (cl:list 'mode_indoor
    (cl:cons ':mode_indoor (mode_indoor msg))
    (cl:cons ':set_complete_indoor (set_complete_indoor msg))
    (cl:cons ':abc (abc msg))
))
