console.log("A...");
const successcb=()=>{
  console.log("D...");
}
const errorcb=()=>{
  console.log("E...");
}
const result= fetch("https://dummyjson.com/products/users/Yashmalik004");
console.log("B...");
result.then(successcb).catch(errorcb);
console.log("C...");