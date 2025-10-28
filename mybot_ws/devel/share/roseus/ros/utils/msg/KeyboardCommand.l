;; Auto-generated. Do not edit!


(when (boundp 'utils::KeyboardCommand)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'KeyboardCommand (find-package "UTILS")))
(unless (find-package "UTILS::KEYBOARDCOMMAND")
  (make-package "UTILS::KEYBOARDCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude KeyboardCommand.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass utils::KeyboardCommand
  :super ros::object
  :slots (_header _mode _left_vel _right_vel ))

(defmethod utils::KeyboardCommand
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:mode __mode) 0)
    ((:left_vel __left_vel) 0.0)
    ((:right_vel __right_vel) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _mode (round __mode))
   (setq _left_vel (float __left_vel))
   (setq _right_vel (float __right_vel))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:left_vel
   (&optional __left_vel)
   (if __left_vel (setq _left_vel __left_vel)) _left_vel)
  (:right_vel
   (&optional __right_vel)
   (if __right_vel (setq _right_vel __right_vel)) _right_vel)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _mode
    1
    ;; float64 _left_vel
    8
    ;; float64 _right_vel
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _mode
       (write-byte _mode s)
     ;; float64 _left_vel
       (sys::poke _left_vel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_vel
       (sys::poke _right_vel (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _mode
     (setq _mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _left_vel
     (setq _left_vel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_vel
     (setq _right_vel (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get utils::KeyboardCommand :md5sum-) "b9f10f6575f77dc85057b5a07675ddb4")
(setf (get utils::KeyboardCommand :datatype-) "utils/KeyboardCommand")
(setf (get utils::KeyboardCommand :definition-)
      "Header header

uint8 mode

float64 left_vel
float64 right_vel

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



(provide :utils/KeyboardCommand "b9f10f6575f77dc85057b5a07675ddb4")


