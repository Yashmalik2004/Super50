const getData = async() => {
  try{
    const response = await fetch("https://dummyjson.com/products");
    const data = await response.json();
    return data;
  }
  catch(err){
    alert(`API call failed: ${err.message}`);
  }
};

const renderCards= (data) => {
  const newDiv = document.createElement('div');
  const {products} = data;

  products.forEach((products)=>{
    const cardContainer = document.createElement('div');
    
  })
}