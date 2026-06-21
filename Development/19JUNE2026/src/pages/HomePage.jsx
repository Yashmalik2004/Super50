import { useState, useMemo } from 'react'
import { useNavigate } from 'react-router-dom'
import { Input } from '@/components/ui/input'
import { Button } from '@/components/ui/button'
import { ROUTES } from '@/constants/routes'
import useProducts from '@/hooks/useProducts'
import ProductCard from '@/components/ProductCard'
import { Search, Sparkles } from 'lucide-react'

const HomePage = () => {
  const navigate = useNavigate()
  const [query, setQuery] = useState('')
  const { products, loading } = useProducts(100)

  // Pick a stable random 10 products from the full list
  const featured = useMemo(() => {
    if (!products.length) return []
    // Shuffle deterministically by sorting on id * golden ratio mod
    const shuffled = [...products].sort(
      (a, b) => (a.id * 1.618) % 10 - (b.id * 1.618) % 10
    )
    return shuffled.slice(0, 10)
  }, [products])

  const handleSearch = (e) => {
    e.preventDefault()
    const trimmed = query.trim()
    if (!trimmed) return
    navigate(`${ROUTES.SEARCH}?q=${encodeURIComponent(trimmed)}`)
  }

  return (
    <div className="mx-auto max-w-7xl px-4 sm:px-6 lg:px-8 py-10 space-y-12">
      {/* Hero / Welcome Section */}
      <section className="rounded-3xl bg-gradient-to-br from-primary/90 to-primary/60 text-primary-foreground px-8 py-14 text-center space-y-6 shadow-lg">
        <div className="flex justify-center">
          <span className="inline-flex items-center gap-2 rounded-full bg-primary-foreground/20 px-4 py-1.5 text-sm font-medium">
            <Sparkles className="w-4 h-4" />
            New Arrivals Every Day
          </span>
        </div>
        <h1 className="text-4xl sm:text-5xl font-extrabold tracking-tight leading-tight">
          Discover Products <br className="hidden sm:block" />
          You'll Love
        </h1>
        <p className="text-primary-foreground/80 max-w-xl mx-auto text-base sm:text-lg">
          Explore thousands of curated products across every category. Type anything below to start your search.
        </p>

        {/* Inline search */}
        <form
          onSubmit={handleSearch}
          className="flex gap-2 max-w-lg mx-auto"
        >
          <div className="relative flex-1">
            <Search className="absolute left-3 top-1/2 -translate-y-1/2 h-4 w-4 text-muted-foreground pointer-events-none" />
            <Input
              id="home-search-input"
              type="text"
              placeholder="Search for products…"
              value={query}
              onChange={(e) => setQuery(e.target.value)}
              className="pl-9 bg-background text-foreground border-0 shadow-md"
            />
          </div>
          <Button
            id="home-search-btn"
            type="submit"
            variant="secondary"
            size="default"
            className="shadow-md font-semibold"
          >
            Search
          </Button>
        </form>
      </section>

      {/* Products Section */}
      <section>
        <div className="flex items-center justify-between mb-6">
          <div>
            <h2 className="text-2xl font-bold tracking-tight">Featured Products</h2>
            <p className="text-muted-foreground text-sm mt-1">Hand-picked products just for you</p>
          </div>
          <span className="text-xs text-muted-foreground font-medium px-3 py-1 rounded-full bg-muted">
            10 picks
          </span>
        </div>

        {loading ? (
          <div className="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-5 gap-4">
            {Array.from({ length: 10 }).map((_, i) => (
              <div
                key={i}
                className="rounded-xl bg-muted animate-pulse aspect-[3/4]"
              />
            ))}
          </div>
        ) : (
          <div className="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-5 gap-4">
            {featured.map((product) => (
              <ProductCard key={product.id} product={product} />
            ))}
          </div>
        )}
      </section>
    </div>
  )
}

export default HomePage
