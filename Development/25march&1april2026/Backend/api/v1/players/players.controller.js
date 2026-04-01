const { createPlayerService } = require("../../../services/players.service.js");

const createPlayerController =  async (req, res) => {
  try {
    const data = req.body;

    const result = await createPlayerService(data);

    res.status(201).json({
      success: true,
      data: {
        player: result,
      },
    });
  } catch (err) {
    if (err.name === "ValidationError") {
      res.status(400);
      res.json({
        success: false,
        message:
          "validation failed, please check your input data" + err.message,
      });
    } else if (err.name === "MongoServerError" && err.code === 11000) {
      res.status(400);
      res.json({
        success: false,
        message:
          "Duplicate key error: A player with this username or email already exists." +
          err.message,
      });
    } else {
      console.log(err.name);
      console.log("Error in creating player", err.message);
      res.status(500);
      res.json({
        success: false,
        message: "Bhaiya ji apka code me error hai, player create nahi ho paya",
      });
    }
  }
};

module.exports = { createPlayerController };