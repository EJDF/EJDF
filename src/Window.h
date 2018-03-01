#pragma once
#include <SDL2/SDL.h>

class Window{
    SDL_Window *window;
    SDL_Surface *surface;

 public:
    Window();
    SDL_Surface *getSurface();
    SDL_Window *getWindow();
};
