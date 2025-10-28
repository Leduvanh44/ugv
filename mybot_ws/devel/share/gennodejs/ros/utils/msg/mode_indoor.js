// Auto-generated. Do not edit!

// (in-package utils.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class mode_indoor {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mode_indoor = null;
      this.set_complete_indoor = null;
      this.abc = null;
    }
    else {
      if (initObj.hasOwnProperty('mode_indoor')) {
        this.mode_indoor = initObj.mode_indoor
      }
      else {
        this.mode_indoor = 0;
      }
      if (initObj.hasOwnProperty('set_complete_indoor')) {
        this.set_complete_indoor = initObj.set_complete_indoor
      }
      else {
        this.set_complete_indoor = false;
      }
      if (initObj.hasOwnProperty('abc')) {
        this.abc = initObj.abc
      }
      else {
        this.abc = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type mode_indoor
    // Serialize message field [mode_indoor]
    bufferOffset = _serializer.uint8(obj.mode_indoor, buffer, bufferOffset);
    // Serialize message field [set_complete_indoor]
    bufferOffset = _serializer.bool(obj.set_complete_indoor, buffer, bufferOffset);
    // Serialize message field [abc]
    bufferOffset = _serializer.float64(obj.abc, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type mode_indoor
    let len;
    let data = new mode_indoor(null);
    // Deserialize message field [mode_indoor]
    data.mode_indoor = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [set_complete_indoor]
    data.set_complete_indoor = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [abc]
    data.abc = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 10;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/mode_indoor';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dcef5ac4b0e09704e023b93597e3b078';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 mode_indoor
    bool set_complete_indoor
    float64 abc
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new mode_indoor(null);
    if (msg.mode_indoor !== undefined) {
      resolved.mode_indoor = msg.mode_indoor;
    }
    else {
      resolved.mode_indoor = 0
    }

    if (msg.set_complete_indoor !== undefined) {
      resolved.set_complete_indoor = msg.set_complete_indoor;
    }
    else {
      resolved.set_complete_indoor = false
    }

    if (msg.abc !== undefined) {
      resolved.abc = msg.abc;
    }
    else {
      resolved.abc = 0.0
    }

    return resolved;
    }
};

module.exports = mode_indoor;
