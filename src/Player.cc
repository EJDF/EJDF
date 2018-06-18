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

void Engine::Player::move(Engine::Vec2 delta){
    // add the vector
    this->sprite.move(delta);
}


void Engine::Player::update(Engine::InputHandler inputHandler){
    // TODO updates.
    // drawing is handled by sprite.
    if(inputHandler.left){
        Engine::Log::note("Move left.");
        this->move(Vec2(-1,0));
    }
    if(inputHandler.right){
        Engine::Log::note("Move right.");
        this->move(Vec2(1,0));
    }
    if(inputHandler.up){
        Engine::Log::note("Move up.");
        this->move(Vec2(0,-1));
    }
    if(inputHandler.down) {
        Engine::Log::note("Move down.");
        this->move(Vec2(0,1));
    }
}
