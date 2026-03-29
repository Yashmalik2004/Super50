console.log("RENDER START");

const { stringify } = require("querystring");
const getData = require("./data.js");
const fs = require("fs");

const render = () => {
  const data = getData();
  fs.writeFileSync("output.html",data);
};

console.log("RENDER END");

module.exports = render;
