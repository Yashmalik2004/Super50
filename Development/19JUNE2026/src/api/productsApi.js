import axiosInstance from './axiosInstance'
import { ENDPOINTS } from '@/constants/endpoints'

// Fetch a list of products (with optional limit)
export const fetchProducts = async (limit = 100) => {
  const response = await axiosInstance.get(ENDPOINTS.GET_PRODUCTS, {
    params: { limit },
  })
  return response.data
}

// Search products by query string
export const searchProducts = async (query) => {
  const response = await axiosInstance.get(ENDPOINTS.SEARCH_PRODUCTS, {
    params: { q: query },
  })
  return response.data
}

// Fetch a single product by id
export const fetchProductById = async (id) => {
  const response = await axiosInstance.get(ENDPOINTS.GET_PRODUCT_BY_ID(id))
  return response.data
}
