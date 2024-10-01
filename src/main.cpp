#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "render/renderer.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[]) {
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow(
            "Pallete",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
            );
    if (window == NULL) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return 1;
    }
    screenSurface = SDL_GetWindowSurface(window);
    renderer *ren = new renderer(window);
    SDL_Event event;
	// game here
	bool playing = true; 
	while (playing) {
		ren->render();
        
        while( SDL_PollEvent( &event ) ){
            switch(event.type){
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    std::cout << "Key pressed: " << event.key.keysym.sym << std::endl;
                    break;

                /* SDL_QUIT event (window close) */
                case SDL_QUIT:
                    playing = false;
                    break;

                default:
                    break;
            }

        }
		// renderGameFrame();
	}
	

    delete(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
