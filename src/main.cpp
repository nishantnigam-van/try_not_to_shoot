#include <SDL3/SDL.h>

constexpr int W = 224, H = 256;

struct Bullet { SDL_FRect r{0, 0, 1, 4}; bool active = false; };

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window; SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer("Star Invaders", W * 3, H * 3,
                                SDL_WINDOW_RESIZABLE, &window, &renderer);
    SDL_SetRenderLogicalPresentation(renderer, W, H,
                                     SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);

    SDL_FRect player{W / 2.f - 7, H - 40, 13, 8};
    Bullet bullet;
    Uint64 last = SDL_GetTicks();
    bool running = true;

    while (running) {
        Uint64 now = SDL_GetTicks();
        float dt = (now - last) / 1000.f;
        last = now;

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
            if (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_SPACE && !bullet.active) {
                bullet.active = true;
                bullet.r.x = player.x + player.w / 2;
                bullet.r.y = player.y;
            }
        }

        const bool* keys = SDL_GetKeyboardState(nullptr);
        if (keys[SDL_SCANCODE_LEFT])  player.x -= 100 * dt;
        if (keys[SDL_SCANCODE_RIGHT]) player.x += 100 * dt;
        player.x = SDL_clamp(player.x, 0.f, W - player.w);

        if (bullet.active) {
            bullet.r.y -= 220 * dt;
            if (bullet.r.y < 0) bullet.active = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player);
        if (bullet.active) SDL_RenderFillRect(renderer, &bullet.r);
        SDL_RenderDebugText(renderer, 8, 8, "SCORE<1> 0000");
        SDL_RenderPresent(renderer);
    }
    SDL_Quit();
}
