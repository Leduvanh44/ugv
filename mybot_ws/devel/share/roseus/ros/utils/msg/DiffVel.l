;; Auto-generated. Do not edit!


(when (boundp 'utils::DiffVel)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'DiffVel (find-package "UTILS")))
(unless (find-package "UTILS::DIFFVEL")
  (make-package "UTILS::DIFFVEL"))

(in-package "ROS")
;;//! \htmlinclude DiffVel.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass utils::DiffVel
  :super ros::object
  :slots (_header _left_vel _right_vel _currHeading ))

(defmethod utils::DiffVel
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:left_vel __left_vel) 0.0)
    ((:right_vel __right_vel) 0.0)
    ((:currHeading __currHeading) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _left_vel (float __left_vel))
   (setq _right_vel (float __right_vel))
   (setq _currHeading (float __currHeading))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:left_vel
   (&optional __left_vel)
   (if __left_vel (setq _left_vel __left_vel)) _left_vel)
  (:right_vel
   (&optional __right_vel)
   (if __right_vel (setq _right_vel __right_vel)) _right_vel)
  (:currHeading
   (&optional __currHeading)
   (if __currHeading (setq _currHeading __currHeading)) _currHeading)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _left_vel
    8
    ;; float64 _right_vel
    8
    ;; float64 _currHeading
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _left_vel
       (sys::poke _left_vel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_vel
       (sys::poke _right_vel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _currHeading
       (sys::poke _currHeading (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _left_vel
     (setq _left_vel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_vel
     (setq _right_vel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _currHeading
     (setq _currHeading (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get utils::DiffVel :md5sum-) "e25873c95bf62df7b9548a7e2e027143")
(setf (get utils::DiffVel :datatype-) "utils/DiffVel")
(setf (get utils::DiffVel :definition-)
      "Header header

float64 left_vel
float64 right_vel

float64 currHeading

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



(provide :utils/DiffVel "e25873c95bf62df7b9548a7e2e027143")


