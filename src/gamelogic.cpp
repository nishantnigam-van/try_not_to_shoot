#include "gamelogic.hpp"
#include<vector>
#include<utility>
#include<SDL3/SDL.h>

using namespace std;

bool gameover(player_pos &spaceship , vector<enemy_pos> &enemyship)
{
	float x = spaceship.x;
	float y = spaceship.y;
	float w = spaceship.w;
	float h = spaceship.h;
	for(int i =0 ; i < enemyship.size() ; i++)
	{
	pair <float,float> enemy_lt ={enemyship[i].x,enemyship[i].y} ,
	      enemy_rt ={enemyship[i].x + enemyship[i].w , enemyship[i].y} ,
	      enemy_lb ={enemyship[i].x , enemyship[i].y + enemyship[i].h} ,
	      enemy_rb ={enemyship[i].x + enemyship[i].w , enemyship[i].y + enemyship[i].h} ;

	if(enemy_lt.first > x && enemy_lt.first < x + h && enemy_lt.second > y && enemy_lt.second < y + h)
		return true ;
	if(enemy_rt.first > x && enemy_rt.first < x + h && enemy_rt.second > y && enemy_rt.second < y + h)
		return true ;
	if(enemy_lb.first > x && enemy_lb.first < x + h && enemy_lb.second > y && enemy_lb.second < y + h)
		return true ;
	if(enemy_rb.first > x && enemy_rb.first < x + h && enemy_rb.second > y && enemy_rb.second < y + h)
		return true ;
	}
	return false;
}
