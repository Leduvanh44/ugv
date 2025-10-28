; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude goal_indoor.msg.html

(cl:defclass <goal_indoor> (roslisp-msg-protocol:ros-message)
  ((goal_indoor
    :reader goal_indoor
    :initarg :goal_indoor
    :type cl:float
    :initform 0.0)
   (way_x_0
    :reader way_x_0
    :initarg :way_x_0
    :type cl:float
    :initform 0.0)
   (way_x_1
    :reader way_x_1
    :initarg :way_x_1
    :type cl:float
    :initform 0.0)
   (way_x_2
    :reader way_x_2
    :initarg :way_x_2
    :type cl:float
    :initform 0.0)
   (way_y_0
    :reader way_y_0
    :initarg :way_y_0
    :type cl:float
    :initform 0.0)
   (way_y_1
    :reader way_y_1
    :initarg :way_y_1
    :type cl:float
    :initform 0.0)
   (way_y_2
    :reader way_y_2
    :initarg :way_y_2
    :type cl:float
    :initform 0.0))
)

(cl:defclass goal_indoor (<goal_indoor>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <goal_indoor>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'goal_indoor)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<goal_indoor> is deprecated: use utils-msg:goal_indoor instead.")))

(cl:ensure-generic-function 'goal_indoor-val :lambda-list '(m))
(cl:defmethod goal_indoor-val ((m <goal_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:goal_indoor-val is deprecated.  Use utils-msg:goal_indoor instead.")
  (goal_indoor m))

(cl:ensure-generic-function 'way_x_0-val :lambda-list '(m))
(cl:defmethod way_x_0-val ((m <goal_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:way_x_0-val is deprecated.  Use utils-msg:way_x_0 instead.")
  (way_x_0 m))

(cl:ensure-generic-function 'way_x_1-val :lambda-list '(m))
(cl:defmethod way_x_1-val ((m <goal_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:way_x_1-val is deprecated.  Use utils-msg:way_x_1 instead.")
  (way_x_1 m))

(cl:ensure-generic-function 'way_x_2-val :lambda-list '(m))
(cl:defmethod way_x_2-val ((m <goal_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:way_x_2-val is deprecated.  Use utils-msg:way_x_2 instead.")
  (way_x_2 m))

(cl:ensure-generic-function 'way_y_0-val :lambda-list '(m))
(cl:defmethod way_y_0-val ((m <goal_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:way_y_0-val is deprecated.  Use utils-msg:way_y_0 instead.")
  (way_y_0 m))

(cl:ensure-generic-function 'way_y_1-val :lambda-list '(m))
(cl:defmethod way_y_1-val ((m <goal_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:way_y_1-val is deprecated.  Use utils-msg:way_y_1 instead.")
  (way_y_1 m))

(cl:ensure-generic-function 'way_y_2-val :lambda-list '(m))
(cl:defmethod way_y_2-val ((m <goal_indoor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:way_y_2-val is deprecated.  Use utils-msg:way_y_2 instead.")
  (way_y_2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <goal_indoor>) ostream)
  "Serializes a message object of type '<goal_indoor>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'goal_indoor))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'way_x_0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'way_x_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'way_x_2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'way_y_0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'way_y_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'way_y_2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <goal_indoor>) istream)
  "Deserializes a message object of type '<goal_indoor>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'goal_indoor) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'way_x_0) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'way_x_1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'way_x_2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'way_y_0) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'way_y_1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'way_y_2) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<goal_indoor>)))
  "Returns string type for a message object of type '<goal_indoor>"
  "utils/goal_indoor")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'goal_indoor)))
  "Returns string type for a message object of type 'goal_indoor"
  "utils/goal_indoor")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<goal_indoor>)))
  "Returns md5sum for a message object of type '<goal_indoor>"
  "ad1b5000cc6755776de425ca68529153")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'goal_indoor)))
  "Returns md5sum for a message object of type 'goal_indoor"
  "ad1b5000cc6755776de425ca68529153")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<goal_indoor>)))
  "Returns full string definition for message of type '<goal_indoor>"
  (cl:format cl:nil "float32 goal_indoor~%~%float32 way_x_0~%float32 way_x_1~%float32 way_x_2 ~%~%float32 way_y_0 ~%float32 way_y_1 ~%float32 way_y_2 ~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'goal_indoor)))
  "Returns full string definition for message of type 'goal_indoor"
  (cl:format cl:nil "float32 goal_indoor~%~%float32 way_x_0~%float32 way_x_1~%float32 way_x_2 ~%~%float32 way_y_0 ~%float32 way_y_1 ~%float32 way_y_2 ~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <goal_indoor>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <goal_indoor>))
  "Converts a ROS message object to a list"
  (cl:list 'goal_indoor
    (cl:cons ':goal_indoor (goal_indoor msg))
    (cl:cons ':way_x_0 (way_x_0 msg))
    (cl:cons ':way_x_1 (way_x_1 msg))
    (cl:cons ':way_x_2 (way_x_2 msg))
    (cl:cons ':way_y_0 (way_y_0 msg))
    (cl:cons ':way_y_1 (way_y_1 msg))
    (cl:cons ':way_y_2 (way_y_2 msg))
))
