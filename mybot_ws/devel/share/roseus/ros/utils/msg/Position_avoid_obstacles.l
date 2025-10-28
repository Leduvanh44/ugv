;; Auto-generated. Do not edit!


(when (boundp 'utils::Position_avoid_obstacles)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'Position_avoid_obstacles (find-package "UTILS")))
(unless (find-package "UTILS::POSITION_AVOID_OBSTACLES")
  (make-package "UTILS::POSITION_AVOID_OBSTACLES"))

(in-package "ROS")
;;//! \htmlinclude Position_avoid_obstacles.msg.html


(defclass utils::Position_avoid_obstacles
  :super ros::object
  :slots (_position_avoid_x _position_avoid_y _obstacles ))

(defmethod utils::Position_avoid_obstacles
  (:init
   (&key
    ((:position_avoid_x __position_avoid_x) 0.0)
    ((:position_avoid_y __position_avoid_y) 0.0)
    ((:obstacles __obstacles) nil)
    )
   (send-super :init)
   (setq _position_avoid_x (float __position_avoid_x))
   (setq _position_avoid_y (float __position_avoid_y))
   (setq _obstacles __obstacles)
   self)
  (:position_avoid_x
   (&optional __position_avoid_x)
   (if __position_avoid_x (setq _position_avoid_x __position_avoid_x)) _position_avoid_x)
  (:position_avoid_y
   (&optional __position_avoid_y)
   (if __position_avoid_y (setq _position_avoid_y __position_avoid_y)) _position_avoid_y)
  (:obstacles
   (&optional __obstacles)
   (if __obstacles (setq _obstacles __obstacles)) _obstacles)
  (:serialization-length
   ()
   (+
    ;; float64 _position_avoid_x
    8
    ;; float64 _position_avoid_y
    8
    ;; bool _obstacles
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _position_avoid_x
       (sys::poke _position_avoid_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _position_avoid_y
       (sys::poke _position_avoid_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; bool _obstacles
       (if _obstacles (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _position_avoid_x
     (setq _position_avoid_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _position_avoid_y
     (setq _position_avoid_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; bool _obstacles
     (setq _obstacles (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get utils::Position_avoid_obstacles :md5sum-) "323d00985a22ae750436ee67965d415b")
(setf (get utils::Position_avoid_obstacles :datatype-) "utils/Position_avoid_obstacles")
(setf (get utils::Position_avoid_obstacles :definition-)
      "float64 position_avoid_x
float64 position_avoid_y

bool obstacles 
")



(provide :utils/Position_avoid_obstacles "323d00985a22ae750436ee67965d415b")


