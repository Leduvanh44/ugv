;; Auto-generated. Do not edit!


(when (boundp 'utils::Complete)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'Complete (find-package "UTILS")))
(unless (find-package "UTILS::COMPLETE")
  (make-package "UTILS::COMPLETE"))

(in-package "ROS")
;;//! \htmlinclude Complete.msg.html


(defclass utils::Complete
  :super ros::object
  :slots (_complete _complete_indoor ))

(defmethod utils::Complete
  (:init
   (&key
    ((:complete __complete) nil)
    ((:complete_indoor __complete_indoor) nil)
    )
   (send-super :init)
   (setq _complete __complete)
   (setq _complete_indoor __complete_indoor)
   self)
  (:complete
   (&optional __complete)
   (if __complete (setq _complete __complete)) _complete)
  (:complete_indoor
   (&optional __complete_indoor)
   (if __complete_indoor (setq _complete_indoor __complete_indoor)) _complete_indoor)
  (:serialization-length
   ()
   (+
    ;; bool _complete
    1
    ;; bool _complete_indoor
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _complete
       (if _complete (write-byte -1 s) (write-byte 0 s))
     ;; bool _complete_indoor
       (if _complete_indoor (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _complete
     (setq _complete (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _complete_indoor
     (setq _complete_indoor (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get utils::Complete :md5sum-) "ad8ef68768c0543c275c56756a7b1615")
(setf (get utils::Complete :datatype-) "utils/Complete")
(setf (get utils::Complete :definition-)
      "bool complete 
bool complete_indoor


")



(provide :utils/Complete "ad8ef68768c0543c275c56756a7b1615")


