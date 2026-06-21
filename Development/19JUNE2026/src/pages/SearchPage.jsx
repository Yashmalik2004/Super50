import { useSearchParams } from 'react-router-dom'
import useSearchProducts from '@/hooks/useSearchProducts'
import ProductCard from '@/components/ProductCard'
import { SearchX } from 'lucide-react'

const SearchPage = () => {
  const [searchParams] = useSearchParams()
  const query = searchParams.get('q') || ''

  const { products, loading } = useSearchProducts(query)

  return (
    <div className="mx-auto max-w-7xl px-4 sm:px-6 lg:px-8 py-10 space-y-8">
      {/* Header */}
      <div className="space-y-1">
        <h1 className="text-2xl font-bold tracking-tight">
          Search results for{' '}
          <span className="text-primary">"{query}"</span>
        </h1>
        {!loading && (
          <p className="text-muted-foreground text-sm">
            {products.length === 0
              ? 'No products found.'
              : `${products.length} product${products.length !== 1 ? 's' : ''} found`}
          </p>
        )}
      </div>

      {loading ? (
        <div className="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-4 xl:grid-cols-5 gap-4">
          {Array.from({ length: 10 }).map((_, i) => (
            <div key={i} className="rounded-xl bg-muted animate-pulse aspect-[3/4]" />
          ))}
        </div>
      ) : products.length === 0 ? (
        <div className="flex flex-col items-center justify-center py-20 gap-4 text-muted-foreground">
          <SearchX className="w-12 h-12" />
          <p className="text-lg font-medium">No results found for "{query}"</p>
          <p className="text-sm">Try different keywords or check the spelling.</p>
        </div>
      ) : (
        <div className="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-4 xl:grid-cols-5 gap-4">
          {products.map((product) => (
            <ProductCard key={product.id} product={product} />
          ))}
        </div>
      )}
    </div>
  )
}

export default SearchPage
