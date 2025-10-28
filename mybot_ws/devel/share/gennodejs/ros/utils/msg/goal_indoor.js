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

class goal_indoor {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.goal_indoor = null;
      this.way_x_0 = null;
      this.way_x_1 = null;
      this.way_x_2 = null;
      this.way_y_0 = null;
      this.way_y_1 = null;
      this.way_y_2 = null;
    }
    else {
      if (initObj.hasOwnProperty('goal_indoor')) {
        this.goal_indoor = initObj.goal_indoor
      }
      else {
        this.goal_indoor = 0.0;
      }
      if (initObj.hasOwnProperty('way_x_0')) {
        this.way_x_0 = initObj.way_x_0
      }
      else {
        this.way_x_0 = 0.0;
      }
      if (initObj.hasOwnProperty('way_x_1')) {
        this.way_x_1 = initObj.way_x_1
      }
      else {
        this.way_x_1 = 0.0;
      }
      if (initObj.hasOwnProperty('way_x_2')) {
        this.way_x_2 = initObj.way_x_2
      }
      else {
        this.way_x_2 = 0.0;
      }
      if (initObj.hasOwnProperty('way_y_0')) {
        this.way_y_0 = initObj.way_y_0
      }
      else {
        this.way_y_0 = 0.0;
      }
      if (initObj.hasOwnProperty('way_y_1')) {
        this.way_y_1 = initObj.way_y_1
      }
      else {
        this.way_y_1 = 0.0;
      }
      if (initObj.hasOwnProperty('way_y_2')) {
        this.way_y_2 = initObj.way_y_2
      }
      else {
        this.way_y_2 = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type goal_indoor
    // Serialize message field [goal_indoor]
    bufferOffset = _serializer.float32(obj.goal_indoor, buffer, bufferOffset);
    // Serialize message field [way_x_0]
    bufferOffset = _serializer.float32(obj.way_x_0, buffer, bufferOffset);
    // Serialize message field [way_x_1]
    bufferOffset = _serializer.float32(obj.way_x_1, buffer, bufferOffset);
    // Serialize message field [way_x_2]
    bufferOffset = _serializer.float32(obj.way_x_2, buffer, bufferOffset);
    // Serialize message field [way_y_0]
    bufferOffset = _serializer.float32(obj.way_y_0, buffer, bufferOffset);
    // Serialize message field [way_y_1]
    bufferOffset = _serializer.float32(obj.way_y_1, buffer, bufferOffset);
    // Serialize message field [way_y_2]
    bufferOffset = _serializer.float32(obj.way_y_2, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type goal_indoor
    let len;
    let data = new goal_indoor(null);
    // Deserialize message field [goal_indoor]
    data.goal_indoor = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [way_x_0]
    data.way_x_0 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [way_x_1]
    data.way_x_1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [way_x_2]
    data.way_x_2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [way_y_0]
    data.way_y_0 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [way_y_1]
    data.way_y_1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [way_y_2]
    data.way_y_2 = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/goal_indoor';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ad1b5000cc6755776de425ca68529153';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 goal_indoor
    
    float32 way_x_0
    float32 way_x_1
    float32 way_x_2 
    
    float32 way_y_0 
    float32 way_y_1 
    float32 way_y_2 
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new goal_indoor(null);
    if (msg.goal_indoor !== undefined) {
      resolved.goal_indoor = msg.goal_indoor;
    }
    else {
      resolved.goal_indoor = 0.0
    }

    if (msg.way_x_0 !== undefined) {
      resolved.way_x_0 = msg.way_x_0;
    }
    else {
      resolved.way_x_0 = 0.0
    }

    if (msg.way_x_1 !== undefined) {
      resolved.way_x_1 = msg.way_x_1;
    }
    else {
      resolved.way_x_1 = 0.0
    }

    if (msg.way_x_2 !== undefined) {
      resolved.way_x_2 = msg.way_x_2;
    }
    else {
      resolved.way_x_2 = 0.0
    }

    if (msg.way_y_0 !== undefined) {
      resolved.way_y_0 = msg.way_y_0;
    }
    else {
      resolved.way_y_0 = 0.0
    }

    if (msg.way_y_1 !== undefined) {
      resolved.way_y_1 = msg.way_y_1;
    }
    else {
      resolved.way_y_1 = 0.0
    }

    if (msg.way_y_2 !== undefined) {
      resolved.way_y_2 = msg.way_y_2;
    }
    else {
      resolved.way_y_2 = 0.0
    }

    return resolved;
    }
};

module.exports = goal_indoor;
