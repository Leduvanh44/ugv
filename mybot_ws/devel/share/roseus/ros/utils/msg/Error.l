;; Auto-generated. Do not edit!


(when (boundp 'utils::Error)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'Error (find-package "UTILS")))
(unless (find-package "UTILS::ERROR")
  (make-package "UTILS::ERROR"))

(in-package "ROS")
;;//! \htmlinclude Error.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass utils::Error
  :super ros::object
  :slots (_header _along_track _cross_track ))

(defmethod utils::Error
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:along_track __along_track) 0.0)
    ((:cross_track __cross_track) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _along_track (float __along_track))
   (setq _cross_track (float __cross_track))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:along_track
   (&optional __along_track)
   (if __along_track (setq _along_track __along_track)) _along_track)
  (:cross_track
   (&optional __cross_track)
   (if __cross_track (setq _cross_track __cross_track)) _cross_track)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _along_track
    8
    ;; float64 _cross_track
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _along_track
       (sys::poke _along_track (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _cross_track
       (sys::poke _cross_track (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _along_track
     (setq _along_track (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _cross_track
     (setq _cross_track (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get utils::Error :md5sum-) "f6e8e9b3c251df9be04fce0859ad0cd8")
(setf (get utils::Error :datatype-) "utils/Error")
(setf (get utils::Error :definition-)
      "Header header

float64 along_track
float64 cross_track

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



(provide :utils/Error "f6e8e9b3c251df9be04fce0859ad0cd8")


