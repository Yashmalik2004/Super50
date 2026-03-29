// window.console.log(window.document);
// console.dir(window.document.children[0]);
// const h1ele=window.document.children[0].children[1].children[0].children[0];

// const h1Element = document.getElementsByTagName("h1");
// const PElement = document.getElementsByTagName("p");
// console.log(h1Element)
// h1Element[0].style.backgroundColor="purple";
// h1Element[1].style.backgroundColor="red";
// PElement[0].style.backgroundColor="green";

let flag = true;
const highlightheading = () => {
  const h1Element = document.getElementsByTagName("h1");
  const pElement = document.getElementsByTagName("p");
  if (flag) {
    h1Element[0].style.backgroundColor = "purple";
    pElement[0].style.backgroundColor = "green";
  } else {
    h1Element[0].style.backgroundColor = "red";
    pElement[0].style.backgroundColor = "blue";
  }
  flag = !flag;
};



























































































































































































