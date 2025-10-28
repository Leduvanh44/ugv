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

class Position_avoid_obstacles {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.position_avoid_x = null;
      this.position_avoid_y = null;
      this.obstacles = null;
    }
    else {
      if (initObj.hasOwnProperty('position_avoid_x')) {
        this.position_avoid_x = initObj.position_avoid_x
      }
      else {
        this.position_avoid_x = 0.0;
      }
      if (initObj.hasOwnProperty('position_avoid_y')) {
        this.position_avoid_y = initObj.position_avoid_y
      }
      else {
        this.position_avoid_y = 0.0;
      }
      if (initObj.hasOwnProperty('obstacles')) {
        this.obstacles = initObj.obstacles
      }
      else {
        this.obstacles = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Position_avoid_obstacles
    // Serialize message field [position_avoid_x]
    bufferOffset = _serializer.float64(obj.position_avoid_x, buffer, bufferOffset);
    // Serialize message field [position_avoid_y]
    bufferOffset = _serializer.float64(obj.position_avoid_y, buffer, bufferOffset);
    // Serialize message field [obstacles]
    bufferOffset = _serializer.bool(obj.obstacles, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Position_avoid_obstacles
    let len;
    let data = new Position_avoid_obstacles(null);
    // Deserialize message field [position_avoid_x]
    data.position_avoid_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [position_avoid_y]
    data.position_avoid_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [obstacles]
    data.obstacles = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 17;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/Position_avoid_obstacles';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '323d00985a22ae750436ee67965d415b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 position_avoid_x
    float64 position_avoid_y
    
    bool obstacles 
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Position_avoid_obstacles(null);
    if (msg.position_avoid_x !== undefined) {
      resolved.position_avoid_x = msg.position_avoid_x;
    }
    else {
      resolved.position_avoid_x = 0.0
    }

    if (msg.position_avoid_y !== undefined) {
      resolved.position_avoid_y = msg.position_avoid_y;
    }
    else {
      resolved.position_avoid_y = 0.0
    }

    if (msg.obstacles !== undefined) {
      resolved.obstacles = msg.obstacles;
    }
    else {
      resolved.obstacles = false
    }

    return resolved;
    }
};

module.exports = Position_avoid_obstacles;
