
const getData = () => {
  fetch("https://dummyjson.com/products?select=id,title,price,thumbnail")
    .then(successHandler)
    .catch(() => {
      alert("Error fetching data");
    });
};


const successHandler = (response) =>{
    console.log("RESPONSE-->",response);

    response.json().then(renderUI);
}

const rootElement = document.getElementById("root");

const renderUI = (data) =>{
    console.log("DATA-->",data); 

    const{products} = data;
    for(let i=0;i<products.length;i++){
      const product = products[i];

      const div = document.createElement("div");
      div.id="card";
      div.innerHTML=`
        <img src=${product.thumbnail} />
        <div>
        <h3>${product.title}</h3>
        <p>Price: $${product.price}</p>
        
        </div>
      `;
      rootElement.appendChild(div);
    }
}

getData();