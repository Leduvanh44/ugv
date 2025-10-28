;; Auto-generated. Do not edit!


(when (boundp 'dk_adap_test::ref)
  (if (not (find-package "DK_ADAP_TEST"))
    (make-package "DK_ADAP_TEST"))
  (shadow 'ref (find-package "DK_ADAP_TEST")))
(unless (find-package "DK_ADAP_TEST::REF")
  (make-package "DK_ADAP_TEST::REF"))

(in-package "ROS")
;;//! \htmlinclude ref.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass dk_adap_test::ref
  :super ros::object
  :slots (_points _vel _accel ))

(defmethod dk_adap_test::ref
  (:init
   (&key
    ((:points __points) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Point :init) r)) r))
    ((:vel __vel) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Point :init) r)) r))
    ((:accel __accel) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Point :init) r)) r))
    )
   (send-super :init)
   (setq _points __points)
   (setq _vel __vel)
   (setq _accel __accel)
   self)
  (:points
   (&rest __points)
   (if (keywordp (car __points))
       (send* _points __points)
     (progn
       (if __points (setq _points (car __points)))
       _points)))
  (:vel
   (&rest __vel)
   (if (keywordp (car __vel))
       (send* _vel __vel)
     (progn
       (if __vel (setq _vel (car __vel)))
       _vel)))
  (:accel
   (&rest __accel)
   (if (keywordp (car __accel))
       (send* _accel __accel)
     (progn
       (if __accel (setq _accel (car __accel)))
       _accel)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point[] _points
    (apply #'+ (send-all _points :serialization-length)) 4
    ;; geometry_msgs/Point[] _vel
    (apply #'+ (send-all _vel :serialization-length)) 4
    ;; geometry_msgs/Point[] _accel
    (apply #'+ (send-all _accel :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point[] _points
     (write-long (length _points) s)
     (dolist (elem _points)
       (send elem :serialize s)
       )
     ;; geometry_msgs/Point[] _vel
     (write-long (length _vel) s)
     (dolist (elem _vel)
       (send elem :serialize s)
       )
     ;; geometry_msgs/Point[] _accel
     (write-long (length _accel) s)
     (dolist (elem _accel)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point[] _points
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _points (let (r) (dotimes (i n) (push (instance geometry_msgs::Point :init) r)) r))
     (dolist (elem- _points)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; geometry_msgs/Point[] _vel
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _vel (let (r) (dotimes (i n) (push (instance geometry_msgs::Point :init) r)) r))
     (dolist (elem- _vel)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; geometry_msgs/Point[] _accel
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _accel (let (r) (dotimes (i n) (push (instance geometry_msgs::Point :init) r)) r))
     (dolist (elem- _accel)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get dk_adap_test::ref :md5sum-) "77379297565095d4368ccb556eb253fa")
(setf (get dk_adap_test::ref :datatype-) "dk_adap_test/ref")
(setf (get dk_adap_test::ref :definition-)
      "geometry_msgs/Point[] points
geometry_msgs/Point[] vel
geometry_msgs/Point[] accel


================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :dk_adap_test/ref "77379297565095d4368ccb556eb253fa")


