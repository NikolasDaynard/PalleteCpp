#pragma once
#include <SDL2/SDL.h>

class renderer {
public:
    SDL_Window *window;
    
    void render();
    renderer(SDL_Window *newWindow) {
        window = newWindow;
    }
    ~renderer() {

    }
};