;; Auto-generated. Do not edit!


(when (boundp 'utils::string_of_qrcode)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'string_of_qrcode (find-package "UTILS")))
(unless (find-package "UTILS::STRING_OF_QRCODE")
  (make-package "UTILS::STRING_OF_QRCODE"))

(in-package "ROS")
;;//! \htmlinclude string_of_qrcode.msg.html


(defclass utils::string_of_qrcode
  :super ros::object
  :slots (_string_of_qrcode ))

(defmethod utils::string_of_qrcode
  (:init
   (&key
    ((:string_of_qrcode __string_of_qrcode) "")
    )
   (send-super :init)
   (setq _string_of_qrcode (string __string_of_qrcode))
   self)
  (:string_of_qrcode
   (&optional __string_of_qrcode)
   (if __string_of_qrcode (setq _string_of_qrcode __string_of_qrcode)) _string_of_qrcode)
  (:serialization-length
   ()
   (+
    ;; string _string_of_qrcode
    4 (length _string_of_qrcode)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _string_of_qrcode
       (write-long (length _string_of_qrcode) s) (princ _string_of_qrcode s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _string_of_qrcode
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _string_of_qrcode (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get utils::string_of_qrcode :md5sum-) "e79ff6f588b017cff095149d881c6fca")
(setf (get utils::string_of_qrcode :datatype-) "utils/string_of_qrcode")
(setf (get utils::string_of_qrcode :definition-)
      "string string_of_qrcode
")



(provide :utils/string_of_qrcode "e79ff6f588b017cff095149d881c6fca")


