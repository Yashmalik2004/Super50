import { useEffect, useState } from "react";
import "./App.css";


function App() {
  const [data, setData] = useState([]);
  const [text, setText] = useState("");
  console.log("data: ", data);
  console.log("text: ", text);
  async function getData() {
    try {
      const res = await fetch(`https://dummyjson.com/products/search?q=${text}`);
      if (res.ok) {
        const result = await res.json();
        setData(result.products);
      } else {
        alert("Error fetching data");
      }
    } catch (err) {
      alert(err.message);
    }
  }
  function handleChange(e) {
    const result = e.target.value;
    setText(result);
  }

  useEffect(() => {
    getData();
  }, [text]);

  return (
    <>
      <div>
        <input onChange={handleChange} />
      </div>
      <div>
        {data.map((elem) => {
          return (
            <div key={elem.id}>
              <h2>{elem.title}</h2>
              <img src={elem.thumbnail} alt={elem.title} />
            </div>
          );
        })}
      </div>
    </>
  );
}

export default App;
