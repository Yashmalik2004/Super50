const express = require("express");
// const {Player} = require("../../../model/playerSchema.js"); //here we did Named export, where the name of the export and the name of the variable should be same. We can also do default export, where we can give any name to the variable while importing.

const {createPlayerController} = require("./players.controller.js");
const {validateCreatePlayerDto} = require("./dto/validatePlayerDto.js");

const playersRouter = express.Router();

playersRouter.post("/",validateCreatePlayerDto, createPlayerController);

module.exports = { playersRouter };
