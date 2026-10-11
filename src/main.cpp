//g++ main.cpp texture.cpp -lSDL3 -lSDL3_image -o mygame

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "texture.hpp"
#include "player.hpp"

int main(int argc, char *argv[])
{

    player_pos spaceship;
    spaceship.w = 91.67f ;
    spaceship.h = 101.67f ;
    spaceship.x = 800;
    spaceship.y = 1000-101.67f;

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
   
    SDL_SetRenderLogicalPresentation(renderer,1600,1000,SDL_LOGICAL_PRESENTATION_LETTERBOX); 

    int outW, outH;
    SDL_GetRenderOutputSize(renderer, &outW, &outH);
    SDL_Log("render output: %dx%d", outW, outH);

    const float k = outH / 1000.0f;   // design space = your 2560x1600 wallpaper

    SDL_Texture *enemy = load_svg(renderer, "../Images/sprites/enemy.svg",
                                  43.5f*k , 59.0f*k );
    SDL_Texture *player = load_svg(renderer,"../Images/sprites/player.svg",
                                  91.67f*k, 101.67f*k);
      
    if (!enemy) return -1;

    float enemy_pos_x = 1600 * 0.5f, enemy_pos_y = 1000 * 0.5f;      // pick whatever position you like
    SDL_FRect dst_enemy = { SDL_roundf(enemy_pos_x), SDL_roundf(enemy_pos_y), 0, 0 };
    SDL_GetTextureSize(enemy, &dst_enemy.w, &dst_enemy.h);   // draw 1:1, no resampling
    
    Uint64 last = SDL_GetTicksNS();  //Get current time

    bool done = false;
    
    SDL_Event event;

    while (!done)
    {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) done = true;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) done = true;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);   // set BEFORE clear
        SDL_RenderClear(renderer);
        
        Uint64 current = SDL_GetTicksNS();
        float dt = (current - last)/1e9f ;
        moveplayer(spaceship,dt);
        drawplayer(renderer,player,spaceship);

        SDL_RenderPresent(renderer);
        last = current ;
    }

    SDL_DestroyTexture(enemy);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
