#include "Log.h"
#include <string>
#include "GameEngine.h"
#include "StateHandler.h"
#include "TestScene.h"

void Engine::StateHandler::init(Engine::Window *window){
    this->window = window;

    // create the initial state
    TestScene *firstState = new TestScene();
    this->addState(firstState);
    this->changeState(0); // go to the first state
}

// change the current state to be the state at index i.
void Engine::StateHandler::changeState(unsigned int index){
    //ensure that this state is valid
    if(index < (this->states.size() - 1)){
        // swap the state
        this->curState = index;
    }
}

// add a new state into the states vector
void Engine::StateHandler::addState(Engine::State *newState){
    this->states.push_back(newState);
}

void Engine::StateHandler::update(Engine::InputHandler inputHandler){
    // make sure that the current state is not null.
    if(this->states[curState] != nullptr){
        this->states[curState]->update(this->window, inputHandler);
    }
}
