const getTotalPrice = (data )=>{
  const {products} = data;

  let totalPrice=0;
  products.forEach((product)=>{
    totalPrice+=product.price;
  });

  console.log(totalPrice);
  return totalPrice;
}
const getProducts = async ()=>{
  try {
    const response = await fetch("https://dummyjson.com/products");
    const data = await response.json();
    return data;

  } catch (err) {
    console.log("---->error", err.message);
  }
};

const main = async () => {
  const data = await getProducts();

  if (!data) return;

  const totalPrice = getTotalPrice(data);

  console.log(totalPrice);
};

main();

