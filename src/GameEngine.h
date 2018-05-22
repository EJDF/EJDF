#pragma once
#include <SDL2/SDL.h>
#include "Log.h"
#include "Input.h"

namespace Engine{
    class StateHandler;
    
    /*
      Window
      Maintains the SDL window stuff

      Abstraction over the low-level code. 
     */
    class Window{
        SDL_Window *window;
        SDL_Surface *surface;
    public:
        Window(){}
        SDL_Window *getWindow();
        SDL_Surface *getSurface();
        int initWindow();
        inline void resetWindow();
    };
    
    /*
      GameEngine
      The primary class containing the game engine.

      This class is in charge of the main event loop along with display code
      until display code is compartmentalized into it's own thread.

      This is either temporary or permanent depending on how workable it is.
     */
    class GameEngine{
        Window window;
        StateHandler *handler;
        
    public:
        GameEngine();
        ~GameEngine();
        int initWindow();
        void update(Engine::InputHandler inputHandler);
        void mainLoop();
    };
}
