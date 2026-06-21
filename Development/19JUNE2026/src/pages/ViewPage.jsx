import { useState } from 'react'
import { useParams, useNavigate } from 'react-router-dom'
import useProduct from '@/hooks/useProduct'
import { Badge } from '@/components/ui/badge'
import { Button } from '@/components/ui/button'
import { ROUTES } from '@/constants/routes'
import {
  Star,
  Package,
  Tag,
  ShieldCheck,
  Truck,
  ArrowLeft,
  ChevronLeft,
  ChevronRight,
} from 'lucide-react'

const ViewPage = () => {
  const { id } = useParams()
  const navigate = useNavigate()
  const { product, loading } = useProduct(id)
  const [currentImage, setCurrentImage] = useState(0)

  if (loading) {
    return (
      <div className="mx-auto max-w-6xl px-4 sm:px-6 lg:px-8 py-10">
        <div className="grid grid-cols-1 lg:grid-cols-2 gap-10 animate-pulse">
          <div className="rounded-2xl bg-muted aspect-square" />
          <div className="space-y-4">
            {[...Array(6)].map((_, i) => (
              <div key={i} className="h-6 bg-muted rounded-lg w-full" />
            ))}
          </div>
        </div>
      </div>
    )
  }

  if (!product) return null

  const images = product.images?.length ? product.images : [product.thumbnail]
  const prevImage = () => setCurrentImage((p) => (p - 1 + images.length) % images.length)
  const nextImage = () => setCurrentImage((p) => (p + 1) % images.length)

  return (
    <div className="mx-auto max-w-6xl px-4 sm:px-6 lg:px-8 py-10 space-y-10">
      {/* Back button */}
      <Button
        id="view-back-btn"
        variant="ghost"
        size="sm"
        onClick={() => navigate(-1)}
        className="gap-2"
      >
        <ArrowLeft className="w-4 h-4" />
        Back
      </Button>

      <div className="grid grid-cols-1 lg:grid-cols-2 gap-10">
        {/* Image gallery */}
        <div className="space-y-4">
          <div className="relative rounded-2xl overflow-hidden bg-muted aspect-square group">
            <img
              src={images[currentImage]}
              alt={product.title}
              className="w-full h-full object-cover transition-transform duration-500 group-hover:scale-105"
            />
            {images.length > 1 && (
              <>
                <button
                  onClick={prevImage}
                  className="absolute left-3 top-1/2 -translate-y-1/2 bg-background/80 hover:bg-background rounded-full p-2 shadow transition-all"
                >
                  <ChevronLeft className="w-4 h-4" />
                </button>
                <button
                  onClick={nextImage}
                  className="absolute right-3 top-1/2 -translate-y-1/2 bg-background/80 hover:bg-background rounded-full p-2 shadow transition-all"
                >
                  <ChevronRight className="w-4 h-4" />
                </button>
              </>
            )}
            {/* Image count */}
            {images.length > 1 && (
              <span className="absolute bottom-3 right-3 bg-background/80 text-xs px-2 py-1 rounded-full font-medium">
                {currentImage + 1} / {images.length}
              </span>
            )}
          </div>

          {/* Thumbnails */}
          {images.length > 1 && (
            <div className="flex gap-2 overflow-x-auto pb-1">
              {images.map((img, idx) => (
                <button
                  key={idx}
                  onClick={() => setCurrentImage(idx)}
                  className={`shrink-0 w-16 h-16 rounded-lg overflow-hidden border-2 transition-all ${
                    idx === currentImage
                      ? 'border-primary scale-105'
                      : 'border-border hover:border-primary/50'
                  }`}
                >
                  <img src={img} alt="" className="w-full h-full object-cover" />
                </button>
              ))}
            </div>
          )}
        </div>

        {/* Product details */}
        <div className="space-y-5">
          {/* Category + Brand */}
          <div className="flex flex-wrap gap-2">
            <Badge variant="secondary" className="capitalize text-xs">
              {product.category}
            </Badge>
            {product.brand && (
              <Badge variant="outline" className="text-xs">
                {product.brand}
              </Badge>
            )}
          </div>

          {/* Title */}
          <h1 className="text-3xl font-extrabold tracking-tight leading-tight">
            {product.title}
          </h1>

          {/* Rating */}
          <div className="flex items-center gap-2">
            <div className="flex items-center gap-1 text-amber-500">
              {[...Array(5)].map((_, i) => (
                <Star
                  key={i}
                  className={`w-4 h-4 ${
                    i < Math.round(product.rating) ? 'fill-current' : 'opacity-30'
                  }`}
                />
              ))}
            </div>
            <span className="text-sm font-medium">{product.rating?.toFixed(1)}</span>
            <span className="text-sm text-muted-foreground">
              ({product.reviews?.length ?? 0} reviews)
            </span>
          </div>

          {/* Price */}
          <div className="flex items-baseline gap-3">
            <span className="text-4xl font-extrabold text-primary">
              ${product.price}
            </span>
            {product.discountPercentage > 0 && (
              <>
                <span className="text-lg text-muted-foreground line-through">
                  ${(product.price / (1 - product.discountPercentage / 100)).toFixed(2)}
                </span>
                <Badge variant="destructive" className="text-sm">
                  -{Math.round(product.discountPercentage)}% OFF
                </Badge>
              </>
            )}
          </div>

          {/* Description */}
          <p className="text-muted-foreground leading-relaxed">{product.description}</p>

          {/* Meta info */}
          <div className="grid grid-cols-2 gap-3">
            <div className="flex items-center gap-2 rounded-lg bg-muted p-3">
              <Package className="w-4 h-4 text-primary" />
              <div>
                <p className="text-xs text-muted-foreground">Stock</p>
                <p className="text-sm font-medium">{product.stock} units</p>
              </div>
            </div>
            <div className="flex items-center gap-2 rounded-lg bg-muted p-3">
              <Tag className="w-4 h-4 text-primary" />
              <div>
                <p className="text-xs text-muted-foreground">SKU</p>
                <p className="text-sm font-medium">{product.sku || 'N/A'}</p>
              </div>
            </div>
            {product.warrantyInformation && (
              <div className="flex items-center gap-2 rounded-lg bg-muted p-3">
                <ShieldCheck className="w-4 h-4 text-primary" />
                <div>
                  <p className="text-xs text-muted-foreground">Warranty</p>
                  <p className="text-sm font-medium">{product.warrantyInformation}</p>
                </div>
              </div>
            )}
            {product.shippingInformation && (
              <div className="flex items-center gap-2 rounded-lg bg-muted p-3">
                <Truck className="w-4 h-4 text-primary" />
                <div>
                  <p className="text-xs text-muted-foreground">Shipping</p>
                  <p className="text-sm font-medium">{product.shippingInformation}</p>
                </div>
              </div>
            )}
          </div>

          {/* Tags */}
          {product.tags?.length > 0 && (
            <div className="flex flex-wrap gap-1.5">
              {product.tags.map((tag) => (
                <span
                  key={tag}
                  className="text-xs bg-secondary text-secondary-foreground px-2 py-1 rounded-full font-medium"
                >
                  #{tag}
                </span>
              ))}
            </div>
          )}
        </div>
      </div>

      {/* Reviews */}
      {product.reviews?.length > 0 && (
        <section className="space-y-4">
          <h2 className="text-xl font-bold tracking-tight">Customer Reviews</h2>
          <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-4">
            {product.reviews.map((review, idx) => (
              <div key={idx} className="rounded-xl border border-border/60 p-4 space-y-2">
                <div className="flex items-center justify-between">
                  <p className="font-medium text-sm">{review.reviewerName}</p>
                  <div className="flex items-center gap-1 text-amber-500">
                    <Star className="w-3 h-3 fill-current" />
                    <span className="text-xs">{review.rating}</span>
                  </div>
                </div>
                <p className="text-sm text-muted-foreground leading-relaxed">{review.comment}</p>
                <p className="text-xs text-muted-foreground">
                  {new Date(review.date).toLocaleDateString('en-US', {
                    year: 'numeric',
                    month: 'short',
                    day: 'numeric',
                  })}
                </p>
              </div>
            ))}
          </div>
        </section>
      )}
    </div>
  )
}

export default ViewPage
