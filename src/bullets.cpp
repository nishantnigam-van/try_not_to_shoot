#include<SDL3/SDL.h>
#include<vector>
#include"bullets.hpp"
#include"player.hpp"


void drawbullet(SDL_Renderer *r , SDL_Texture *bullet , vector<bullet_pos> &bullets)
{
  for(int i = 0 ; i < bullets.size() ; i++){
    if(bullets[i].x < -10 ||bullets[i].x > 1610 ||bullets[i].y < -10 || bullets[i].y > 1010 ){
      bullets.erase(bullets.begin() + i);
      i--;
      continue;
    }
	      SDL_FRect dst ={bullets[i].x ,                          
	                  bullets[i].y ,                           
	                  bullets[i].w ,                           
	                  bullets[i].h };                          
	      SDL_RenderTexture(r,bullet,nullptr,&dst);
  }
}

void shootbullet(player_pos &p , vector<bullet_pos> &bullets)
{ 
  int numKeys;
  const bool* key = SDL_GetKeyboardState(&numKeys);

  if(key[SDL_SCANCODE_SPACE]){
    bullets.push_back({
        p.x + 1.5f  ,
        p.y + p.h/2 , 
        width ,
        height ,
        speed
    });

    bullets.push_back({
        p.x + p.w -5,
        p.y + p.h/2 , 
        width ,
        height ,
        speed
    });
  }

}

void movebullet(vector<bullet_pos> &bullets , float dt)
{
	for(int i = 0 ; i < bullets.size() ; i++){
    bullets[i].velocity = bullets[i].velocity  + acceleration;
		bullets[i].y += bullets[i].velocity*dt;
  }
}
