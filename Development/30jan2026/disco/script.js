const rootElement = document.getElementById('root');
rootElement.style.backgroundColor="black";
const getrandomColor=()=>{
  const randomVal= Math.random();
  
  const scaledValue= randomVal * 255;
  const floorVal= Math.floor(scaledValue);
  return floorVal;
}


const callbackFunction=() =>{
  // console.log(Math.random());
  const red= getrandomColor();
  const green= getrandomColor();
  const blue= getrandomColor();

  rootElement.style.backgroundColor=`rgb(${red}, ${green}, ${blue})`;
  rootElement.style.boxShadow=`rgb(${red}, ${green}, ${blue})`;
  //homework: instead of rgb use hexcode
}

// const delay=3000;
// setTimeout(callbackFunction, delay)


window.setInterval(callbackFunction, 100)