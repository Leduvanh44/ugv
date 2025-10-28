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

class distance_msgs {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.dis_x = null;
      this.dis_y = null;
      this.orient_z = null;
      this.orient_w = null;
    }
    else {
      if (initObj.hasOwnProperty('dis_x')) {
        this.dis_x = initObj.dis_x
      }
      else {
        this.dis_x = 0.0;
      }
      if (initObj.hasOwnProperty('dis_y')) {
        this.dis_y = initObj.dis_y
      }
      else {
        this.dis_y = 0.0;
      }
      if (initObj.hasOwnProperty('orient_z')) {
        this.orient_z = initObj.orient_z
      }
      else {
        this.orient_z = 0.0;
      }
      if (initObj.hasOwnProperty('orient_w')) {
        this.orient_w = initObj.orient_w
      }
      else {
        this.orient_w = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type distance_msgs
    // Serialize message field [dis_x]
    bufferOffset = _serializer.float64(obj.dis_x, buffer, bufferOffset);
    // Serialize message field [dis_y]
    bufferOffset = _serializer.float64(obj.dis_y, buffer, bufferOffset);
    // Serialize message field [orient_z]
    bufferOffset = _serializer.float64(obj.orient_z, buffer, bufferOffset);
    // Serialize message field [orient_w]
    bufferOffset = _serializer.float64(obj.orient_w, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type distance_msgs
    let len;
    let data = new distance_msgs(null);
    // Deserialize message field [dis_x]
    data.dis_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [dis_y]
    data.dis_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [orient_z]
    data.orient_z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [orient_w]
    data.orient_w = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/distance_msgs';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '755117db4347f5445de21da69b3fd8c0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 dis_x
    float64 dis_y
    float64 orient_z 
    float64 orient_w
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new distance_msgs(null);
    if (msg.dis_x !== undefined) {
      resolved.dis_x = msg.dis_x;
    }
    else {
      resolved.dis_x = 0.0
    }

    if (msg.dis_y !== undefined) {
      resolved.dis_y = msg.dis_y;
    }
    else {
      resolved.dis_y = 0.0
    }

    if (msg.orient_z !== undefined) {
      resolved.orient_z = msg.orient_z;
    }
    else {
      resolved.orient_z = 0.0
    }

    if (msg.orient_w !== undefined) {
      resolved.orient_w = msg.orient_w;
    }
    else {
      resolved.orient_w = 0.0
    }

    return resolved;
    }
};

module.exports = distance_msgs;
