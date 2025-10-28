
(cl:in-package :asdf)

(defsystem "dk_adap_test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ref" :depends-on ("_package_ref"))
    (:file "_package_ref" :depends-on ("_package"))
    (:file "state" :depends-on ("_package_state"))
    (:file "_package_state" :depends-on ("_package"))
  ))