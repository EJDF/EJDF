#include <SDL2/SDL.h>
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
