const { Player } = require("../model/playerSchema");

const createPlayerService = async (data) => {
    await Player.insertOne(data);
};

module.exports = { createPlayerService };