; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude pointID.msg.html

(cl:defclass <pointID> (roslisp-msg-protocol:ros-message)
  ((pointID
    :reader pointID
    :initarg :pointID
    :type cl:fixnum
    :initform 0))
)

(cl:defclass pointID (<pointID>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pointID>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pointID)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<pointID> is deprecated: use utils-msg:pointID instead.")))

(cl:ensure-generic-function 'pointID-val :lambda-list '(m))
(cl:defmethod pointID-val ((m <pointID>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:pointID-val is deprecated.  Use utils-msg:pointID instead.")
  (pointID m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pointID>) ostream)
  "Serializes a message object of type '<pointID>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pointID)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pointID>) istream)
  "Deserializes a message object of type '<pointID>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pointID)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pointID>)))
  "Returns string type for a message object of type '<pointID>"
  "utils/pointID")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pointID)))
  "Returns string type for a message object of type 'pointID"
  "utils/pointID")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pointID>)))
  "Returns md5sum for a message object of type '<pointID>"
  "e9ecd73bc27dcc76310bc664bc0605f0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pointID)))
  "Returns md5sum for a message object of type 'pointID"
  "e9ecd73bc27dcc76310bc664bc0605f0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pointID>)))
  "Returns full string definition for message of type '<pointID>"
  (cl:format cl:nil "uint8 pointID~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pointID)))
  "Returns full string definition for message of type 'pointID"
  (cl:format cl:nil "uint8 pointID~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pointID>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pointID>))
  "Converts a ROS message object to a list"
  (cl:list 'pointID
    (cl:cons ':pointID (pointID msg))
))
