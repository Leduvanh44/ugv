; Auto-generated. Do not edit!


(cl:in-package dk_adap_test-msg)


;//! \htmlinclude ref.msg.html

(cl:defclass <ref> (roslisp-msg-protocol:ros-message)
  ((points
    :reader points
    :initarg :points
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point)))
   (vel
    :reader vel
    :initarg :vel
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point)))
   (accel
    :reader accel
    :initarg :accel
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point))))
)

(cl:defclass ref (<ref>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ref>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ref)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dk_adap_test-msg:<ref> is deprecated: use dk_adap_test-msg:ref instead.")))

(cl:ensure-generic-function 'points-val :lambda-list '(m))
(cl:defmethod points-val ((m <ref>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dk_adap_test-msg:points-val is deprecated.  Use dk_adap_test-msg:points instead.")
  (points m))

(cl:ensure-generic-function 'vel-val :lambda-list '(m))
(cl:defmethod vel-val ((m <ref>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dk_adap_test-msg:vel-val is deprecated.  Use dk_adap_test-msg:vel instead.")
  (vel m))

(cl:ensure-generic-function 'accel-val :lambda-list '(m))
(cl:defmethod accel-val ((m <ref>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dk_adap_test-msg:accel-val is deprecated.  Use dk_adap_test-msg:accel instead.")
  (accel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ref>) ostream)
  "Serializes a message object of type '<ref>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'points))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'points))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'vel))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'accel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'accel))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ref>) istream)
  "Deserializes a message object of type '<ref>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'points) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'points)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'vel) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'vel)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'accel) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'accel)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ref>)))
  "Returns string type for a message object of type '<ref>"
  "dk_adap_test/ref")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ref)))
  "Returns string type for a message object of type 'ref"
  "dk_adap_test/ref")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ref>)))
  "Returns md5sum for a message object of type '<ref>"
  "77379297565095d4368ccb556eb253fa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ref)))
  "Returns md5sum for a message object of type 'ref"
  "77379297565095d4368ccb556eb253fa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ref>)))
  "Returns full string definition for message of type '<ref>"
  (cl:format cl:nil "geometry_msgs/Point[] points~%geometry_msgs/Point[] vel~%geometry_msgs/Point[] accel~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ref)))
  "Returns full string definition for message of type 'ref"
  (cl:format cl:nil "geometry_msgs/Point[] points~%geometry_msgs/Point[] vel~%geometry_msgs/Point[] accel~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ref>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'points) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'vel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'accel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ref>))
  "Converts a ROS message object to a list"
  (cl:list 'ref
    (cl:cons ':points (points msg))
    (cl:cons ':vel (vel msg))
    (cl:cons ':accel (accel msg))
))
