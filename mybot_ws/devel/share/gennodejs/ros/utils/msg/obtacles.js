// Auto-generated. Do not edit!

// (in-package utils.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class obtacles {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.sonar_left = null;
      this.sonar_right = null;
      this.left_dis_sonar = null;
      this.right_dis_sonar = null;
      this.lidar = null;
      this.left_ver_lidar = null;
      this.right_ver_lidar = null;
      this.angle_avoid_lidar = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('sonar_left')) {
        this.sonar_left = initObj.sonar_left
      }
      else {
        this.sonar_left = false;
      }
      if (initObj.hasOwnProperty('sonar_right')) {
        this.sonar_right = initObj.sonar_right
      }
      else {
        this.sonar_right = false;
      }
      if (initObj.hasOwnProperty('left_dis_sonar')) {
        this.left_dis_sonar = initObj.left_dis_sonar
      }
      else {
        this.left_dis_sonar = 0.0;
      }
      if (initObj.hasOwnProperty('right_dis_sonar')) {
        this.right_dis_sonar = initObj.right_dis_sonar
      }
      else {
        this.right_dis_sonar = 0.0;
      }
      if (initObj.hasOwnProperty('lidar')) {
        this.lidar = initObj.lidar
      }
      else {
        this.lidar = false;
      }
      if (initObj.hasOwnProperty('left_ver_lidar')) {
        this.left_ver_lidar = initObj.left_ver_lidar
      }
      else {
        this.left_ver_lidar = 0.0;
      }
      if (initObj.hasOwnProperty('right_ver_lidar')) {
        this.right_ver_lidar = initObj.right_ver_lidar
      }
      else {
        this.right_ver_lidar = 0.0;
      }
      if (initObj.hasOwnProperty('angle_avoid_lidar')) {
        this.angle_avoid_lidar = initObj.angle_avoid_lidar
      }
      else {
        this.angle_avoid_lidar = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type obtacles
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [sonar_left]
    bufferOffset = _serializer.bool(obj.sonar_left, buffer, bufferOffset);
    // Serialize message field [sonar_right]
    bufferOffset = _serializer.bool(obj.sonar_right, buffer, bufferOffset);
    // Serialize message field [left_dis_sonar]
    bufferOffset = _serializer.float32(obj.left_dis_sonar, buffer, bufferOffset);
    // Serialize message field [right_dis_sonar]
    bufferOffset = _serializer.float32(obj.right_dis_sonar, buffer, bufferOffset);
    // Serialize message field [lidar]
    bufferOffset = _serializer.bool(obj.lidar, buffer, bufferOffset);
    // Serialize message field [left_ver_lidar]
    bufferOffset = _serializer.float32(obj.left_ver_lidar, buffer, bufferOffset);
    // Serialize message field [right_ver_lidar]
    bufferOffset = _serializer.float32(obj.right_ver_lidar, buffer, bufferOffset);
    // Serialize message field [angle_avoid_lidar]
    bufferOffset = _serializer.float32(obj.angle_avoid_lidar, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type obtacles
    let len;
    let data = new obtacles(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [sonar_left]
    data.sonar_left = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [sonar_right]
    data.sonar_right = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [left_dis_sonar]
    data.left_dis_sonar = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_dis_sonar]
    data.right_dis_sonar = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [lidar]
    data.lidar = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [left_ver_lidar]
    data.left_ver_lidar = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_ver_lidar]
    data.right_ver_lidar = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [angle_avoid_lidar]
    data.angle_avoid_lidar = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 23;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/obtacles';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9f846863e66577b5d671e0a2f062d383';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    bool sonar_left
    bool sonar_right
    
    float32 left_dis_sonar
    float32 right_dis_sonar
    
    bool lidar
    float32 left_ver_lidar
    float32 right_ver_lidar
    float32 angle_avoid_lidar
    
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new obtacles(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.sonar_left !== undefined) {
      resolved.sonar_left = msg.sonar_left;
    }
    else {
      resolved.sonar_left = false
    }

    if (msg.sonar_right !== undefined) {
      resolved.sonar_right = msg.sonar_right;
    }
    else {
      resolved.sonar_right = false
    }

    if (msg.left_dis_sonar !== undefined) {
      resolved.left_dis_sonar = msg.left_dis_sonar;
    }
    else {
      resolved.left_dis_sonar = 0.0
    }

    if (msg.right_dis_sonar !== undefined) {
      resolved.right_dis_sonar = msg.right_dis_sonar;
    }
    else {
      resolved.right_dis_sonar = 0.0
    }

    if (msg.lidar !== undefined) {
      resolved.lidar = msg.lidar;
    }
    else {
      resolved.lidar = false
    }

    if (msg.left_ver_lidar !== undefined) {
      resolved.left_ver_lidar = msg.left_ver_lidar;
    }
    else {
      resolved.left_ver_lidar = 0.0
    }

    if (msg.right_ver_lidar !== undefined) {
      resolved.right_ver_lidar = msg.right_ver_lidar;
    }
    else {
      resolved.right_ver_lidar = 0.0
    }

    if (msg.angle_avoid_lidar !== undefined) {
      resolved.angle_avoid_lidar = msg.angle_avoid_lidar;
    }
    else {
      resolved.angle_avoid_lidar = 0.0
    }

    return resolved;
    }
};

module.exports = obtacles;
