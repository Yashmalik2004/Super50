const data = {
  imgURL: "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQf1fiSQO7JfDw0uv1Ae_Ye-Bo9nhGNg27dwg&s",
  name : "Yash malik",
  batch: "CSE-A",
  college : "KRMU",
}

const rootElement =  document.getElementById("root");
// const newDivElement = document.createElement("div");

// const imgElement = document.createElement("img");
// imgElement.src = data.imgURL;
// imgElement.alt = "Profile Image";

// const nameElement = document.createElement("h1");
// nameElement.textContent = data.name;

// const batchElement = document.createElement("p");
// batchElement.textContent = `Batch: ${data.batch}`;

// const collegeElement = document.createElement("p");
// collegeElement.textContent = `College: ${data.college}`;

// rootElement.appendChild(imgElement);
// rootElement.appendChild(newDivElement);
// newDivElement.appendChild(nameElement);
// newDivElement.appendChild(batchElement);
// newDivElement.appendChild(collegeElement);

rootElement.innerHTML=`
<img id='user-img' src="${data.imgURL}">
<div>
    <h1>${data.name}</h1>
    <p>Batch: ${data.batch}</p>
    <p>College: ${data.college}</p>
</div>
`;



    