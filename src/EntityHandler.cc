#include "EntityHandler.h"
#include "Vec2.h"
#include "Log.h"

void Engine::EntityHandler::init(Engine::Window window){
    this->window = window;
}

void Engine::EntityHandler::updateEntities(){
    for(auto& sprite : this->entities){
        sprite.draw(this->window.getSurface());
        sprite.move(Vec2(10,10));
    }
}

void Engine::EntityHandler::add(Engine::Sprite sprite){
    this->entities.push_back(sprite);
}
