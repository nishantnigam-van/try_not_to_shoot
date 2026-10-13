#pragma once 
#include<SDL3/SDL.h>

struct enemy_pos{
  float x ,y ;
  float vx = 0 , vy = 0;
  float w , h ;
};

void drawenemy(SDL_Renderer * r , SDL_Texture *enemy , enemy_pos &e);
// void moveenemy(enemy_pos &r, float dt );
