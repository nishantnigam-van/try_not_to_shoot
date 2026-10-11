# Sprite pack (SDL3 / SDL3_image)

Each sprite is white-on-transparent, so you can tint it at runtime
(`SDL_SetTextureColorMod`) instead of making coloured copies.

| file      | native size (units of your 2560x1600 image) |
|-----------|---------------------------------------------|
| enemy     | 43.5 x 59                                    |
| player    | 91.7 x 101.7                                 |
| orb       | 88 x 81 (pixel-exact trace of the striped sphere) |
| bullet    | 4 x 27                                       |
| ground    | 700 x 4                                      |

Formats: `*.svg` (vector master), `*@4x.png`, `*@8x.png` (transparent, antialiased).

## Option A - load the PNG and downscale (simplest)
```c
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

SDL_Surface *s = IMG_Load("sprites/enemy@8x.png");
SDL_Texture *enemy = SDL_CreateTextureFromSurface(renderer, s);
SDL_DestroySurface(s);
SDL_SetTextureScaleMode(enemy, SDL_SCALEMODE_LINEAR);   // smooth downscale

// 4K: scale by 1.5 vs the original wallpaper -> enemy ~ 65 x 89 px
SDL_FRect dst = { x, y, 43.5f * 1.5f, 59.0f * 1.5f };
SDL_RenderTexture(renderer, enemy, NULL, &dst);
```

## Option B - rasterise the SVG at the exact size you need (sharpest)
```c
```
SDL_IOStream *io = SDL_IOFromFile("sprites/enemy.svg", "rb");
SDL_Surface *s = IMG_LoadSizedSVG_IO(io, 65, 89);   // closes io for you
SDL_Texture *enemy = SDL_CreateTextureFromSurface(renderer, s);
SDL_DestroySurface(s);
Re-rasterise when the window/render scale changes (e.g. 1080p -> 4K).
