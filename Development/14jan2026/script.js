"use strict";

// function sum(a, b) {
//   console.log(a + b);
//   if (true) {
//     let c = 90;
//     console.log(c);
//   }
// }
// sum(4, 6);
//------------------------------------------------
// function sum(a, b) {
//   console.log(a + b);
//   if (true) {
//     var c = 90;
//     console.log(c);
//   }
//   console.log(c);
// }
// sum(4, 6);

//------------------------------------------------
// function sum(a, b) {
//   console.log(a + b);
//   if (true) {
//     var c;
//     console.log(c);
//   }
//   console.log(c);
// }
// sum(4, 6);
//------------------------------------------------
// console.log("START");

// function sum(a, b) {
//   console.log(a + b);
//   if (true) {
//     let c;
//     console.log(c);
//   }
//   console.log("sum done...");
// }
// sum(4, 6);

// console.log("END");
//------------------------------------------------
console.log(c);

var c=100;
console.log(c);
var c=200;
console.log(c);

// in var u can redeclare and reassign
// in let u can reassign but cannot redeclare
// in const u cannot redeclare and cannot reassign

// when u write a code, memory is allocated in two phases
// 1. creation phase
// 2. execution phase
// in creation phase memory is allocated and in execution phase memory is assigned values
// in creation phase var is assigned undefined, let and const are not assigned any value
// so if we try to access let and const before initialization we get reference error
// this phase is called temporal dead zone
// in creation phase var is hoisted, let and const are not hoisted

// hoisting is a mechanism where variables and function declarations are moved to the top of their scope before code execution
// this means that you can use variables and functions before they are declared in the code
// however, only the declarations are hoisted, not the initializations