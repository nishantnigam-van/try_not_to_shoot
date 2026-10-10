#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>

int main(int argc , char* argv[]){

  bool done = false ;

  if(!SDL_Init(SDL_INIT_VIDEO))
  {
    SDL_Log("Couldnt Initialzie video!");
    return -1;
  }
  SDL_Window * window;
  window = SDL_CreateWindow("Try Not to Shoot",
                              800,
                              600,
                              SDL_WINDOW_FULLSCREEN);
  
  if(!window)
  {
    SDL_Log("couldnt create window!");
    return -1;
  }
  
  SDL_Delay(4000);

//  SDL_Event event;

  /*while(!done)
  {
    while(SDL_PollEvent(&event))
    {
    }
  }
  */

  SDL_Quit();
}
