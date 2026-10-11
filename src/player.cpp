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

//  key[SDL_SCANCODE_LEFT] = key[SDL_SCANCODE_A]; 
//  key[SDL_SCANCODE_RIGHT] = key[SDL_SCANCODE_D]; 
//  key[SDL_SCANCODE_UP] = key[SDL_SCANCODE_W]; 
//  key[SDL_SCANCODE_DOWN] = key[SDL_SCANCODE_S]; 
  
  if( key[SDL_SCANCODE_A]==key[SDL_SCANCODE_D]|| (!key[SDL_SCANCODE_A] && !key[SDL_SCANCODE_D] && p.vx != 0))
   {
      p.x += p.vx*dt;
      if(p.vx > 0)
      {
        float v = p.vx - p.de_a* dt;
        if(v<0)
          v=0;
        p.vx = v;
      }
      else{
         float v = p.vx + p.de_a*dt;
         if(v>0)
           v=0;
         p.vx = v;

      }  
   }
  
   if(key[SDL_SCANCODE_S]==key[SDL_SCANCODE_W] || (!key[SDL_SCANCODE_W] && !key[SDL_SCANCODE_S]  && p.vy != 0))
   {
      p.y += p.vy*dt;
      if(p.vy > 0)
      {
        float v = p.vy - p.de_a* dt;
        if(v<0)
          v=0;
        p.vy = v;
      }
      else{
         float v = p.vy + p.de_a*dt;
         if(v>0)
           v=0;
         p.vy = v;
      }
   }

  if(key[SDL_SCANCODE_A]!=key[SDL_SCANCODE_D])
  { 
    if(key[SDL_SCANCODE_A])
   {
      p.x += p.vx*dt;
      float v = p.vx - p.a * dt;
      
      if(v<=-1*p.max_speed)
        p.vx = -1*p.max_speed;
      else
        p.vx = v;
    }
    else if(key[SDL_SCANCODE_D])
   {
      p.x += p.vx*dt;
      float v = p.vx + p.a * dt;
      if(v>=p.max_speed)
        p.vx = p.max_speed;
      else
        p.vx = v;
    
   }
  }
  if(key[SDL_SCANCODE_W]!=key[SDL_SCANCODE_S])
    if(key[SDL_SCANCODE_S])
  {
      p.y += p.vy*dt;
      float v = p.vy + p.a*dt;
      if(v>=p.max_speed)
        p.vy = p.max_speed;
      else
        p.vy = v;
  }
  else if(key[SDL_SCANCODE_W])
  {
      p.y += p.vy*dt;
      float v = p.vy - p.a * dt;
      if(v<=-1*p.max_speed)
        p.vy = -1*p.max_speed;
      else
        p.vy = v;
  }
  
}
