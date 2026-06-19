Please create a simple React (Vite) + Javascript app.
Follow the following guidelines:

1. Use React Router v7 using <BrowserRouter> <Routes> 
2. Make a constant file for all API Endpoints as well as frontend routes.
3. Use single Axios Instance for all API calls.
4. Tailwind CSS v4 (strictly v4) for styling.
5. Use shadcn/ui component library for basic components like input, button, ...
6. Use-React-Toastify library for toasts (create a centralized utility for it).
7. Manage error handling using try...catch and use errorToast instance to show errors or successToast instance to show success messages.
8. Store environment variables in .env.
9. Have a src Folder.
  Inside src folder, have these folders:
    api
    components
    hooks
    lib
    pages
    constants
    utils

10. No need to have:
    State management or context API
    Protected Routes
    Any validator or Provider for forms.

11. About the frontend:
  It will have
    Homepage
      - basic welcome section and then list products (10)
        - Use htps://dummyjson.com/products?limit=100 (use any random 10 products)
      - The search box at top with search button
      - Type anything in search box and then hit search - it will redirect to /find?q={{searchText+}}

    Search Page
      - It will show list of products
        - Use hhtps://dummyjson.com/products/search?q={{searchText}}
      - Clicking on any product will redirect the user to /view/{{product-id}}
    
    View Page
      - It will show the information of the products
        - Use hhtps://dummyjson.com/products/{{products-id}}

  There will be a navbar with Home button. Search box will also be on that navbar only.
  This will be visible to all the page, so lets make a layout for it.