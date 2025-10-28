; Auto-generated. Do not edit!


(cl:in-package utils-msg)


;//! \htmlinclude string_of_qrcode.msg.html

(cl:defclass <string_of_qrcode> (roslisp-msg-protocol:ros-message)
  ((string_of_qrcode
    :reader string_of_qrcode
    :initarg :string_of_qrcode
    :type cl:string
    :initform ""))
)

(cl:defclass string_of_qrcode (<string_of_qrcode>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <string_of_qrcode>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'string_of_qrcode)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name utils-msg:<string_of_qrcode> is deprecated: use utils-msg:string_of_qrcode instead.")))

(cl:ensure-generic-function 'string_of_qrcode-val :lambda-list '(m))
(cl:defmethod string_of_qrcode-val ((m <string_of_qrcode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader utils-msg:string_of_qrcode-val is deprecated.  Use utils-msg:string_of_qrcode instead.")
  (string_of_qrcode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <string_of_qrcode>) ostream)
  "Serializes a message object of type '<string_of_qrcode>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'string_of_qrcode))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'string_of_qrcode))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <string_of_qrcode>) istream)
  "Deserializes a message object of type '<string_of_qrcode>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'string_of_qrcode) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'string_of_qrcode) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<string_of_qrcode>)))
  "Returns string type for a message object of type '<string_of_qrcode>"
  "utils/string_of_qrcode")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'string_of_qrcode)))
  "Returns string type for a message object of type 'string_of_qrcode"
  "utils/string_of_qrcode")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<string_of_qrcode>)))
  "Returns md5sum for a message object of type '<string_of_qrcode>"
  "e79ff6f588b017cff095149d881c6fca")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'string_of_qrcode)))
  "Returns md5sum for a message object of type 'string_of_qrcode"
  "e79ff6f588b017cff095149d881c6fca")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<string_of_qrcode>)))
  "Returns full string definition for message of type '<string_of_qrcode>"
  (cl:format cl:nil "string string_of_qrcode~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'string_of_qrcode)))
  "Returns full string definition for message of type 'string_of_qrcode"
  (cl:format cl:nil "string string_of_qrcode~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <string_of_qrcode>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'string_of_qrcode))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <string_of_qrcode>))
  "Converts a ROS message object to a list"
  (cl:list 'string_of_qrcode
    (cl:cons ':string_of_qrcode (string_of_qrcode msg))
))
