#include<vector>
#include<utility>
#include<SDL3/SDL.h>
#include"player.hpp"
#include"enemy.hpp"
#include"bullets.hpp"

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

void destroyenemy(vector<enemy_pos> &enemyship , vector<bullet_pos> &bullet)
{
  for(int j = 0 ; j < bullet.size() ; j ++){
	    float x = bullet[j].x;
	    float y = bullet[j].y;
	    float w = bullet[j].w;
	    float h = bullet[j].h;
      for(int i = 0 ; i < enemyship.size() ; i++){
          bool check = false;
	        pair <float,float> enemy_lt ={enemyship[i].x,enemyship[i].y} ,
	              enemy_rt ={enemyship[i].x + enemyship[i].w , enemyship[i].y} ,
	              enemy_lb ={enemyship[i].x , enemyship[i].y + enemyship[i].h} ,
	              enemy_rb ={enemyship[i].x + enemyship[i].w , enemyship[i].y + enemyship[i].h} ;

	        if(enemy_lt.first > x && enemy_lt.first < x + h && enemy_lt.second > y && enemy_lt.second < y + h)
	        	check= true ;
	        if(enemy_rt.first > x && enemy_rt.first < x + h && enemy_rt.second > y && enemy_rt.second < y + h)
	        	check= true ;
	        if(enemy_lb.first > x && enemy_lb.first < x + h && enemy_lb.second > y && enemy_lb.second < y + h)
	        	check= true ;
	        if(enemy_rb.first > x && enemy_rb.first < x + h && enemy_rb.second > y && enemy_rb.second < y + h)
	        	check= true ;

          if(check == true){
            enemyship.erase(enemyship.begin()+i);
            i--;
          }
	      }
    }
}
