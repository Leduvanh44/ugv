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

class DiffVel {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.left_vel = null;
      this.right_vel = null;
      this.currHeading = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('left_vel')) {
        this.left_vel = initObj.left_vel
      }
      else {
        this.left_vel = 0.0;
      }
      if (initObj.hasOwnProperty('right_vel')) {
        this.right_vel = initObj.right_vel
      }
      else {
        this.right_vel = 0.0;
      }
      if (initObj.hasOwnProperty('currHeading')) {
        this.currHeading = initObj.currHeading
      }
      else {
        this.currHeading = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DiffVel
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [left_vel]
    bufferOffset = _serializer.float64(obj.left_vel, buffer, bufferOffset);
    // Serialize message field [right_vel]
    bufferOffset = _serializer.float64(obj.right_vel, buffer, bufferOffset);
    // Serialize message field [currHeading]
    bufferOffset = _serializer.float64(obj.currHeading, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DiffVel
    let len;
    let data = new DiffVel(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [left_vel]
    data.left_vel = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_vel]
    data.right_vel = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [currHeading]
    data.currHeading = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/DiffVel';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e25873c95bf62df7b9548a7e2e027143';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    float64 left_vel
    float64 right_vel
    
    float64 currHeading
    
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
    const resolved = new DiffVel(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.left_vel !== undefined) {
      resolved.left_vel = msg.left_vel;
    }
    else {
      resolved.left_vel = 0.0
    }

    if (msg.right_vel !== undefined) {
      resolved.right_vel = msg.right_vel;
    }
    else {
      resolved.right_vel = 0.0
    }

    if (msg.currHeading !== undefined) {
      resolved.currHeading = msg.currHeading;
    }
    else {
      resolved.currHeading = 0.0
    }

    return resolved;
    }
};

module.exports = DiffVel;
