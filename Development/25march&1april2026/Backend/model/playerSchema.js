const {Schema, model} = require("mongoose");

const playerSchema = new Schema({
  name: {type: String,
    required: true,
    trim: true,
  },
  username: {
    type: String,
    required: true,
    trim: true,
    unique: true,
  },
  email:{
    type: String,
    required: true,
    unique: true,
    trim: true,
  },
  avatarURL: String,
  skills:[{
    type: String,
    enum: ["killing","survival","defense","dance"],
  },],
  description: String,
  
});

const Player = model("Player", playerSchema);

module.exports = {Player};