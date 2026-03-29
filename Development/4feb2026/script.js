// console.log("script start");

// const pyes=()=>{
//   console.log("yes");
// }
// const pno=()=>{
//   console.log("no");
// }

// const sum=(a,b,cb)=>{
//   console.log("calculation started");
//   const ans=a+b;
//   window.setTimeout(pno,0);
//   cb(ans);
//   console.log("calculation almost done");

// }
// sum(12,13,pyes);
// console.log("script end");

// console.log("script start");

// const successData = (res) =>{
//   console.log("successData called-->",res);
// };
// const pyes=(res)=>{
//   console.log("yes");
//   res.json().then(successData);
// }
// const pno=(res)=>{
//   console.log("no");
// }
// window.fetch("https://dummyjson.com/products").then(pyes).catch(pno);
// console.log("script end");
//-----------------------------------------------------------
// console.log(window);

// console.dir(window.document);

// const rootele=window.document.getElementById("root");
// console.log("root element: ", rootele);

// rootele.innerHTML="<h1>Hello World</h1>";
// rootele.style.backgroundColor="blue";
// rootele.style.padding="20px";

//-----------------------------------------------------------

const rootele=window.document.getElementById("root");

const title=document.getElementsByTagName("h1");

title.innerText="Hello World";
title.className="text-type-1";

rootele.appendChild(title);


