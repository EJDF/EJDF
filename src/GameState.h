#pragma once
#include "GameEngine.h"

namespace Engine{
    class Window;
    /*
      GameState
      polymorphic class from which all gamestates are derived
     */
    class GameState{
    public:
        virtual void init(Window window) = 0;
        virtual void update(Window window) = 0;
    };
}
