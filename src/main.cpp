//g++ main.cpp texture.cpp -lSDL3 -lSDL3_image -o mygame

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "texture.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "gamelogic.hpp"
#include "bullets.hpp"
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{

    player_pos spaceship;
    spaceship.w = 91.67f ;
    spaceship.h = 101.67f ;
    spaceship.x = 800;
    spaceship.y = 1000-101.67f;

//    enemy_pos enemyship;
//    enemyship.w = 43.5f;
//    enemyship.h = 59.0f;

    vector<enemy_pos> enemyship;
    vector<bullet_pos> bullets;

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
    SDL_SetRenderLogicalPresentation(renderer,1600,1000,SDL_LOGICAL_PRESENTATION_LETTERBOX);  // This one will make our world 1600*1000 in all devices as we can use these as the logic in game and it will scale to respective system 
    int outW, outH;
    SDL_GetRenderOutputSize(renderer, &outW, &outH);
    SDL_Log("render output: %dx%d", outW, outH);

    const float k = outH / 1000.0f;
    SDL_Texture *enemy = load_svg(renderer, "../Images/sprites/enemy.svg", 
                                  43.5f*k , 59.0f*k );  // Multiplying with k help keep out render texture of same size couse some screen may more pixel so we render more like that i guess ?
    SDL_Texture *player = load_svg(renderer,"../Images/sprites/player.svg",
                                  91.67f*k, 101.67f*k);
    SDL_Texture *bullet = load_svg(renderer , "../Images/sprites/bullet.svg",
                                  4.0f*k , 27.0f*k); 
      
    if (!enemy || !player || !bullet) {
	    SDL_Log("Couldnt load enemy / player texture");
	    return -1;
    }
    
    Uint64 last = SDL_GetTicksNS();  //Get current time
    Uint64 start_time = SDL_GetTicksNS(); //To increase the number of enemies as the time increases
    bool done = false;
    
    SDL_Event event;

    while (!done)
    {
      	done = gameover(spaceship,enemyship); //need here cause dont wanna overwrite the done from event.exit 

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) done = true;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) done = true;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);   // set BEFORE clear
        SDL_RenderClear(renderer);
        
        Uint64 current = SDL_GetTicksNS();
        float dt = (current - last)/1e9f ;
        
        if (dt > 0.05f) dt = 0.05f;


        shootbullet(spaceship,bullets);
        moveplayer(spaceship,dt);
      	moveenemy(enemyship,dt);
        movebullet(bullets,dt);
        drawplayer(renderer,player,spaceship);
        drawbullet(renderer,bullet,bullets);
      	getenemycoordinates(start_time,current,enemyship);
        drawenemy(renderer,enemy,enemyship);

        SDL_RenderPresent(renderer);
        last = current ;
    }

    SDL_DestroyTexture(enemy);
    SDL_DestroyTexture(player);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
