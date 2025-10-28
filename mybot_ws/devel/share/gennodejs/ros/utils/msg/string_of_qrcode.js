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

class string_of_qrcode {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.string_of_qrcode = null;
    }
    else {
      if (initObj.hasOwnProperty('string_of_qrcode')) {
        this.string_of_qrcode = initObj.string_of_qrcode
      }
      else {
        this.string_of_qrcode = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type string_of_qrcode
    // Serialize message field [string_of_qrcode]
    bufferOffset = _serializer.string(obj.string_of_qrcode, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type string_of_qrcode
    let len;
    let data = new string_of_qrcode(null);
    // Deserialize message field [string_of_qrcode]
    data.string_of_qrcode = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.string_of_qrcode.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'utils/string_of_qrcode';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e79ff6f588b017cff095149d881c6fca';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string string_of_qrcode
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new string_of_qrcode(null);
    if (msg.string_of_qrcode !== undefined) {
      resolved.string_of_qrcode = msg.string_of_qrcode;
    }
    else {
      resolved.string_of_qrcode = ''
    }

    return resolved;
    }
};

module.exports = string_of_qrcode;
