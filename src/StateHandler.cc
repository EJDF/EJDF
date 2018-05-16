#include "GameEngine.h"
#include "StateHandler.h"


void Engine::StateHandler::init(Engine::Window *window){
    this->window = window;
}

// change the current state to be the state at index i.
void Engine::StateHandler::changeState(unsigned int index){
    //ensure that this state is valid
    if(index < (this->states.size() - 1)){
        // swap the state
        this->curState = this->states[index];
    }
}

// add a new state into the states vector
void Engine::StateHandler::addState(Engine::State newState){
    this->states.push_back(newState);
}

void Engine::StateHandler::update(Engine::InputHandler inputHandler){
    this->curState.update(*(this->window), inputHandler);
}
