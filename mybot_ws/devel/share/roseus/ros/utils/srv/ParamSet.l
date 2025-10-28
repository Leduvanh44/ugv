;; Auto-generated. Do not edit!


(when (boundp 'utils::ParamSet)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'ParamSet (find-package "UTILS")))
(unless (find-package "UTILS::PARAMSET")
  (make-package "UTILS::PARAMSET"))
(unless (find-package "UTILS::PARAMSETREQUEST")
  (make-package "UTILS::PARAMSETREQUEST"))
(unless (find-package "UTILS::PARAMSETRESPONSE")
  (make-package "UTILS::PARAMSETRESPONSE"))

(in-package "ROS")





(defclass utils::ParamSetRequest
  :super ros::object
  :slots (_param_id _value ))

(defmethod utils::ParamSetRequest
  (:init
   (&key
    ((:param_id __param_id) "")
    ((:value __value) (instance utils::ParamValue :init))
    )
   (send-super :init)
   (setq _param_id (string __param_id))
   (setq _value __value)
   self)
  (:param_id
   (&optional __param_id)
   (if __param_id (setq _param_id __param_id)) _param_id)
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
    ;; string _param_id
    4 (length _param_id)
    ;; utils/ParamValue _value
    (send _value :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _param_id
       (write-long (length _param_id) s) (princ _param_id s)
     ;; utils/ParamValue _value
       (send _value :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _param_id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _param_id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; utils/ParamValue _value
     (send _value :deserialize buf ptr-) (incf ptr- (send _value :serialization-length))
   ;;
   self)
  )

(defclass utils::ParamSetResponse
  :super ros::object
  :slots (_success _value ))

(defmethod utils::ParamSetResponse
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

(defclass utils::ParamSet
  :super ros::object
  :slots ())

(setf (get utils::ParamSet :md5sum-) "c423cafb898fff374cbe8530ecd4d285")
(setf (get utils::ParamSet :datatype-) "utils/ParamSet")
(setf (get utils::ParamSet :request) utils::ParamSetRequest)
(setf (get utils::ParamSet :response) utils::ParamSetResponse)

(defmethod utils::ParamSetRequest
  (:response () (instance utils::ParamSetResponse :init)))

(setf (get utils::ParamSetRequest :md5sum-) "c423cafb898fff374cbe8530ecd4d285")
(setf (get utils::ParamSetRequest :datatype-) "utils/ParamSetRequest")
(setf (get utils::ParamSetRequest :definition-)
      "# Request set parameter value

string param_id
ParamValue value

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

(setf (get utils::ParamSetResponse :md5sum-) "c423cafb898fff374cbe8530ecd4d285")
(setf (get utils::ParamSetResponse :datatype-) "utils/ParamSetResponse")
(setf (get utils::ParamSetResponse :definition-)
      "# Request set parameter value

string param_id
ParamValue value

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



(provide :utils/ParamSet "c423cafb898fff374cbe8530ecd4d285")


