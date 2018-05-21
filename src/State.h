#pragma once
#include "GameEngine.h"

namespace Engine{
    /*
      State
      Manage the current state, be it a level etc.
      abstract class.
     */
    class State{
    public:
        // abstract state updater
        virtual void update(Window *, InputHandler inputHandler) = 0;
    };
}
