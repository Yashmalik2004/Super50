console.log("start");

const fs=require('fs');

const readFileText = (i) => {
    fs.readFile("./data.txt","utf-8",(err,data) => {
      if(err){
        console.log("error: ",err.message);
      }
      else{
        const endTime = performance.now();
        console.log(i,"----->",endTime-startTime);
      }
    });
};

const startTime=performance.now();

for(let i=0;i<20;i++){
  readFileText(i);
};

const endTime= performance.now();

console.log(endTime-startTime, "end");