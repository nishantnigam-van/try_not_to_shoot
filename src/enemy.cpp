#include<SDL3/SDL.h>
#include<random>
#include"enemy.hpp"
using namespace std;
  
void drawenemy(SDL_Renderer * r , SDL_Texture * enemy , enemy_pos &e){
    if(e.x.size() > 0 && e.y.size() > 0)
    {
	    for(int i =0 ;i < e.x.size() ; i ++)
	    {
    		SDL_FRect dst ={e.x[i] ,                          
        	            e.y[i] ,                           
        	            e.w ,                           
        	            e.h };                          
    		SDL_RenderTexture(r,enemy,nullptr,&dst);
	    }
    }
  }

void getenemycoordinates(Uint64 old_time , Uint64 current_time , enemy_pos &e)
{
	if(1)
	{
		float lower_bound_x = e.w/2;
		float upper_bound_x = 1600.0f - e.w/2;
		float generate_y = e.h/2;
		float generate_x = lower_bound_x + (upper_bound_x-lower_bound_x)*current_time/(10.0f * 1e9f); 
		if(e.x.size()==0){
			e.x.push_back(generate_x);
			e.y.push_back(generate_y);
		}
	}
}

// void drawenemy(SDL_Renderer * r , SDL_Texture *enemy , enemy_pos &e){
//
// }
//
