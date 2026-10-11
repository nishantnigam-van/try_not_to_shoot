#include "texture.hpp"

SDL_Texture *load_svg(SDL_Renderer *r, const char *path, float w, float h) {
    SDL_IOStream *io = SDL_IOFromFile(path, "rb");
    if (!io) { SDL_Log("open %s failed: %s", path, SDL_GetError()); return nullptr; }

    SDL_Surface *s = IMG_LoadSizedSVG_IO(io, (int)SDL_roundf(w), (int)SDL_roundf(h)); // closes io
    if (!s) { SDL_Log("svg load failed: %s", SDL_GetError()); return nullptr; }

    SDL_Texture *t = SDL_CreateTextureFromSurface(r, s);
    SDL_DestroySurface(s);
    if (!t) { SDL_Log("texture failed: %s", SDL_GetError()); return nullptr; }

    SDL_SetTextureScaleMode(t, SDL_SCALEMODE_LINEAR);
    return t;
}
