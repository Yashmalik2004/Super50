const mng = require("mongoose");
const URL = process.env.MONGODB_URL;

mng
    .connect(URL, {
        dbName: "hotels-management-tool",
    })
    .then(() => {
        console.log("------- DB Connected -------");
    })
    .catch((err) => {
        console.error("---- DB Connection Failed -----", err.message);
    });