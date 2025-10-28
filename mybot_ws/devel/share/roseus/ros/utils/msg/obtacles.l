;; Auto-generated. Do not edit!


(when (boundp 'utils::obtacles)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'obtacles (find-package "UTILS")))
(unless (find-package "UTILS::OBTACLES")
  (make-package "UTILS::OBTACLES"))

(in-package "ROS")
;;//! \htmlinclude obtacles.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass utils::obtacles
  :super ros::object
  :slots (_header _sonar_left _sonar_right _left_dis_sonar _right_dis_sonar _lidar _left_ver_lidar _right_ver_lidar _angle_avoid_lidar ))

(defmethod utils::obtacles
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:sonar_left __sonar_left) nil)
    ((:sonar_right __sonar_right) nil)
    ((:left_dis_sonar __left_dis_sonar) 0.0)
    ((:right_dis_sonar __right_dis_sonar) 0.0)
    ((:lidar __lidar) nil)
    ((:left_ver_lidar __left_ver_lidar) 0.0)
    ((:right_ver_lidar __right_ver_lidar) 0.0)
    ((:angle_avoid_lidar __angle_avoid_lidar) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _sonar_left __sonar_left)
   (setq _sonar_right __sonar_right)
   (setq _left_dis_sonar (float __left_dis_sonar))
   (setq _right_dis_sonar (float __right_dis_sonar))
   (setq _lidar __lidar)
   (setq _left_ver_lidar (float __left_ver_lidar))
   (setq _right_ver_lidar (float __right_ver_lidar))
   (setq _angle_avoid_lidar (float __angle_avoid_lidar))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:sonar_left
   (&optional __sonar_left)
   (if __sonar_left (setq _sonar_left __sonar_left)) _sonar_left)
  (:sonar_right
   (&optional __sonar_right)
   (if __sonar_right (setq _sonar_right __sonar_right)) _sonar_right)
  (:left_dis_sonar
   (&optional __left_dis_sonar)
   (if __left_dis_sonar (setq _left_dis_sonar __left_dis_sonar)) _left_dis_sonar)
  (:right_dis_sonar
   (&optional __right_dis_sonar)
   (if __right_dis_sonar (setq _right_dis_sonar __right_dis_sonar)) _right_dis_sonar)
  (:lidar
   (&optional __lidar)
   (if __lidar (setq _lidar __lidar)) _lidar)
  (:left_ver_lidar
   (&optional __left_ver_lidar)
   (if __left_ver_lidar (setq _left_ver_lidar __left_ver_lidar)) _left_ver_lidar)
  (:right_ver_lidar
   (&optional __right_ver_lidar)
   (if __right_ver_lidar (setq _right_ver_lidar __right_ver_lidar)) _right_ver_lidar)
  (:angle_avoid_lidar
   (&optional __angle_avoid_lidar)
   (if __angle_avoid_lidar (setq _angle_avoid_lidar __angle_avoid_lidar)) _angle_avoid_lidar)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; bool _sonar_left
    1
    ;; bool _sonar_right
    1
    ;; float32 _left_dis_sonar
    4
    ;; float32 _right_dis_sonar
    4
    ;; bool _lidar
    1
    ;; float32 _left_ver_lidar
    4
    ;; float32 _right_ver_lidar
    4
    ;; float32 _angle_avoid_lidar
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; bool _sonar_left
       (if _sonar_left (write-byte -1 s) (write-byte 0 s))
     ;; bool _sonar_right
       (if _sonar_right (write-byte -1 s) (write-byte 0 s))
     ;; float32 _left_dis_sonar
       (sys::poke _left_dis_sonar (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_dis_sonar
       (sys::poke _right_dis_sonar (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _lidar
       (if _lidar (write-byte -1 s) (write-byte 0 s))
     ;; float32 _left_ver_lidar
       (sys::poke _left_ver_lidar (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_ver_lidar
       (sys::poke _right_ver_lidar (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angle_avoid_lidar
       (sys::poke _angle_avoid_lidar (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; bool _sonar_left
     (setq _sonar_left (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _sonar_right
     (setq _sonar_right (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _left_dis_sonar
     (setq _left_dis_sonar (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_dis_sonar
     (setq _right_dis_sonar (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _lidar
     (setq _lidar (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _left_ver_lidar
     (setq _left_ver_lidar (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_ver_lidar
     (setq _right_ver_lidar (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angle_avoid_lidar
     (setq _angle_avoid_lidar (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get utils::obtacles :md5sum-) "9f846863e66577b5d671e0a2f062d383")
(setf (get utils::obtacles :datatype-) "utils/obtacles")
(setf (get utils::obtacles :definition-)
      "Header header

bool sonar_left
bool sonar_right

float32 left_dis_sonar
float32 right_dis_sonar

bool lidar
float32 left_ver_lidar
float32 right_ver_lidar
float32 angle_avoid_lidar


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



(provide :utils/obtacles "9f846863e66577b5d671e0a2f062d383")


