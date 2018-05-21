#pragma once
#include "State.h"
#include "Log.h"

class TestScene : public Engine::State{
 public:
    TestScene(){
        Engine::Log::note("created");
    }
    void update(Engine::Window *window, Engine::InputHandler inputHandler){
        Engine::Log::note("test");
    }
};
