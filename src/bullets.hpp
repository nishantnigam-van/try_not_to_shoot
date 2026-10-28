#include<SDL3/SDL.h>
#include<vector>
#include"player.hpp"

using namespace std;

#define speed -300.0f //speed of the bullet
#define acceleration -10.0f //acceleration of bullet
#define width 4.0f
#define height 27.0f

struct bullet_pos{
  float x , y;
  float w , h;
  float velocity;
};

void shootbullet(player_pos &p , vector<bullet_pos> &bullet );
void drawbullet(SDL_Renderer *r , SDL_Texture *enemy , vector<bullet_pos> &bullets);
void movebullet(vector<bullet_pos> &bullets , float dt);

