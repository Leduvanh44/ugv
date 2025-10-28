; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude heading_plot.msg.html

(cl:defclass <heading_plot> (roslisp-msg-protocol:ros-message)
  ((CurrX_indoor
    :reader CurrX_indoor
    :initarg :CurrX_indoor
    :type cl:float
    :initform 0.0)
   (exit_indoor
    :reader exit_indoor
    :initarg :exit_indoor
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass heading_plot (<heading_plot>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <heading_plot>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'heading_plot)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<heading_plot> is deprecated: use utils-msg:heading_plot instead.")))

(cl:ensure-generic-function 'CurrX_indoor-val :lambda-list '(m))
(cl:defmethod CurrX_indoor-val ((m <heading_plot>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:CurrX_indoor-val is deprecated.  Use utils-msg:CurrX_indoor instead.")
  (CurrX_indoor m))

(cl:ensure-generic-function 'exit_indoor-val :lambda-list '(m))
(cl:defmethod exit_indoor-val ((m <heading_plot>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:exit_indoor-val is deprecated.  Use utils-msg:exit_indoor instead.")
  (exit_indoor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <heading_plot>) ostream)
  "Serializes a message object of type '<heading_plot>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'CurrX_indoor))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'exit_indoor) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <heading_plot>) istream)
  "Deserializes a message object of type '<heading_plot>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'CurrX_indoor) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:slot-value msg 'exit_indoor) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<heading_plot>)))
  "Returns string type for a message object of type '<heading_plot>"
  "utils/heading_plot")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'heading_plot)))
  "Returns string type for a message object of type 'heading_plot"
  "utils/heading_plot")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<heading_plot>)))
  "Returns md5sum for a message object of type '<heading_plot>"
  "4ed3e3540501bff48c532877c801a09c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'heading_plot)))
  "Returns md5sum for a message object of type 'heading_plot"
  "4ed3e3540501bff48c532877c801a09c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<heading_plot>)))
  "Returns full string definition for message of type '<heading_plot>"
  (cl:format cl:nil "float64 CurrX_indoor~%bool exit_indoor~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'heading_plot)))
  "Returns full string definition for message of type 'heading_plot"
  (cl:format cl:nil "float64 CurrX_indoor~%bool exit_indoor~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <heading_plot>))
  (cl:+ 0
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <heading_plot>))
  "Converts a ROS message object to a list"
  (cl:list 'heading_plot
    (cl:cons ':CurrX_indoor (CurrX_indoor msg))
    (cl:cons ':exit_indoor (exit_indoor msg))
))
