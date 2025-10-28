;; Auto-generated. Do not edit!


(when (boundp 'utils::mode_indoor)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'mode_indoor (find-package "UTILS")))
(unless (find-package "UTILS::MODE_INDOOR")
  (make-package "UTILS::MODE_INDOOR"))

(in-package "ROS")
;;//! \htmlinclude mode_indoor.msg.html


(defclass utils::mode_indoor
  :super ros::object
  :slots (_mode_indoor _set_complete_indoor _abc ))

(defmethod utils::mode_indoor
  (:init
   (&key
    ((:mode_indoor __mode_indoor) 0)
    ((:set_complete_indoor __set_complete_indoor) nil)
    ((:abc __abc) 0.0)
    )
   (send-super :init)
   (setq _mode_indoor (round __mode_indoor))
   (setq _set_complete_indoor __set_complete_indoor)
   (setq _abc (float __abc))
   self)
  (:mode_indoor
   (&optional __mode_indoor)
   (if __mode_indoor (setq _mode_indoor __mode_indoor)) _mode_indoor)
  (:set_complete_indoor
   (&optional __set_complete_indoor)
   (if __set_complete_indoor (setq _set_complete_indoor __set_complete_indoor)) _set_complete_indoor)
  (:abc
   (&optional __abc)
   (if __abc (setq _abc __abc)) _abc)
  (:serialization-length
   ()
   (+
    ;; uint8 _mode_indoor
    1
    ;; bool _set_complete_indoor
    1
    ;; float64 _abc
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _mode_indoor
       (write-byte _mode_indoor s)
     ;; bool _set_complete_indoor
       (if _set_complete_indoor (write-byte -1 s) (write-byte 0 s))
     ;; float64 _abc
       (sys::poke _abc (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _mode_indoor
     (setq _mode_indoor (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _set_complete_indoor
     (setq _set_complete_indoor (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float64 _abc
     (setq _abc (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get utils::mode_indoor :md5sum-) "dcef5ac4b0e09704e023b93597e3b078")
(setf (get utils::mode_indoor :datatype-) "utils/mode_indoor")
(setf (get utils::mode_indoor :definition-)
      "uint8 mode_indoor
bool set_complete_indoor
float64 abc
")



(provide :utils/mode_indoor "dcef5ac4b0e09704e023b93597e3b078")


