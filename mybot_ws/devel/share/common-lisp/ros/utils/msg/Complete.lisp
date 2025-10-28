; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude Complete.msg.html

(cl:defclass <Complete> (roslisp-msg-protocol:ros-message)
  ((complete
    :reader complete
    :initarg :complete
    :type cl:boolean
    :initform cl:nil)
   (complete_indoor
    :reader complete_indoor
    :initarg :complete_indoor
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Complete (<Complete>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Complete>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Complete)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<Complete> is deprecated: use utils-msg:Complete instead.")))

(cl:ensure-generic-function 'complete-val :lambda-list '(m))
(cl:defmethod complete-val ((m <Complete>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:complete-val is deprecated.  Use utils-msg:complete instead.")
  (complete m))

(cl:ensure-generic-function 'complete_indoor-val :lambda-list '(m))
(cl:defmethod complete_indoor-val ((m <Complete>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:complete_indoor-val is deprecated.  Use utils-msg:complete_indoor instead.")
  (complete_indoor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Complete>) ostream)
  "Serializes a message object of type '<Complete>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'complete) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'complete_indoor) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Complete>) istream)
  "Deserializes a message object of type '<Complete>"
    (cl:setf (cl:slot-value msg 'complete) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'complete_indoor) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Complete>)))
  "Returns string type for a message object of type '<Complete>"
  "utils/Complete")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Complete)))
  "Returns string type for a message object of type 'Complete"
  "utils/Complete")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Complete>)))
  "Returns md5sum for a message object of type '<Complete>"
  "ad8ef68768c0543c275c56756a7b1615")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Complete)))
  "Returns md5sum for a message object of type 'Complete"
  "ad8ef68768c0543c275c56756a7b1615")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Complete>)))
  "Returns full string definition for message of type '<Complete>"
  (cl:format cl:nil "bool complete ~%bool complete_indoor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Complete)))
  "Returns full string definition for message of type 'Complete"
  (cl:format cl:nil "bool complete ~%bool complete_indoor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Complete>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Complete>))
  "Converts a ROS message object to a list"
  (cl:list 'Complete
    (cl:cons ':complete (complete msg))
    (cl:cons ':complete_indoor (complete_indoor msg))
))
