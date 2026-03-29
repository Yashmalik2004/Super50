console.log("start");

const fsPromise = require("fs/promises");

const readFileText = async (i) => {
  try {
    const data = await fsPromise.readFile("./data.txt", "utf-8");
    const endTime = performance.now();
    console.log(i, "----->", endTime - startTime);
  } catch (err) {
    console.log("file reading error: ", err.message);
  }
};

const startTime = performance.now();

for (let i = 0; i < 20; i++) {
  readFileText(i);
}

const endTime = performance.now();

console.log(endTime - startTime, "end");
