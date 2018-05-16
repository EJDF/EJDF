#include "GameEngine.h"

namespace Engine{
    /*
      State
      Manage the current state, be it a level etc.
     */
    class State{
    public:
        void update(Window window, InputHandler inputHandler);
    };
}
