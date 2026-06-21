import { useState } from 'react'
import { useNavigate, Link, useSearchParams } from 'react-router-dom'
import { Input } from '@/components/ui/input'
import { Button } from '@/components/ui/button'
import { ROUTES } from '@/constants/routes'
import { Search, ShoppingBag } from 'lucide-react'

const Navbar = () => {
  const navigate = useNavigate()
  const [searchParams] = useSearchParams()
  const [query, setQuery] = useState(searchParams.get('q') || '')

  const handleSearch = (e) => {
    e.preventDefault()
    const trimmed = query.trim()
    if (!trimmed) return
    navigate(`${ROUTES.SEARCH}?q=${encodeURIComponent(trimmed)}`)
  }

  return (
    <header className="sticky top-0 z-50 w-full border-b border-border/50 bg-background/80 backdrop-blur-md shadow-sm">
      <div className="mx-auto max-w-7xl px-4 sm:px-6 lg:px-8">
        <div className="flex h-16 items-center justify-between gap-4">
          {/* Logo / Home */}
          <Link
            to={ROUTES.HOME}
            className="flex items-center gap-2 font-bold text-xl tracking-tight text-primary hover:opacity-80 transition-opacity shrink-0"
          >
            <ShoppingBag className="w-6 h-6 text-primary" />
            <span>ShopSphere</span>
          </Link>

          {/* Search bar */}
          <form
            onSubmit={handleSearch}
            className="flex flex-1 max-w-xl items-center gap-2"
          >
            <div className="relative flex-1">
              <Search className="absolute left-3 top-1/2 -translate-y-1/2 h-4 w-4 text-muted-foreground pointer-events-none" />
              <Input
                id="navbar-search-input"
                type="text"
                placeholder="Search products…"
                value={query}
                onChange={(e) => setQuery(e.target.value)}
                className="pl-9 w-full"
              />
            </div>
            <Button id="navbar-search-btn" type="submit" variant="default" size="sm">
              Search
            </Button>
          </form>

          {/* Home button */}
          <Link to={ROUTES.HOME}>
            <Button id="navbar-home-btn" variant="ghost" size="sm" className="shrink-0">
              Home
            </Button>
          </Link>
        </div>
      </div>
    </header>
  )
}

export default Navbar
