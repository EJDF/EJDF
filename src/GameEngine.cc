#include "Log.h"
#include "GameEngine.h"

// init the game engine
Engine::GameEngine::GameEngine(){
    // create the window
    this->initWindow();

    this->resetWindow();

    
}

// initialize the SDL window
int Engine::GameEngine::initWindow(){
    // initialize the SDL variables to NULL because it's a C library.
    this->window = NULL;
    this->surface = NULL;

    // create a window called EJDF of size 800x600.
    this->window = SDL_CreateWindow("EJDF", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED, 800, 600,
                                    SDL_WINDOW_SHOWN);

    // check if window creation worked
    if(!this->window)
        Engine::Log::fatalError(std::string("Could not init SDL",SDL_GetError()));

    this->surface = SDL_GetWindowSurface(this->window);

    if(!this->surface)
        Engine::Log::fatalError(std::string("Could not get a window context",
                                            SDL_GetError()));
    return 0;
}

// update the current state along with the SDL window.
void Engine::GameEngine::update(){
    SDL_UpdateWindowSurface(this->window);
}

// reset the window to white
inline void Engine::GameEngine::resetWindow(){
    SDL_FillRect(this->surface, NULL,
                 SDL_MapRGB(this->surface->format, 255, 255, 255));

}

/*
  Getters for the low-level SDL parts of the engine.
*/
SDL_Window *Engine::GameEngine::getWindow(){
    return this->window;
}

SDL_Surface *Engine::GameEngine::getSurface(){
    return this->surface;
}
