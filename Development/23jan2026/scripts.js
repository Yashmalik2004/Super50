// const username = prompt("what is your name? ");
// let age = prompt("what is your age? ");
// do {
//   age = prompt("enter valid age again!: ");
//   age=Number(age);
// } while (Number.isNaN(age) || age < 10 || age > 30);

// const branch = prompt("what is your branch? ");

// const student = {
//   name: username,
//   age,
//   branch,
//   Rollno: "2301010006",
// };

// console.log("student info : " +student);

// const obj={
//   0:"raj",
//   1:"ramesh",
//   2:"rakesh",
//   3:"rohan",
// };

// delete obj[0];
// obj["hello"]="world";
// console.log(obj);

// const arr=["raj","ramesh","rakesh","rohan"];
// arr.push("raghu");
// arr.splice(3,2,"yash","sneha");
// console.log(arr);

// const obj={name:"yash",city:"delhi"};

// console.log("keys: ",Object.keys(obj));
// console.log("value: ",Object.values(obj));
// console.log("entries: ",Object.entries(obj));

// function palindrome() {
//   let x = prompt("Enter string: ");
//   // let splitxt=x.split();
//   // console.log(splitxt);
//   // let splitbyspace=x.split(" ");
//   // console.log(splitbyspace);
//   let ans = x.split("").reverse().join("");
//   console.log(ans);
//   if (x === ans) {
//     console.log("YES");
//   } else {
//     console.log("NO");
//   }
// }
// palindrome();

// function print(val){
//   console.log('------------>');
//   console.log('----->',val)
//   console.log('------------>');
// }
// function sum(a,b, x){
//   const ans=a+b;
//   x(print)
// }

// const res=sum(15,33, print);
// //Hof= higher order functions-> a function that takes another function as a parameter or returns a function. eg: sum().
// //callbacks= a function which is passed as an arguement to another arguement. eg: print().

// //function assignment(function name assignment)
// const add=function sum(a,b){
//   const ans=a+b;
//   console.log(ans)
// }
// add(10,20);
// //function assignment(anonymous assignment)
// const add1=function (a,b){
//   const ans=a+b;
//   console.log(ans)
// }
// add1(10,20);
// //arrow function assignment
// const add2=(a,b) => {
//   const ans=a+b;
//   console.log(ans)
// }
// add2(10,20);
