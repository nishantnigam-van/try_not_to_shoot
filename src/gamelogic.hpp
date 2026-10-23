#pragma once
#include<SDL3/SDL.h>
#include<vector>
#include"player.hpp"
#include"enemy.hpp"

using namespace std;

bool gameover(player_pos &spaceship , vector<enemy_pos> &enemyship);
