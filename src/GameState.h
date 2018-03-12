#pragma once
#include "Input.h"
#include "Scene.h"

namespace Engine{
    class Window;
    /*
      GameState
      Maintains the state of a given scene
     */
    class GameState{
        Scene scene;
    public:
        void init(Window window);
        void update(Window window, InputHandler inputHandler);
    };
}
