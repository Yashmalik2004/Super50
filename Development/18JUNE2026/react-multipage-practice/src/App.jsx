import {BrowserRouter , Routes, Route} from 'react-router';
function App(){
  return(
    <div>
      <BrowserRouter>
        <Routes>
          <Route path='/' element={<h1>Home</h1>}></Route>
          <Route path='/about' element={<h1>About</h1>}></Route>
          <Route path='/contact' element={<h1>Contact</h1>}></Route>
          <Route path='*' element={<h1>Not Found</h1>}></Route>
        </Routes>
      </BrowserRouter>
    </div>
  )
}
export default App;