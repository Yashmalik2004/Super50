const fs= require('fs');

const getIndexFile = () =>{
  const data = fs.readFileSync("./ui/index.html","utf-8");
  return data;
};
const getCardTemplateFile = () =>{
  const data = fs.readFileSync("./ui/card-template.html","utf-8");
  return data;
};


//request here is a promise, promise represents eventual completion or rejection of a "asynchronous process". Promise have three states : 1. pending, 2. fullfilled, 3. rejected.
const getDummyData = (successCallback)=>{
  const request = fetch("https://dummyjson.com/products?limit=20");

  request.
  then((data)=>{
    const pr2=data.json();

    pr2.then((finalData)=>{
      successCallback(finalData);
    })
  }).
  catch(()=>{console.log("--> Error Occured!")})
};

const saveOP=(htmltext)=>{
  fs.writeFileSync("output.html",htmltext);
}

module.exports= {getIndexFile,getDummyData,getCardTemplateFile,saveOP};
