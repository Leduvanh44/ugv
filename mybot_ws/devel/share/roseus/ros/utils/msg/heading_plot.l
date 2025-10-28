;; Auto-generated. Do not edit!


(when (boundp 'utils::heading_plot)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'heading_plot (find-package "UTILS")))
(unless (find-package "UTILS::HEADING_PLOT")
  (make-package "UTILS::HEADING_PLOT"))

(in-package "ROS")
;;//! \htmlinclude heading_plot.msg.html


(defclass utils::heading_plot
  :super ros::object
  :slots (_CurrX_indoor _exit_indoor ))

(defmethod utils::heading_plot
  (:init
   (&key
    ((:CurrX_indoor __CurrX_indoor) 0.0)
    ((:exit_indoor __exit_indoor) nil)
    )
   (send-super :init)
   (setq _CurrX_indoor (float __CurrX_indoor))
   (setq _exit_indoor __exit_indoor)
   self)
  (:CurrX_indoor
   (&optional __CurrX_indoor)
   (if __CurrX_indoor (setq _CurrX_indoor __CurrX_indoor)) _CurrX_indoor)
  (:exit_indoor
   (&optional __exit_indoor)
   (if __exit_indoor (setq _exit_indoor __exit_indoor)) _exit_indoor)
  (:serialization-length
   ()
   (+
    ;; float64 _CurrX_indoor
    8
    ;; bool _exit_indoor
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _CurrX_indoor
       (sys::poke _CurrX_indoor (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; bool _exit_indoor
       (if _exit_indoor (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _CurrX_indoor
     (setq _CurrX_indoor (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; bool _exit_indoor
     (setq _exit_indoor (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get utils::heading_plot :md5sum-) "4ed3e3540501bff48c532877c801a09c")
(setf (get utils::heading_plot :datatype-) "utils/heading_plot")
(setf (get utils::heading_plot :definition-)
      "float64 CurrX_indoor
bool exit_indoor
")



(provide :utils/heading_plot "4ed3e3540501bff48c532877c801a09c")


