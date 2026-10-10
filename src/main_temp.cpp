#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>

int main( int argc , char * argv[])
{
  bool done = false; 
  bool a = SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window;
  window = SDL_CreateWindow("Try not to shoot",
                              800,
                              600,
                              SDL_WINDOW_BORDERLESS);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
  
  if (!renderer) {
      SDL_Log("Couldn't create renderer: %s", SDL_GetError());
      return -1;
  }


  SDL_Event event;

  while(!done)
  {
    while(SDL_PollEvent(&event))
    {
        // 2. Allow the window to be closed safely
        if (event.type == SDL_EVENT_QUIT) {
            done = true;
        }
    }

    // 3. Draw a frame so the Wayland compositor maps the window
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255); // Dark gray background
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  // 4. Explicit cleanup before SDL_Quit()
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();
  }
