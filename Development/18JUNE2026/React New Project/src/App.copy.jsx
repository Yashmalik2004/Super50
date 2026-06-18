// to make a react component we must return something from the function and write code in pascal case and in js and html form.
import { useState } from "react";

function Main() {
  const [currentValue, updateFunction] = useState(0);
  let count = 0;
  console.log("-----------------------------------------------");
  console.log("Rendered value of current value: ", currentValue);

  const handleClick = () => {
    count++;
    updateFunction(currentValue + 1);
    console.log("Current value after click: ",currentValue);
  };
  console.log(count);
  return (
    <div>
      <h1> Count {currentValue}</h1>
      <button onClick={handleClick}>Click me</button>
    </div>
  );
}
export default Main;
