const mongoose = require("mongoose");

mongoose
  .connect(process.env.MONGODB_URL, { dbName: "game-database" })
  .then(() => {
    console.log("------DB connected--------");
  })
  .catch((err) => {
    console.log("------ERROR in DB, NOT connected--------", err.message);
  });
