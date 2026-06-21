import { useNavigate } from 'react-router-dom'
import { Card, CardContent } from '@/components/ui/card'
import { Badge } from '@/components/ui/badge'
import { ROUTES } from '@/constants/routes'
import { Star } from 'lucide-react'

const ProductCard = ({ product }) => {
  const navigate = useNavigate()

  const handleClick = () => {
    navigate(ROUTES.VIEW_PRODUCT(product.id))
  }

  return (
    <Card
      id={`product-card-${product.id}`}
      onClick={handleClick}
      className="cursor-pointer group overflow-hidden transition-all duration-300 hover:shadow-xl hover:-translate-y-1 border border-border/60"
    >
      <div className="relative aspect-square overflow-hidden bg-muted">
        <img
          src={product.thumbnail}
          alt={product.title}
          className="w-full h-full object-cover transition-transform duration-500 group-hover:scale-110"
          loading="lazy"
        />
        <Badge
          variant="secondary"
          className="absolute top-2 left-2 text-xs font-medium capitalize"
        >
          {product.category}
        </Badge>
        {product.discountPercentage > 0 && (
          <Badge
            variant="destructive"
            className="absolute top-2 right-2 text-xs font-medium"
          >
            -{Math.round(product.discountPercentage)}%
          </Badge>
        )}
      </div>

      <CardContent className="p-4 space-y-2">
        <h3 className="font-semibold text-sm leading-tight line-clamp-2 group-hover:text-primary transition-colors">
          {product.title}
        </h3>

        <div className="flex items-center gap-1 text-amber-500">
          <Star className="w-3.5 h-3.5 fill-current" />
          <span className="text-xs font-medium">{product.rating?.toFixed(1)}</span>
          <span className="text-xs text-muted-foreground ml-1">
            ({product.stock} in stock)
          </span>
        </div>

        <div className="flex items-baseline gap-2">
          <span className="text-lg font-bold text-primary">
            ${product.price}
          </span>
          {product.discountPercentage > 0 && (
            <span className="text-xs text-muted-foreground line-through">
              ${(product.price / (1 - product.discountPercentage / 100)).toFixed(2)}
            </span>
          )}
        </div>
      </CardContent>
    </Card>
  )
}

export default ProductCard
