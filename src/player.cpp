#include<SDL3/SDL.h>
#include "player.hpp"

bool drawplayer(SDL_Renderer* r , SDL_Texture* player , const player_pos &p)
{
  SDL_FRect dst = {p.x , 
                  p.y ,
                  p.w ,
                  p.h };
  return SDL_RenderTexture(r,player,nullptr,&dst); 
}

void moveplayer(player_pos &p,float dt)
{
  int numKeys;
  const bool* key = SDL_GetKeyboardState(&numKeys);

  bool noKeyPressed = true;
  for(int i = 0 ; i < numKeys ; i++)
    if(key[i])
    {
      noKeyPressed = false;
      break;
    }

  if(noKeyPressed){
   if(p.vx != 0)
   {
      if(p.vx > 0)
      {
        float v = p.vx - p.de_a* dt;
        if(v<0)
          v=0;
        p.x += v*dt;
        p.vx = v;
      }
      else{
         float v = p.vx + p.de_a*dt;
         if(v>0)
           v=0;
         p.x += v*dt;
         p.vx = v;

      }
  
   }
   if(p.vy != 0)
   {
      if(p.vy > 0)
      {
        float v = p.vy - p.de_a* dt;
        if(v<0)
          v=0;
        p.y += v*dt;
        p.vy = v;
      }
      else{
         float v = p.vy + p.de_a*dt;
         if(v>0)
           v=0;
         p.y += v*dt;
         p.vy = v;
      }
   }
  }

  else{
  if(key[SDL_SCANCODE_A])
  {
      float v = p.vx - p.a * dt;
      if(v<=-1*p.max_speed)
      {
        p.vx = -1*p.max_speed;
        p.x += p.vx*dt;
      }
      else
      {
        p.x += v*dt;
        p.vx = v;
      }
  }
  if(key[SDL_SCANCODE_D])
  {
      float v = p.vx + p.a * dt;
      if(v>=p.max_speed)
      {
        p.vx = p.max_speed;
        p.x += p.vx*dt;
      }
      else
      {
        p.x += v*dt;
        p.vx = v;
      }
  }
  if(key[SDL_SCANCODE_S])
  {
      float v = p.vy + p.a*dt;
      if(v>=p.max_speed)
      {
        p.vy = p.max_speed;
        p.y += p.vy*dt;
      }
      else
      {
        p.y += v*dt;
        p.vy = v;
      }
  }
  if(key[SDL_SCANCODE_W])
  {
      float v = p.vy - p.a * dt;
      if(v<=-1*p.max_speed)
      {
        p.vy = -1*p.max_speed;
        p.y += p.vy*dt;
      }
      else
      {
        p.y += v*dt;
        p.vy = v;
      }
    }
  }
}
