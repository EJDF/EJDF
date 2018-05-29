#ifdef __MINGW32__
#include <SDL.h> // on windows, the header is just SDL2.h
#else
#include <SDL2/SDL.h> // on UNIX, the header is in the SDL2 dir.
#endif

#include "Event.h"
// Pass function events from the main loop in order to handle keys / quitting
// return true on 
bool eventHandler(SDL_Event event, Engine::InputHandler *inputHandler){
    if(event.type == SDL_QUIT){
        return false;
    }else if(event.type == SDL_KEYDOWN){ // key is pressed
        switch(event.key.keysym.sym){
        case SDLK_LEFT:
            inputHandler->left = true;
            break;
        case SDLK_RIGHT:
            inputHandler->right = true;
            break;
        case SDLK_DOWN:
            inputHandler->down = true;
            break;
        case SDLK_UP:
            inputHandler->up = true;
            break;
        }
    }else if(event.type == SDL_KEYUP){ // key is released
        switch(event.key.keysym.sym){
        case SDLK_LEFT:
            inputHandler->left = false;
            break;
        case SDLK_RIGHT:
            inputHandler->right = false;
            break;
        case SDLK_DOWN:
            inputHandler->down = false;
            break;
        case SDLK_UP:
            inputHandler->up = false;
            break;
        }
    }
    

    return true;
}
