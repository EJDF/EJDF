#include "EntityHandler.h"

void Engine::EntityHandler::init(Engine::Window window){
    this->window = window;
}

void Engine::EntityHandler::updateEntities(){
    for(auto& sprite : this->entities){
        sprite.draw(this->window.getSurface());
    }
}

void Engine::EntityHandler::add(Engine::Sprite sprite){
    this->entities.push_back(sprite);
}
