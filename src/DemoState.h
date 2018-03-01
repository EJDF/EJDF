#pragma once
#include "GameEngine.h"
#include "GameState.h"
#include "EntityHandler.h"
#include "Log.h"

class Demo : public Engine::GameState{
    Engine::EntityHandler entities;
 public:
    void init(Engine::Window window){
        // careful about compiling in the right directory with loading this
        // if you load in the wrong place depending on your OS it'll segfault
        // trying to load this file.
        entities.init(window);
        entities.add(Engine::Sprite(10,10,50,50, "../res/test.bmp"));
    }

    void update(Engine::Window window, Engine::InputHandler inputHandler){
        entities.updateEntities();
        if(inputHandler.left){
            Engine::Log::note("fff");
        }
    }
};
