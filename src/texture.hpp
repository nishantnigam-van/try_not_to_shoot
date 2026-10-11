#pragma once 
#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>


SDL_Texture * load_svg(SDL_Renderer* r , const char *path,float w , float h);
