const { Router } = require("express");
const { signupController} = require("./auth.controllers.js");
const {  loginController } = require("./auth.controllers.js");
const { validateSignup } = require("./auth.middlewares.js");
const { validateLogin} = require("./auth.middlewares.js")

const authRouter = Router();

authRouter.post("/signup", validateSignup, signupController);

authRouter.post("/login", validateLogin, loginController);

module.exports = { authRouter };
