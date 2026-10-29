#include "background.hpp"

void drawmoon(SDL_Renderer* r , SDL_Texture *moon)
{
  SDL_FRect abc = { moon_x ,
                       moon_y ,
                       moon_w ,
                       moon_h };
  SDL_RenderTexture(r,moon,nullptr,&abc);
}
