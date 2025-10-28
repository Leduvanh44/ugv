;; Auto-generated. Do not edit!


(when (boundp 'utils::pointID)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'pointID (find-package "UTILS")))
(unless (find-package "UTILS::POINTID")
  (make-package "UTILS::POINTID"))

(in-package "ROS")
;;//! \htmlinclude pointID.msg.html


(defclass utils::pointID
  :super ros::object
  :slots (_pointID ))

(defmethod utils::pointID
  (:init
   (&key
    ((:pointID __pointID) 0)
    )
   (send-super :init)
   (setq _pointID (round __pointID))
   self)
  (:pointID
   (&optional __pointID)
   (if __pointID (setq _pointID __pointID)) _pointID)
  (:serialization-length
   ()
   (+
    ;; uint8 _pointID
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _pointID
       (write-byte _pointID s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _pointID
     (setq _pointID (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get utils::pointID :md5sum-) "e9ecd73bc27dcc76310bc664bc0605f0")
(setf (get utils::pointID :datatype-) "utils/pointID")
(setf (get utils::pointID :definition-)
      "uint8 pointID
")



(provide :utils/pointID "e9ecd73bc27dcc76310bc664bc0605f0")


