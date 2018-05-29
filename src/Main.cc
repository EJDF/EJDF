#include <iostream>
#ifdef __MINGW32__
#include <SDL.h> // on windows, the header is just SDL2.h
#else
#include <SDL2/SDL.h> // on UNIX, the header is in the SDL2 dir.
#endif
#include "Log.h"
#include "GameEngine.h"

int main(int argc, char **argv){
    // start SDL
    if(SDL_INIT_EVERYTHING < 0)
        Engine::Log::fatalError("Could not start SDL");

    
    // create the engine (so many namespaces)
    // this is the initial point of the game.
    Engine::GameEngine engine = Engine::GameEngine();

    return 0;
}
