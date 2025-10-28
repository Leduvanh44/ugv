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

class Error {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.along_track = null;
      this.cross_track = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('along_track')) {
        this.along_track = initObj.along_track
      }
      else {
        this.along_track = 0.0;
      }
      if (initObj.hasOwnProperty('cross_track')) {
        this.cross_track = initObj.cross_track
      }
      else {
        this.cross_track = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Error
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [along_track]
    bufferOffset = _serializer.float64(obj.along_track, buffer, bufferOffset);
    // Serialize message field [cross_track]
    bufferOffset = _serializer.float64(obj.cross_track, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Error
    let len;
    let data = new Error(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [along_track]
    data.along_track = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cross_track]
    data.cross_track = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/Error';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f6e8e9b3c251df9be04fce0859ad0cd8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    float64 along_track
    float64 cross_track
    
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
    const resolved = new Error(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.along_track !== undefined) {
      resolved.along_track = msg.along_track;
    }
    else {
      resolved.along_track = 0.0
    }

    if (msg.cross_track !== undefined) {
      resolved.cross_track = msg.cross_track;
    }
    else {
      resolved.cross_track = 0.0
    }

    return resolved;
    }
};

module.exports = Error;
