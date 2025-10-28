;; Auto-generated. Do not edit!


(when (boundp 'utils::SetMode)
  (if (not (find-package "UTILS"))
    (make-package "UTILS"))
  (shadow 'SetMode (find-package "UTILS")))
(unless (find-package "UTILS::SETMODE")
  (make-package "UTILS::SETMODE"))
(unless (find-package "UTILS::SETMODEREQUEST")
  (make-package "UTILS::SETMODEREQUEST"))
(unless (find-package "UTILS::SETMODERESPONSE")
  (make-package "UTILS::SETMODERESPONSE"))

(in-package "ROS")





(intern "*MAV_MODE_PREFLIGHT*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_PREFLIGHT* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_PREFLIGHT* 0)
(intern "*MAV_MODE_STABILIZE_DISARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_STABILIZE_DISARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_STABILIZE_DISARMED* 80)
(intern "*MAV_MODE_STABILIZE_ARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_STABILIZE_ARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_STABILIZE_ARMED* 208)
(intern "*MAV_MODE_MANUAL_DISARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_MANUAL_DISARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_MANUAL_DISARMED* 64)
(intern "*MAV_MODE_MANUAL_ARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_MANUAL_ARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_MANUAL_ARMED* 192)
(intern "*MAV_MODE_GUIDED_DISARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_GUIDED_DISARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_GUIDED_DISARMED* 88)
(intern "*MAV_MODE_GUIDED_ARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_GUIDED_ARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_GUIDED_ARMED* 216)
(intern "*MAV_MODE_AUTO_DISARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_AUTO_DISARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_AUTO_DISARMED* 92)
(intern "*MAV_MODE_AUTO_ARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_AUTO_ARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_AUTO_ARMED* 220)
(intern "*MAV_MODE_TEST_DISARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_TEST_DISARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_TEST_DISARMED* 66)
(intern "*MAV_MODE_TEST_ARMED*" (find-package "UTILS::SETMODEREQUEST"))
(shadow '*MAV_MODE_TEST_ARMED* (find-package "UTILS::SETMODEREQUEST"))
(defconstant utils::SetModeRequest::*MAV_MODE_TEST_ARMED* 194)
(defclass utils::SetModeRequest
  :super ros::object
  :slots (_base_mode _custom_mode ))

(defmethod utils::SetModeRequest
  (:init
   (&key
    ((:base_mode __base_mode) 0)
    ((:custom_mode __custom_mode) "")
    )
   (send-super :init)
   (setq _base_mode (round __base_mode))
   (setq _custom_mode (string __custom_mode))
   self)
  (:base_mode
   (&optional __base_mode)
   (if __base_mode (setq _base_mode __base_mode)) _base_mode)
  (:custom_mode
   (&optional __custom_mode)
   (if __custom_mode (setq _custom_mode __custom_mode)) _custom_mode)
  (:serialization-length
   ()
   (+
    ;; uint8 _base_mode
    1
    ;; string _custom_mode
    4 (length _custom_mode)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _base_mode
       (write-byte _base_mode s)
     ;; string _custom_mode
       (write-long (length _custom_mode) s) (princ _custom_mode s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _base_mode
     (setq _base_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _custom_mode
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _custom_mode (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass utils::SetModeResponse
  :super ros::object
  :slots (_mode_sent ))

(defmethod utils::SetModeResponse
  (:init
   (&key
    ((:mode_sent __mode_sent) nil)
    )
   (send-super :init)
   (setq _mode_sent __mode_sent)
   self)
  (:mode_sent
   (&optional __mode_sent)
   (if __mode_sent (setq _mode_sent __mode_sent)) _mode_sent)
  (:serialization-length
   ()
   (+
    ;; bool _mode_sent
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _mode_sent
       (if _mode_sent (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _mode_sent
     (setq _mode_sent (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass utils::SetMode
  :super ros::object
  :slots ())

(setf (get utils::SetMode :md5sum-) "e4f18fa93379f9ff1780d270ce110203")
(setf (get utils::SetMode :datatype-) "utils/SetMode")
(setf (get utils::SetMode :request) utils::SetModeRequest)
(setf (get utils::SetMode :response) utils::SetModeResponse)

(defmethod utils::SetModeRequest
  (:response () (instance utils::SetModeResponse :init)))

(setf (get utils::SetModeRequest :md5sum-) "e4f18fa93379f9ff1780d270ce110203")
(setf (get utils::SetModeRequest :datatype-) "utils/SetModeRequest")
(setf (get utils::SetModeRequest :definition-)
      "# set FCU mode
#
# Known custom modes listed here:
# http://wiki.ros.org/mavros/CustomModes

# basic modes from MAV_MODE
uint8 MAV_MODE_PREFLIGHT		= 0
uint8 MAV_MODE_STABILIZE_DISARMED	= 80
uint8 MAV_MODE_STABILIZE_ARMED		= 208
uint8 MAV_MODE_MANUAL_DISARMED		= 64
uint8 MAV_MODE_MANUAL_ARMED		= 192
uint8 MAV_MODE_GUIDED_DISARMED		= 88
uint8 MAV_MODE_GUIDED_ARMED		= 216
uint8 MAV_MODE_AUTO_DISARMED		= 92
uint8 MAV_MODE_AUTO_ARMED		= 220
uint8 MAV_MODE_TEST_DISARMED		= 66
uint8 MAV_MODE_TEST_ARMED		= 194

uint8 base_mode		# filled by MAV_MODE enum value or 0 if custom_mode != ''
string custom_mode	# string mode representation or integer
---
bool mode_sent		# Mode known/parsed correctly and SET_MODE are sent

")

(setf (get utils::SetModeResponse :md5sum-) "e4f18fa93379f9ff1780d270ce110203")
(setf (get utils::SetModeResponse :datatype-) "utils/SetModeResponse")
(setf (get utils::SetModeResponse :definition-)
      "# set FCU mode
#
# Known custom modes listed here:
# http://wiki.ros.org/mavros/CustomModes

# basic modes from MAV_MODE
uint8 MAV_MODE_PREFLIGHT		= 0
uint8 MAV_MODE_STABILIZE_DISARMED	= 80
uint8 MAV_MODE_STABILIZE_ARMED		= 208
uint8 MAV_MODE_MANUAL_DISARMED		= 64
uint8 MAV_MODE_MANUAL_ARMED		= 192
uint8 MAV_MODE_GUIDED_DISARMED		= 88
uint8 MAV_MODE_GUIDED_ARMED		= 216
uint8 MAV_MODE_AUTO_DISARMED		= 92
uint8 MAV_MODE_AUTO_ARMED		= 220
uint8 MAV_MODE_TEST_DISARMED		= 66
uint8 MAV_MODE_TEST_ARMED		= 194

uint8 base_mode		# filled by MAV_MODE enum value or 0 if custom_mode != ''
string custom_mode	# string mode representation or integer
---
bool mode_sent		# Mode known/parsed correctly and SET_MODE are sent

")



(provide :utils/SetMode "e4f18fa93379f9ff1780d270ce110203")


