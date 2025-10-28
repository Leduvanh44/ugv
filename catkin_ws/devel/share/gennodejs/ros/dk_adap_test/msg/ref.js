// Auto-generated. Do not edit!

// (in-package dk_adap_test.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class ref {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.points = null;
      this.vel = null;
      this.accel = null;
    }
    else {
      if (initObj.hasOwnProperty('points')) {
        this.points = initObj.points
      }
      else {
        this.points = [];
      }
      if (initObj.hasOwnProperty('vel')) {
        this.vel = initObj.vel
      }
      else {
        this.vel = [];
      }
      if (initObj.hasOwnProperty('accel')) {
        this.accel = initObj.accel
      }
      else {
        this.accel = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ref
    // Serialize message field [points]
    // Serialize the length for message field [points]
    bufferOffset = _serializer.uint32(obj.points.length, buffer, bufferOffset);
    obj.points.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [vel]
    // Serialize the length for message field [vel]
    bufferOffset = _serializer.uint32(obj.vel.length, buffer, bufferOffset);
    obj.vel.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [accel]
    // Serialize the length for message field [accel]
    bufferOffset = _serializer.uint32(obj.accel.length, buffer, bufferOffset);
    obj.accel.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ref
    let len;
    let data = new ref(null);
    // Deserialize message field [points]
    // Deserialize array length for message field [points]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.points = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.points[i] = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [vel]
    // Deserialize array length for message field [vel]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.vel = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.vel[i] = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [accel]
    // Deserialize array length for message field [accel]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.accel = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.accel[i] = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 24 * object.points.length;
    length += 24 * object.vel.length;
    length += 24 * object.accel.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'dk_adap_test/ref';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '77379297565095d4368ccb556eb253fa';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Point[] points
    geometry_msgs/Point[] vel
    geometry_msgs/Point[] accel
    
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ref(null);
    if (msg.points !== undefined) {
      resolved.points = new Array(msg.points.length);
      for (let i = 0; i < resolved.points.length; ++i) {
        resolved.points[i] = geometry_msgs.msg.Point.Resolve(msg.points[i]);
      }
    }
    else {
      resolved.points = []
    }

    if (msg.vel !== undefined) {
      resolved.vel = new Array(msg.vel.length);
      for (let i = 0; i < resolved.vel.length; ++i) {
        resolved.vel[i] = geometry_msgs.msg.Point.Resolve(msg.vel[i]);
      }
    }
    else {
      resolved.vel = []
    }

    if (msg.accel !== undefined) {
      resolved.accel = new Array(msg.accel.length);
      for (let i = 0; i < resolved.accel.length; ++i) {
        resolved.accel[i] = geometry_msgs.msg.Point.Resolve(msg.accel[i]);
      }
    }
    else {
      resolved.accel = []
    }

    return resolved;
    }
};

module.exports = ref;
