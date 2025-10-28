;; Auto-generated. Do not edit!


(when (boundp 'dk_adap_test::state)
  (if (not (find-package "DK_ADAP_TEST"))
    (make-package "DK_ADAP_TEST"))
  (shadow 'state (find-package "DK_ADAP_TEST")))
(unless (find-package "DK_ADAP_TEST::STATE")
  (make-package "DK_ADAP_TEST::STATE"))

(in-package "ROS")
;;//! \htmlinclude state.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass dk_adap_test::state
  :super ros::object
  :slots (_header _child_frame_id _x _y _phi _linear_velocity _angular_velocity ))

(defmethod dk_adap_test::state
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:child_frame_id __child_frame_id) "")
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:phi __phi) 0.0)
    ((:linear_velocity __linear_velocity) 0.0)
    ((:angular_velocity __angular_velocity) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _child_frame_id (string __child_frame_id))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _phi (float __phi))
   (setq _linear_velocity (float __linear_velocity))
   (setq _angular_velocity (float __angular_velocity))
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
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:phi
   (&optional __phi)
   (if __phi (setq _phi __phi)) _phi)
  (:linear_velocity
   (&optional __linear_velocity)
   (if __linear_velocity (setq _linear_velocity __linear_velocity)) _linear_velocity)
  (:angular_velocity
   (&optional __angular_velocity)
   (if __angular_velocity (setq _angular_velocity __angular_velocity)) _angular_velocity)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _child_frame_id
    4 (length _child_frame_id)
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _phi
    8
    ;; float64 _linear_velocity
    8
    ;; float64 _angular_velocity
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
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _phi
       (sys::poke _phi (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _linear_velocity
       (sys::poke _linear_velocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular_velocity
       (sys::poke _angular_velocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _child_frame_id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _child_frame_id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _phi
     (setq _phi (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _linear_velocity
     (setq _linear_velocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular_velocity
     (setq _angular_velocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get dk_adap_test::state :md5sum-) "140a803ed3c5e06fc1dbfe9d2d41136d")
(setf (get dk_adap_test::state :datatype-) "dk_adap_test/state")
(setf (get dk_adap_test::state :definition-)
      "Header header
string child_frame_id

float64 x
float64 y
float64 phi
float64 linear_velocity
float64 angular_velocity
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



(provide :dk_adap_test/state "140a803ed3c5e06fc1dbfe9d2d41136d")


