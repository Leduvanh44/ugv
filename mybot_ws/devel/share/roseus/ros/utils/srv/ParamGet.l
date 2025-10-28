;; Auto-generated. Do not edit!


(when (boundp 'utils::ParamGet)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'ParamGet (find-package "UTILS")))
(unless (find-package "UTILS::PARAMGET")
  (make-package "UTILS::PARAMGET"))
(unless (find-package "UTILS::PARAMGETREQUEST")
  (make-package "UTILS::PARAMGETREQUEST"))
(unless (find-package "UTILS::PARAMGETRESPONSE")
  (make-package "UTILS::PARAMGETRESPONSE"))

(in-package "ROS")





(defclass utils::ParamGetRequest
  :super ros::object
  :slots (_param_id ))

(defmethod utils::ParamGetRequest
  (:init
   (&key
    ((:param_id __param_id) "")
    )
   (send-super :init)
   (setq _param_id (string __param_id))
   self)
  (:param_id
   (&optional __param_id)
   (if __param_id (setq _param_id __param_id)) _param_id)
  (:serialization-length
   ()
   (+
    ;; string _param_id
    4 (length _param_id)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _param_id
       (write-long (length _param_id) s) (princ _param_id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _param_id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _param_id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass utils::ParamGetResponse
  :super ros::object
  :slots (_success _value ))

(defmethod utils::ParamGetResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:value __value) (instance utils::ParamValue :init))
    )
   (send-super :init)
   (setq _success __success)
   (setq _value __value)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:value
   (&rest __value)
   (if (keywordp (car __value))
       (send* _value __value)
     (progn
       (if __value (setq _value (car __value)))
       _value)))
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; utils/ParamValue _value
    (send _value :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; utils/ParamValue _value
       (send _value :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; utils/ParamValue _value
     (send _value :deserialize buf ptr-) (incf ptr- (send _value :serialization-length))
   ;;
   self)
  )

(defclass utils::ParamGet
  :super ros::object
  :slots ())

(setf (get utils::ParamGet :md5sum-) "777d24d2a7ab1765ef009a69f464d2bc")
(setf (get utils::ParamGet :datatype-) "utils/ParamGet")
(setf (get utils::ParamGet :request) utils::ParamGetRequest)
(setf (get utils::ParamGet :response) utils::ParamGetResponse)

(defmethod utils::ParamGetRequest
  (:response () (instance utils::ParamGetResponse :init)))

(setf (get utils::ParamGetRequest :md5sum-) "777d24d2a7ab1765ef009a69f464d2bc")
(setf (get utils::ParamGetRequest :datatype-) "utils/ParamGetRequest")
(setf (get utils::ParamGetRequest :definition-)
      "# Request parameter from attached device

string param_id
---
bool success
utils/ParamValue value


================================================================================
MSG: utils/ParamValue
# Parameter value storage type.
#
# Integer and float fields:
#
# if integer != 0: it is integer value
# else if real != 0.0: it is float value
# else: it is zero.

int64 integer
float64 real
")

(setf (get utils::ParamGetResponse :md5sum-) "777d24d2a7ab1765ef009a69f464d2bc")
(setf (get utils::ParamGetResponse :datatype-) "utils/ParamGetResponse")
(setf (get utils::ParamGetResponse :definition-)
      "# Request parameter from attached device

string param_id
---
bool success
utils/ParamValue value


================================================================================
MSG: utils/ParamValue
# Parameter value storage type.
#
# Integer and float fields:
#
# if integer != 0: it is integer value
# else if real != 0.0: it is float value
# else: it is zero.

int64 integer
float64 real
")



(provide :utils/ParamGet "777d24d2a7ab1765ef009a69f464d2bc")


