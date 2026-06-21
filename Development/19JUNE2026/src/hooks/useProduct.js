import { useState, useEffect } from 'react'
import { fetchProductById } from '@/api/productsApi'
import { errorToast } from '@/utils/toast'

// Hook to fetch a single product by id
const useProduct = (id) => {
  const [product, setProduct] = useState(null)
  const [loading, setLoading] = useState(true)
  const [error, setError] = useState(null)

  useEffect(() => {
    if (!id) return

    const load = async () => {
      try {
        setLoading(true)
        setError(null)
        const data = await fetchProductById(id)
        setProduct(data)
      } catch (err) {
        setError(err)
        errorToast(err?.response?.data?.message || 'Failed to fetch product details.')
      } finally {
        setLoading(false)
      }
    }
    load()
  }, [id])

  return { product, loading, error }
}

export default useProduct
