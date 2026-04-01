const dotenv = require("dotenv");
dotenv.config(); //blocking sync
const express= require("express");
const morgan = require("morgan");
const {v1Router} = require("./api/v1/routes.js");


require("./config/database.js");

const app = express();

app.use(morgan("dev")); //request logging
app.use(express.json()); //body parser for json -- express will read the body in json format

app.use("/api/v1", v1Router);

const PORT = process.env.PORT ?? 3000;   // ?? = "Nullish Coalescing Operator"
// console.log("=========---->",process.env);

app.listen(PORT, () => {
  console.log("server started!");
});