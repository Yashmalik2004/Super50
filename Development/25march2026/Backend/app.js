const dotenv = require("dotenv");
dotenv.config(); //blocking sync
const express= require("express");
const morgan = require("morgan");
const {v1Router} = require("./api/routes.js")


require("./config/database.js");

const app = express();

app.use(morgan("dev")); //request logging

app.use("/api/v1", v1Router);

const PORT = process.env ?? 3000;   // ?? = "Nullish Coalescing Operator"
// console.log("=========---->",process.env);

app.listen(PORT, () => {
  console.log("server started!");
})