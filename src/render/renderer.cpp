#include <stdio.h>
#include <iostream>
#include "renderer.h"

void renderer::render() {
    // std::cout << "testr" << std::endl;
    SDL_UpdateWindowSurface(window);
}