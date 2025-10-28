// Auto-generated. Do not edit!

// (in-package dk_adap_test.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class state {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.child_frame_id = null;
      this.x = null;
      this.y = null;
      this.phi = null;
      this.linear_velocity = null;
      this.angular_velocity = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('child_frame_id')) {
        this.child_frame_id = initObj.child_frame_id
      }
      else {
        this.child_frame_id = '';
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('phi')) {
        this.phi = initObj.phi
      }
      else {
        this.phi = 0.0;
      }
      if (initObj.hasOwnProperty('linear_velocity')) {
        this.linear_velocity = initObj.linear_velocity
      }
      else {
        this.linear_velocity = 0.0;
      }
      if (initObj.hasOwnProperty('angular_velocity')) {
        this.angular_velocity = initObj.angular_velocity
      }
      else {
        this.angular_velocity = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type state
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [child_frame_id]
    bufferOffset = _serializer.string(obj.child_frame_id, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.float64(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float64(obj.y, buffer, bufferOffset);
    // Serialize message field [phi]
    bufferOffset = _serializer.float64(obj.phi, buffer, bufferOffset);
    // Serialize message field [linear_velocity]
    bufferOffset = _serializer.float64(obj.linear_velocity, buffer, bufferOffset);
    // Serialize message field [angular_velocity]
    bufferOffset = _serializer.float64(obj.angular_velocity, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type state
    let len;
    let data = new state(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [child_frame_id]
    data.child_frame_id = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [phi]
    data.phi = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [linear_velocity]
    data.linear_velocity = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [angular_velocity]
    data.angular_velocity = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.child_frame_id.length;
    return length + 44;
  }

  static datatype() {
    // Returns string type for a message object
    return 'dk_adap_test/state';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '140a803ed3c5e06fc1dbfe9d2d41136d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    string child_frame_id
    
    float64 x
    float64 y
    float64 phi
    float64 linear_velocity
    float64 angular_velocity
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
    const resolved = new state(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.child_frame_id !== undefined) {
      resolved.child_frame_id = msg.child_frame_id;
    }
    else {
      resolved.child_frame_id = ''
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.phi !== undefined) {
      resolved.phi = msg.phi;
    }
    else {
      resolved.phi = 0.0
    }

    if (msg.linear_velocity !== undefined) {
      resolved.linear_velocity = msg.linear_velocity;
    }
    else {
      resolved.linear_velocity = 0.0
    }

    if (msg.angular_velocity !== undefined) {
      resolved.angular_velocity = msg.angular_velocity;
    }
    else {
      resolved.angular_velocity = 0.0
    }

    return resolved;
    }
};

module.exports = state;
