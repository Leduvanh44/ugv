;; Auto-generated. Do not edit!


(when (boundp 'utils::goal_indoor)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'goal_indoor (find-package "UTILS")))
(unless (find-package "UTILS::GOAL_INDOOR")
  (make-package "UTILS::GOAL_INDOOR"))

(in-package "ROS")
;;//! \htmlinclude goal_indoor.msg.html


(defclass utils::goal_indoor
  :super ros::object
  :slots (_goal_indoor _way_x_0 _way_x_1 _way_x_2 _way_y_0 _way_y_1 _way_y_2 ))

(defmethod utils::goal_indoor
  (:init
   (&key
    ((:goal_indoor __goal_indoor) 0.0)
    ((:way_x_0 __way_x_0) 0.0)
    ((:way_x_1 __way_x_1) 0.0)
    ((:way_x_2 __way_x_2) 0.0)
    ((:way_y_0 __way_y_0) 0.0)
    ((:way_y_1 __way_y_1) 0.0)
    ((:way_y_2 __way_y_2) 0.0)
    )
   (send-super :init)
   (setq _goal_indoor (float __goal_indoor))
   (setq _way_x_0 (float __way_x_0))
   (setq _way_x_1 (float __way_x_1))
   (setq _way_x_2 (float __way_x_2))
   (setq _way_y_0 (float __way_y_0))
   (setq _way_y_1 (float __way_y_1))
   (setq _way_y_2 (float __way_y_2))
   self)
  (:goal_indoor
   (&optional __goal_indoor)
   (if __goal_indoor (setq _goal_indoor __goal_indoor)) _goal_indoor)
  (:way_x_0
   (&optional __way_x_0)
   (if __way_x_0 (setq _way_x_0 __way_x_0)) _way_x_0)
  (:way_x_1
   (&optional __way_x_1)
   (if __way_x_1 (setq _way_x_1 __way_x_1)) _way_x_1)
  (:way_x_2
   (&optional __way_x_2)
   (if __way_x_2 (setq _way_x_2 __way_x_2)) _way_x_2)
  (:way_y_0
   (&optional __way_y_0)
   (if __way_y_0 (setq _way_y_0 __way_y_0)) _way_y_0)
  (:way_y_1
   (&optional __way_y_1)
   (if __way_y_1 (setq _way_y_1 __way_y_1)) _way_y_1)
  (:way_y_2
   (&optional __way_y_2)
   (if __way_y_2 (setq _way_y_2 __way_y_2)) _way_y_2)
  (:serialization-length
   ()
   (+
    ;; float32 _goal_indoor
    4
    ;; float32 _way_x_0
    4
    ;; float32 _way_x_1
    4
    ;; float32 _way_x_2
    4
    ;; float32 _way_y_0
    4
    ;; float32 _way_y_1
    4
    ;; float32 _way_y_2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _goal_indoor
       (sys::poke _goal_indoor (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _way_x_0
       (sys::poke _way_x_0 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _way_x_1
       (sys::poke _way_x_1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _way_x_2
       (sys::poke _way_x_2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _way_y_0
       (sys::poke _way_y_0 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _way_y_1
       (sys::poke _way_y_1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _way_y_2
       (sys::poke _way_y_2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _goal_indoor
     (setq _goal_indoor (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _way_x_0
     (setq _way_x_0 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _way_x_1
     (setq _way_x_1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _way_x_2
     (setq _way_x_2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _way_y_0
     (setq _way_y_0 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _way_y_1
     (setq _way_y_1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _way_y_2
     (setq _way_y_2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get utils::goal_indoor :md5sum-) "ad1b5000cc6755776de425ca68529153")
(setf (get utils::goal_indoor :datatype-) "utils/goal_indoor")
(setf (get utils::goal_indoor :definition-)
      "float32 goal_indoor

float32 way_x_0
float32 way_x_1
float32 way_x_2 

float32 way_y_0 
float32 way_y_1 
float32 way_y_2 


")



(provide :utils/goal_indoor "ad1b5000cc6755776de425ca68529153")


