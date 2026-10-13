#pragma once 
#include<SDL3/SDL.h>


struct player_pos{
  float x , y;
  float vx = 0 , vy = 0;
  float a = 4000.f;
  float de_a = 1000.0f;
  float w,h;
  float max_speed = 600.0f;
  float tilt = 0;
  float D = 300;
  float max_angle = 3.14 / 5 ; //around >30*
  };

bool drawplayer(SDL_Renderer* r,SDL_Texture *player,const player_pos &p);
void moveplayer(player_pos &p,float dt);
