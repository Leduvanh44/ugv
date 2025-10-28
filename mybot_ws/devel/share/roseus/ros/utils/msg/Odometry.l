;; Auto-generated. Do not edit!


(when (boundp 'utils::Odometry)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'Odometry (find-package "UTILS")))
(unless (find-package "UTILS::ODOMETRY")
  (make-package "UTILS::ODOMETRY"))

(in-package "ROS")
;;//! \htmlinclude Odometry.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass utils::Odometry
  :super ros::object
  :slots (_header _child_frame_id _position _orientation _linear_velocity _angular_velocity _YPY _linear_acceleration _angular_acceleration _latitude _longitude _altitude _heading _x_indoor _y_indoor _mode_in ))

(defmethod utils::Odometry
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:child_frame_id __child_frame_id) "")
    ((:position __position) (instance geometry_msgs::Vector3 :init))
    ((:orientation __orientation) (instance geometry_msgs::Quaternion :init))
    ((:linear_velocity __linear_velocity) (instance geometry_msgs::Vector3 :init))
    ((:angular_velocity __angular_velocity) (instance geometry_msgs::Vector3 :init))
    ((:YPY __YPY) (instance geometry_msgs::Vector3 :init))
    ((:linear_acceleration __linear_acceleration) (instance geometry_msgs::Vector3 :init))
    ((:angular_acceleration __angular_acceleration) (instance geometry_msgs::Vector3 :init))
    ((:latitude __latitude) 0.0)
    ((:longitude __longitude) 0.0)
    ((:altitude __altitude) 0.0)
    ((:heading __heading) 0.0)
    ((:x_indoor __x_indoor) 0.0)
    ((:y_indoor __y_indoor) 0.0)
    ((:mode_in __mode_in) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _child_frame_id (string __child_frame_id))
   (setq _position __position)
   (setq _orientation __orientation)
   (setq _linear_velocity __linear_velocity)
   (setq _angular_velocity __angular_velocity)
   (setq _YPY __YPY)
   (setq _linear_acceleration __linear_acceleration)
   (setq _angular_acceleration __angular_acceleration)
   (setq _latitude (float __latitude))
   (setq _longitude (float __longitude))
   (setq _altitude (float __altitude))
   (setq _heading (float __heading))
   (setq _x_indoor (float __x_indoor))
   (setq _y_indoor (float __y_indoor))
   (setq _mode_in (float __mode_in))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:child_frame_id
   (&optional __child_frame_id)
   (if __child_frame_id (setq _child_frame_id __child_frame_id)) _child_frame_id)
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:orientation
   (&rest __orientation)
   (if (keywordp (car __orientation))
       (send* _orientation __orientation)
     (progn
       (if __orientation (setq _orientation (car __orientation)))
       _orientation)))
  (:linear_velocity
   (&rest __linear_velocity)
   (if (keywordp (car __linear_velocity))
       (send* _linear_velocity __linear_velocity)
     (progn
       (if __linear_velocity (setq _linear_velocity (car __linear_velocity)))
       _linear_velocity)))
  (:angular_velocity
   (&rest __angular_velocity)
   (if (keywordp (car __angular_velocity))
       (send* _angular_velocity __angular_velocity)
     (progn
       (if __angular_velocity (setq _angular_velocity (car __angular_velocity)))
       _angular_velocity)))
  (:YPY
   (&rest __YPY)
   (if (keywordp (car __YPY))
       (send* _YPY __YPY)
     (progn
       (if __YPY (setq _YPY (car __YPY)))
       _YPY)))
  (:linear_acceleration
   (&rest __linear_acceleration)
   (if (keywordp (car __linear_acceleration))
       (send* _linear_acceleration __linear_acceleration)
     (progn
       (if __linear_acceleration (setq _linear_acceleration (car __linear_acceleration)))
       _linear_acceleration)))
  (:angular_acceleration
   (&rest __angular_acceleration)
   (if (keywordp (car __angular_acceleration))
       (send* _angular_acceleration __angular_acceleration)
     (progn
       (if __angular_acceleration (setq _angular_acceleration (car __angular_acceleration)))
       _angular_acceleration)))
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:altitude
   (&optional __altitude)
   (if __altitude (setq _altitude __altitude)) _altitude)
  (:heading
   (&optional __heading)
   (if __heading (setq _heading __heading)) _heading)
  (:x_indoor
   (&optional __x_indoor)
   (if __x_indoor (setq _x_indoor __x_indoor)) _x_indoor)
  (:y_indoor
   (&optional __y_indoor)
   (if __y_indoor (setq _y_indoor __y_indoor)) _y_indoor)
  (:mode_in
   (&optional __mode_in)
   (if __mode_in (setq _mode_in __mode_in)) _mode_in)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _child_frame_id
    4 (length _child_frame_id)
    ;; geometry_msgs/Vector3 _position
    (send _position :serialization-length)
    ;; geometry_msgs/Quaternion _orientation
    (send _orientation :serialization-length)
    ;; geometry_msgs/Vector3 _linear_velocity
    (send _linear_velocity :serialization-length)
    ;; geometry_msgs/Vector3 _angular_velocity
    (send _angular_velocity :serialization-length)
    ;; geometry_msgs/Vector3 _YPY
    (send _YPY :serialization-length)
    ;; geometry_msgs/Vector3 _linear_acceleration
    (send _linear_acceleration :serialization-length)
    ;; geometry_msgs/Vector3 _angular_acceleration
    (send _angular_acceleration :serialization-length)
    ;; float64 _latitude
    8
    ;; float64 _longitude
    8
    ;; float64 _altitude
    8
    ;; float64 _heading
    8
    ;; float64 _x_indoor
    8
    ;; float64 _y_indoor
    8
    ;; float64 _mode_in
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _child_frame_id
       (write-long (length _child_frame_id) s) (princ _child_frame_id s)
     ;; geometry_msgs/Vector3 _position
       (send _position :serialize s)
     ;; geometry_msgs/Quaternion _orientation
       (send _orientation :serialize s)
     ;; geometry_msgs/Vector3 _linear_velocity
       (send _linear_velocity :serialize s)
     ;; geometry_msgs/Vector3 _angular_velocity
       (send _angular_velocity :serialize s)
     ;; geometry_msgs/Vector3 _YPY
       (send _YPY :serialize s)
     ;; geometry_msgs/Vector3 _linear_acceleration
       (send _linear_acceleration :serialize s)
     ;; geometry_msgs/Vector3 _angular_acceleration
       (send _angular_acceleration :serialize s)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _altitude
       (sys::poke _altitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _heading
       (sys::poke _heading (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_indoor
       (sys::poke _x_indoor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_indoor
       (sys::poke _y_indoor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _mode_in
       (sys::poke _mode_in (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _child_frame_id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _child_frame_id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; geometry_msgs/Vector3 _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;; geometry_msgs/Quaternion _orientation
     (send _orientation :deserialize buf ptr-) (incf ptr- (send _orientation :serialization-length))
   ;; geometry_msgs/Vector3 _linear_velocity
     (send _linear_velocity :deserialize buf ptr-) (incf ptr- (send _linear_velocity :serialization-length))
   ;; geometry_msgs/Vector3 _angular_velocity
     (send _angular_velocity :deserialize buf ptr-) (incf ptr- (send _angular_velocity :serialization-length))
   ;; geometry_msgs/Vector3 _YPY
     (send _YPY :deserialize buf ptr-) (incf ptr- (send _YPY :serialization-length))
   ;; geometry_msgs/Vector3 _linear_acceleration
     (send _linear_acceleration :deserialize buf ptr-) (incf ptr- (send _linear_acceleration :serialization-length))
   ;; geometry_msgs/Vector3 _angular_acceleration
     (send _angular_acceleration :deserialize buf ptr-) (incf ptr- (send _angular_acceleration :serialization-length))
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _altitude
     (setq _altitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _heading
     (setq _heading (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_indoor
     (setq _x_indoor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_indoor
     (setq _y_indoor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _mode_in
     (setq _mode_in (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get utils::Odometry :md5sum-) "fc870a8e2d3ea437c6c672a95e3ca877")
(setf (get utils::Odometry :datatype-) "utils/Odometry")
(setf (get utils::Odometry :definition-)
      "Header header
string child_frame_id

geometry_msgs/Vector3 position
geometry_msgs/Quaternion orientation

geometry_msgs/Vector3 linear_velocity
geometry_msgs/Vector3 angular_velocity

geometry_msgs/Vector3 YPY

geometry_msgs/Vector3 linear_acceleration
geometry_msgs/Vector3 angular_acceleration

float64 latitude
float64 longitude
float64 altitude

float64 heading

float64 x_indoor
float64 y_indoor
float64 mode_in

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

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :utils/Odometry "fc870a8e2d3ea437c6c672a95e3ca877")


