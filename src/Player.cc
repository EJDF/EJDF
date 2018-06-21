#include "Player.h"
#include "Input.h"

Engine::Player::Player(Engine::Window *window, std::string spriteFilename,
                       unsigned int id, Engine::Vec2 startPos,
                       unsigned int width, unsigned int height){
    this->health = 100;
    this->window = window;
    this->sprite = Sprite(startPos.x, startPos.y, width, height, spriteFilename);
    this->id = id;
}

void Engine::Player::move(Engine::Vec2f deltaVec){
    // add the vector
    this->sprite.move(deltaVec);
}


void Engine::Player::update(Engine::InputHandler inputHandler){
    Engine::Vec2f deltaVec;
    if(inputHandler.left) {
        deltaVec.x += -1;
    }
    if(inputHandler.right) {
        deltaVec.x += 1;
    }
    if(inputHandler.up) {
        deltaVec.y += -1;
    }
    if(inputHandler.down) {
        deltaVec.y += 1;
    }
    this->move(deltaVec);
}
