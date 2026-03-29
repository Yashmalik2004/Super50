// const getDummyData = ()=>{
//   const request = fetch("https://dummyjson.com/products?limit=20");

//   request.
//   then((data)=>{
//     const pr2=data.json();

//     pr2.then((finalData)=>{
//       console.log(finalData);
//     })
//   }).
//   catch(()=>{console.log("--> Error Occured!")})
// };

// getDummyData();

console.log('A');
console.log('C');
console.log('D');
console.log('B');
console.log('E');
console.log('F');
console.log('G');

const getDummyData = async () => {
  try {
    const response = await fetch("https://jsonplaceholder.typicode.com/posts");
    const data = await response.json();

    console.log(data);
  } catch (err) {
    console.log("---->error", err.message);
  }
};

getDummyData();
