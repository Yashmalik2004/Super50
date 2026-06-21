import { useState, useEffect } from 'react'
import { fetchProducts } from '@/api/productsApi'
import { errorToast } from '@/utils/toast'

// Hook to fetch a list of products
const useProducts = (limit = 100) => {
  const [products, setProducts] = useState([])
  const [loading, setLoading] = useState(true)
  const [error, setError] = useState(null)

  useEffect(() => {
    const load = async () => {
      try {
        setLoading(true)
        const data = await fetchProducts(limit)
        setProducts(data.products || [])
      } catch (err) {
        setError(err)
        errorToast(err?.response?.data?.message || 'Failed to fetch products.')
      } finally {
        setLoading(false)
      }
    }
    load()
  }, [limit])

  return { products, loading, error }
}

export default useProducts
