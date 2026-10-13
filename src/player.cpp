#include<SDL3/SDL.h>
#include<cmath>
#include "player.hpp"

bool drawplayer(SDL_Renderer* r , SDL_Texture* player , const player_pos &p)
{
  // SDL_FRect dst = {p.x , 
  //                 p.y ,
  //                 p.w ,
  //                 p.h };
  // return SDL_RenderTexture(r,player,nullptr,&dst); 
 float center_x = p.x + p.w/2 ;
 float center_y = p.y + p.h/2 ;
 float coor_x[4] = {- p.w / 2 ,  p.w/ 2 , p.w / 2 , - p.w/2};
 float coor_y[4] = {- p.h / 2 ,- p.h/ 2 , p.h / 2 ,   p.h/2};

 //following coordinate system 
 float texture_x[4] = { 0 , 1 , 1, 0};
 float texture_y[4] = { 0 , 0 , 1, 1};

  SDL_Vertex v[4];
  
  for(int i = 0 ; i < 4 ; i++){
    float z = -coor_x[i]*sin(p.tilt);
    float scale = p.D/(p.D-z);
    
    float visual_x = coor_x[i]*scale*cos(p.tilt) + center_x;
    float visual_y = coor_y[i]*scale + center_y;

    v[i].position = {visual_x,visual_y};
    v[i].color = {1,1,1,1};
    v[i].tex_coord = { texture_x[i], texture_y[i]};
  }
  int indices[6] = { 0 , 1 , 2 , 0 , 2 , 3};
  return SDL_RenderGeometry(r , player , v , 4 , indices , 6 );

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
  p.tilt = p.vx * p.max_angle / p.max_speed;
}
