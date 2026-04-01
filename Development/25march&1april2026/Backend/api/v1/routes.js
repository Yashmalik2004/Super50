const express= require("express");
// const {Player} = require("../../model/playerSchema.js"); //here we did Named export, where the name of the export and the name of the variable should be same. We can also do default export, where we can give any name to the variable while importing.

const {playersRouter} = require("./players/routes.js")

const v1Router = express.Router();

v1Router.use("/players",playersRouter);

module.exports= {v1Router};
