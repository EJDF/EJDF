#include <iostream>
#include <SDL2/SDL.h>
#include "Log.h"
#include "GameEngine.h"
#include "HitagiFile.h"

int main(int argc, char **argv){
    // start SDL
    if(SDL_INIT_EVERYTHING < 0)
        Engine::Log::fatalError("Could not start SDL");

    
    // create the engine (so many namespaces)
    Engine::GameEngine::GameEngine engine = Engine::GameEngine::GameEngine();

    // load a test file
    Engine::HitagiFile file =
        Engine::HitagiFile::HitagiFile(std::string("res/content.hitagi"));
    
    return 0;
}
