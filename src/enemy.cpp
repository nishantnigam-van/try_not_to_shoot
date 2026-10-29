#include<SDL3/SDL.h>
#include<random>
#include"enemy.hpp"
#include<vector>
#include<cstdlib>
using namespace std;

#define enemy_width 43.5f
#define enemy_height 59.0f
#define spawn_frequency 5.0f
  
void drawenemy(SDL_Renderer * r , SDL_Texture * enemy , vector <enemy_pos>  &e){

	  for(int i =0 ;i < e.size() ; i ++){
        if(e[i].y > 1100){
          e.erase(e.begin() + i);
          i--;
          continue;
        }
	      SDL_FRect dst ={e[i].x ,                          
	                  e[i].y ,                           
	                  e[i].w ,                           
	                  e[i].h };                          
	      SDL_RenderTexture(r,enemy,nullptr,&dst);
	  }
  }

void getenemycoordinates(Uint64 *old_time , Uint64 current_time , vector<enemy_pos> &e)
{
	if(current_time - *old_time > spawn_frequency) //get something better about this
	{
		float lower_bound_x = enemy_width/2;
		float upper_bound_x = 1600.0f - enemy_width/2;
		float generate_y = enemy_height/2 - 200;
		float generate_x = rand()%1600 ; 
		e.push_back(enemy_pos{generate_x,
				generate_y,
				enemy_width,
				enemy_height,
				3
				});
	}
  *old_time = current_time;
}

void moveenemy(vector<enemy_pos> &e, float dt){
	for(int i = 0 ; i < e.size() ; i++)
		e[i].y += 100*dt;
}
