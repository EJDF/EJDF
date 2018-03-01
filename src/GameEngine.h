#pragma once
#include <SDL2/SDL.h>
#include "Log.h"

namespace Engine{
    /*
      GameEngine
      The primary class containing the game engine.
      This class is in charge of the main event loop along with display code
      until display code is compartmentalized into it's own thread.
      This is either temporary or permanent depending on how workable it is.
     */
    class GameEngine{
        SDL_Window *window;
        SDL_Surface *surface;

    public:
        GameEngine();
        int initWindow();
        void update();
        void mainLoop();
        inline void resetWindow();
        SDL_Window *getWindow();
        SDL_Surface *getSurface();
        
    };
}
