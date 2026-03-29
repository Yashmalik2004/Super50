// read html file, populate it such way that there are multiple cars in the main tag.
// const fs = require("fs");
// fs.readFileSync("./ui/index.html", )

const {getDummyData,getIndexFile,getCardTemplateFile,saveOP} = require('./helper.js');
const fs = require('fs');

const indexFileText = getIndexFile();
const cardFileText = getCardTemplateFile();

const createUI = (data) =>{
  const {products} = data;

  let finalCardText = ``;
  products.forEach((ele)=>{

    let FilledTemplateText = cardFileText.replace("__IMG_LINK__",ele.thumbnail);
    FilledTemplateText = FilledTemplateText.replace("__TITLE__",ele.title);
    FilledTemplateText = FilledTemplateText.replace("VIEWS",ele.price);

    finalCardText+=`\n \t${FilledTemplateText} \n`
    
  });
  
  const finalHTML=indexFileText.replace("__PLACE_HOLDER__", finalCardText);
  saveOP(finalHTML);
}
getDummyData(createUI);






