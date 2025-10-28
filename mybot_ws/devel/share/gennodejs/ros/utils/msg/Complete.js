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

class Complete {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.complete = null;
      this.complete_indoor = null;
    }
    else {
      if (initObj.hasOwnProperty('complete')) {
        this.complete = initObj.complete
      }
      else {
        this.complete = false;
      }
      if (initObj.hasOwnProperty('complete_indoor')) {
        this.complete_indoor = initObj.complete_indoor
      }
      else {
        this.complete_indoor = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Complete
    // Serialize message field [complete]
    bufferOffset = _serializer.bool(obj.complete, buffer, bufferOffset);
    // Serialize message field [complete_indoor]
    bufferOffset = _serializer.bool(obj.complete_indoor, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Complete
    let len;
    let data = new Complete(null);
    // Deserialize message field [complete]
    data.complete = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [complete_indoor]
    data.complete_indoor = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/Complete';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ad8ef68768c0543c275c56756a7b1615';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool complete 
    bool complete_indoor
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Complete(null);
    if (msg.complete !== undefined) {
      resolved.complete = msg.complete;
    }
    else {
      resolved.complete = false
    }

    if (msg.complete_indoor !== undefined) {
      resolved.complete_indoor = msg.complete_indoor;
    }
    else {
      resolved.complete_indoor = false
    }

    return resolved;
    }
};

module.exports = Complete;
