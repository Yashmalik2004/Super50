const express = require("express");
const mongoose = require("mongoose");

mongoose
  .connect(
    "mongodb://yashmalik:4B2pMF7XV7a8sZlB@ac-aax0yl7-shard-00-00.bwy1nz8.mongodb.net:27017,ac-aax0yl7-shard-00-01.bwy1nz8.mongodb.net:27017,ac-aax0yl7-shard-00-02.bwy1nz8.mongodb.net:27017/?ssl=true&replicaSet=atlas-79utbo-shard-0&authSource=admin&appName=Cluster0",
    {
      dbName: "YashDB",
    },
  )
  .then(() => {
    console.log("🔥🔥🔥-----DB connected-------✅✅✅");
  })
  .catch((err) => {
    console.log("error in DB connection", err.message);
  });

// const movieSchema = new mongoose.Schema({
//   title: String,
//   rating: Number,
//   releaseYear: Number,
//   description: String,
// });

//https://mongoosejs.com/docs/validation.html
const movieSchema = new mongoose.Schema({
  title: { type: String, required: true, unique: true, trim: true },
  rating: {
    type: Number,
    min: [1, "Too few! "],
    max: 10,
    required: [true, "Rating should be present between 1 to 10."],
  },
  releaseYear: { type: Number, default: 2000 },
  description: { type: String },
  origin: { type: String, enum: ["Bollywood", "Hollywood", "twitch"] },
});

const Movies = mongoose.model("movie", movieSchema);

const app = express();

//middleware
// app.use((req, res, next) => {
//   console.log("-->", req.url, ",", req.method);
//   next();
// });

app.use(express.json());

//Creating Movies\
//POST -- > http://localhost:3000/movies
app.post("/movies", async (req, res) => {
  try {
    const movieData = req.body;
    let result;
    try {
      result = await Movies.create(
        movieData,
        //   [
        //   {
        //     title: "ABCD",
        //     rating: 8,
        //     releaseYear: 2017,
        //     description: "xyzabc",
        //   },
        //   {
        //     title: "Monika Darling",
        //     rating: 10,
        //     releaseYear: 2069,
        //     description: "hole hole",
        //   },
        // ]
      );
    } catch (err) {
      res.status(400);
      res.json({
        success: false,
        message: err.message,
      });
      return;
    }
    console.log("result: ", result);
    res.status(201);
    res.json({
      success: true,
      message: "Movies inserted",
      data: result,
    });
  } catch (error) {
    console.log("FULL ERROR:", error.message);
    res.status(500).json({
      success: false,
      message: "Failed to insert movies",
      error: error.message,
    });
  }
});

//GET handler for "/"
app.get("/", (req, res) => {
  console.log(" /app route hit!");
  res.send("hello app");
});

//GET handler for "/users"
//GET -- > http://localhost:3000/users
app.get("/users", (req, res) => {
  console.log(" /users route hit!");
  res.send("hello users");
});

app.listen(3000, () => {
  console.log("Server is running on http://localhost:3000"); // port runs on OS level
});
