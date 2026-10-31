#include "background.hpp"

void drawmoon(SDL_Renderer* r , SDL_Texture *moon)
{
  SDL_FRect abc = { moon_x ,
                       moon_y ,
                       moon_w ,
                       moon_h };
  SDL_RenderTexture(r,moon,nullptr,&abc);
}

void drawmenu(bool *menu , bool *done , SDL_Renderer *r , SDL_Texture *main_menu){
  SDL_Event e;
  while(SDL_PollEvent(&e)){
    if(e.type == SDL_EVENT_QUIT) *done = true , *menu = false ;
    if(e.type == SDL_EVENT_KEY_DOWN){
      if(e.key.key == SDLK_ESCAPE) *done = true , *menu = false;
      if(e.key.key == SDLK_RETURN) *menu = false;
    }
  }
  SDL_SetRenderDrawColor(r,0,0,0,255);
  SDL_RenderClear(r);
  SDL_FRect dst = { 200 , 125 , 1200 , 750};
  SDL_RenderTexture(r,main_menu,nullptr,&dst);
  SDL_RenderPresent(r);
}
