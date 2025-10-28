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

class pointID {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pointID = null;
    }
    else {
      if (initObj.hasOwnProperty('pointID')) {
        this.pointID = initObj.pointID
      }
      else {
        this.pointID = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type pointID
    // Serialize message field [pointID]
    bufferOffset = _serializer.uint8(obj.pointID, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type pointID
    let len;
    let data = new pointID(null);
    // Deserialize message field [pointID]
    data.pointID = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/pointID';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e9ecd73bc27dcc76310bc664bc0605f0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 pointID
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new pointID(null);
    if (msg.pointID !== undefined) {
      resolved.pointID = msg.pointID;
    }
    else {
      resolved.pointID = 0
    }

    return resolved;
    }
};

module.exports = pointID;
