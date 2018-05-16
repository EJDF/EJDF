#pragma once
#include <vector>
#include "Log.h"
#include "Input.h"
#include "State.h"

namespace Engine{
    class Window;
    /*
      StateHandler
      Handles the current gamestate and level
      Allows for swapping of state using the `changeState()' function.
      Changing of the state pulls from the vector of preexisting states.
     */
    class StateHandler{
        Window *window;
        std::vector<State> states;
        State curState;
    public:
        void init(Window *window);
        void addState(State curState);
        void changeState(unsigned int index);
        void update(InputHandler inputHandler);
    };
}
