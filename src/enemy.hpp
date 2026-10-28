#pragma once 
#include<vector>
#include<SDL3/SDL.h>
using namespace std;


struct enemy_pos{
  float x ,y ;
  float w , h ;
  int hp ;
};

void drawenemy(SDL_Renderer * r , SDL_Texture *enemy , vector<enemy_pos> &e);
void getenemycoordinates(Uint64 old_time , Uint64 current_time , vector<enemy_pos> &e);
void moveenemy(vector<enemy_pos> &e, float dt );
