#include "GameObject.h"

// Initializes with all the core fields
Engine::GameObject::GameObject(Window *window, std::string spriteFilename,
                               unsigned int id, Vec2 startPos,
                               unsigned int width, unsigned int height)
    : sprite(startPos.x, startPos.y, width, height, spriteFilename), id(id){
    this->window = window;
}

// get the uid of the object.
unsigned int Engine::GameObject::getID(){
    return this->id;
}

// draw to the screen.
void Engine::GameObject::draw(){
    this->sprite.draw(this->window->getSurface());
}

// play a given animation.
void Engine::GameObject::animate(unsigned int length, unsigned int startFrame){
    this->sprite.playAnimation(length, startFrame);
}
