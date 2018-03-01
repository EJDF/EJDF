#include "Log.h"


void Engine::Log::message(std::string msg){
    std::cout << msg << "\n";
}


void Engine::Log::note(std::string msg){
    std::cout << "[NOTE] " << msg << "\n";
}


void Engine::Log::warning(std::string msg){
    std::cout << "[WARNING] " << msg << "\n";
}


void Engine::Log::error(std::string msg){
    std::cout << "[ERROR] " << msg << "\n";
}


void Engine::Log::fatalError(std::string msg){
    std::cout << "[FATAL ERROR] " << msg << "\n";
    exit(1);
}
