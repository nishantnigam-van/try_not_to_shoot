#pragma once 
#include<SDL3/SDL.h>


struct player_pos{
  float x , y;
  float vx = 0 , vy = 0;
  float a = 4000.f;
  float de_a = 1000.0f;
  float w,h;
  float max_speed = 600.0f;
  };

bool drawplayer(SDL_Renderer* r,SDL_Texture *player,const player_pos &p);
void moveplayer(player_pos &p,float dt);

