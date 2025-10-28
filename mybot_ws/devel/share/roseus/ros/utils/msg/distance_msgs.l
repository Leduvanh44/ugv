;; Auto-generated. Do not edit!


(when (boundp 'utils::distance_msgs)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'distance_msgs (find-package "UTILS")))
(unless (find-package "UTILS::DISTANCE_MSGS")
  (make-package "UTILS::DISTANCE_MSGS"))

(in-package "ROS")
;;//! \htmlinclude distance_msgs.msg.html


(defclass utils::distance_msgs
  :super ros::object
  :slots (_dis_x _dis_y _orient_z _orient_w ))

(defmethod utils::distance_msgs
  (:init
   (&key
    ((:dis_x __dis_x) 0.0)
    ((:dis_y __dis_y) 0.0)
    ((:orient_z __orient_z) 0.0)
    ((:orient_w __orient_w) 0.0)
    )
   (send-super :init)
   (setq _dis_x (float __dis_x))
   (setq _dis_y (float __dis_y))
   (setq _orient_z (float __orient_z))
   (setq _orient_w (float __orient_w))
   self)
  (:dis_x
   (&optional __dis_x)
   (if __dis_x (setq _dis_x __dis_x)) _dis_x)
  (:dis_y
   (&optional __dis_y)
   (if __dis_y (setq _dis_y __dis_y)) _dis_y)
  (:orient_z
   (&optional __orient_z)
   (if __orient_z (setq _orient_z __orient_z)) _orient_z)
  (:orient_w
   (&optional __orient_w)
   (if __orient_w (setq _orient_w __orient_w)) _orient_w)
  (:serialization-length
   ()
   (+
    ;; float64 _dis_x
    8
    ;; float64 _dis_y
    8
    ;; float64 _orient_z
    8
    ;; float64 _orient_w
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _dis_x
       (sys::poke _dis_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dis_y
       (sys::poke _dis_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _orient_z
       (sys::poke _orient_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _orient_w
       (sys::poke _orient_w (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _dis_x
     (setq _dis_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dis_y
     (setq _dis_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _orient_z
     (setq _orient_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _orient_w
     (setq _orient_w (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get utils::distance_msgs :md5sum-) "755117db4347f5445de21da69b3fd8c0")
(setf (get utils::distance_msgs :datatype-) "utils/distance_msgs")
(setf (get utils::distance_msgs :definition-)
      "float64 dis_x
float64 dis_y
float64 orient_z 
float64 orient_w
")



(provide :utils/distance_msgs "755117db4347f5445de21da69b3fd8c0")


