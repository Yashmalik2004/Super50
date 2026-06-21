import { useState, useEffect } from 'react'
import { searchProducts } from '@/api/productsApi'
import { errorToast } from '@/utils/toast'

// Hook to search products by query
const useSearchProducts = (query) => {
  const [products, setProducts] = useState([])
  const [loading, setLoading] = useState(false)
  const [error, setError] = useState(null)

  useEffect(() => {
    if (!query) return

    const load = async () => {
      try {
        setLoading(true)
        setError(null)
        const data = await searchProducts(query)
        setProducts(data.products || [])
      } catch (err) {
        setError(err)
        errorToast(err?.response?.data?.message || 'Failed to search products.')
      } finally {
        setLoading(false)
      }
    }
    load()
  }, [query])

  return { products, loading, error }
}

export default useSearchProducts
