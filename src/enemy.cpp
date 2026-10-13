#include<SDL3/SDL.h>
#include"enemy.hpp"
  
void drawenemy(SDL_Renderer * r , SDL_Texture * enemy , enemy_pos &e){
    SDL_FRect dst ={e.x ,                          
                    e.y ,                           
                    e.w ,                           
                    e.h };                          
    SDL_RenderTexture(r,enemy,nullptr,&dst);
  }

// void drawenemy(SDL_Renderer * r , SDL_Texture *enemy , enemy_pos &e){
//
// }
//
