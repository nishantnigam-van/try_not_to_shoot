#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "texture.hpp"

int main(int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("game", 2560, 1600,
        SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_FULLSCREEN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
    if (!window || !renderer) {
        SDL_Log("window/renderer failed: %s", SDL_GetError());
        return -1;
    }
    SDL_SetRenderVSync(renderer, 1);

    // real output pixels (e.g. 3840x2160), not the requested 2560x1600
    int outW, outH;
    SDL_GetRenderOutputSize(renderer, &outW, &outH);
    SDL_Log("render output: %dx%d", outW, outH);

    const float k = outH / 1600.0f;   // design space = your 2560x1600 wallpaper

    SDL_Texture *enemy = load_svg(renderer, "../Images/sprites/enemy.svg",
                                  43.5f * k, 59.0f * k);
    if (!enemy) return -1;

    float enemy_pos_x = outW * 0.5f, enemy_pos_y = outH * 0.5f;      // pick whatever position you like
    SDL_FRect dst_enemy = { SDL_roundf(enemy_pos_x), SDL_roundf(enemy_pos_y), 0, 0 };
    SDL_GetTextureSize(enemy, &dst_enemy.w, &dst_enemy.h);   // draw 1:1, no resampling

    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) done = true;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) done = true;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);   // set BEFORE clear
        SDL_RenderClear(renderer);

        if (!SDL_RenderTexture(renderer, enemy, nullptr, &dst_enemy))
            SDL_Log("render failed: %s", SDL_GetError());
        
        dst_enemy.x -= 0.1f;

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(enemy);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
