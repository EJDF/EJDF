#pragma once
#include "GameObject.h"

namespace Engine{
    /*
      Actor
      Player/player-like GameObjects
     */
    class Actor : Engine::GameObject{
    public:
        virtual void move(Engine::InputHandler inputHandler);
    };
}
