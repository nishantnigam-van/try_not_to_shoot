#pragma once 
#include<vector>
#include<SDL3/SDL.h>
using namespace std;

struct enemy_pos{
  vector<float> x ,y ;
  vector<float> vx, vy ;
  float w , h ;
};

void drawenemy(SDL_Renderer * r , SDL_Texture *enemy , enemy_pos &e);
void getenemycoordinates(Uint64 old_time , Uint64 current_time , enemy_pos &e);
// void moveenemy(enemy_pos &r, float dt );
