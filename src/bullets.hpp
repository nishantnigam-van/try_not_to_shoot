#include<SDL3/SDL.h>
#include<vector>
#include"player.hpp"

using namespace std;

#define speed 300.0f //speed of the bullet

struct bullet_pos{
  float x , y;
  float w , h;
};

void shootbullet(player_pos &p , vector<bullet_pos> &bullet );
void drawbullet(SDL_Renderer *r , SDL_Texture *enemy , vector<bullet_pos> &bullets);
void movebullet(vector<bullet_pos> &bullets , float dt);

