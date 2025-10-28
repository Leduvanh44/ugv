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

class heading_plot {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.CurrX_indoor = null;
      this.exit_indoor = null;
    }
    else {
      if (initObj.hasOwnProperty('CurrX_indoor')) {
        this.CurrX_indoor = initObj.CurrX_indoor
      }
      else {
        this.CurrX_indoor = 0.0;
      }
      if (initObj.hasOwnProperty('exit_indoor')) {
        this.exit_indoor = initObj.exit_indoor
      }
      else {
        this.exit_indoor = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type heading_plot
    // Serialize message field [CurrX_indoor]
    bufferOffset = _serializer.float64(obj.CurrX_indoor, buffer, bufferOffset);
    // Serialize message field [exit_indoor]
    bufferOffset = _serializer.bool(obj.exit_indoor, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type heading_plot
    let len;
    let data = new heading_plot(null);
    // Deserialize message field [CurrX_indoor]
    data.CurrX_indoor = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [exit_indoor]
    data.exit_indoor = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 9;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/heading_plot';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4ed3e3540501bff48c532877c801a09c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 CurrX_indoor
    bool exit_indoor
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new heading_plot(null);
    if (msg.CurrX_indoor !== undefined) {
      resolved.CurrX_indoor = msg.CurrX_indoor;
    }
    else {
      resolved.CurrX_indoor = 0.0
    }

    if (msg.exit_indoor !== undefined) {
      resolved.exit_indoor = msg.exit_indoor;
    }
    else {
      resolved.exit_indoor = false
    }

    return resolved;
    }
};

module.exports = heading_plot;
