;; Auto-generated. Do not edit!


(when (boundp 'utils::Encoder)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'Encoder (find-package "UTILS")))
(unless (find-package "UTILS::ENCODER")
  (make-package "UTILS::ENCODER"))

(in-package "ROS")
;;//! \htmlinclude Encoder.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass utils::Encoder
  :super ros::object
  :slots (_header _left_twist _right_twist ))

(defmethod utils::Encoder
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:left_twist __left_twist) 0.0)
    ((:right_twist __right_twist) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _left_twist (float __left_twist))
   (setq _right_twist (float __right_twist))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:left_twist
   (&optional __left_twist)
   (if __left_twist (setq _left_twist __left_twist)) _left_twist)
  (:right_twist
   (&optional __right_twist)
   (if __right_twist (setq _right_twist __right_twist)) _right_twist)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _left_twist
    8
    ;; float64 _right_twist
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _left_twist
       (sys::poke _left_twist (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_twist
       (sys::poke _right_twist (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _left_twist
     (setq _left_twist (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_twist
     (setq _right_twist (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get utils::Encoder :md5sum-) "e3130839172a03e3e11466bb4bb95e01")
(setf (get utils::Encoder :datatype-) "utils/Encoder")
(setf (get utils::Encoder :definition-)
      "Header header

float64 left_twist
float64 right_twist

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :utils/Encoder "e3130839172a03e3e11466bb4bb95e01")


