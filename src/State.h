#pragma once
#include <vector>
#include "GameObject.h"

namespace Engine{
    /*
      State (Abstract)

      Manage the current state, be it a level etc.
      A state is a level or menu or whatever. For example, level1 would be
      just a state called E1M1. They are all classes derived from this
      abstract one.

      Each derived state is called a "Scene", the header and code associated
      are all stored in the `scenes/' directory in the source directory.

      Created states require a constructor to start up any sprites or
      whatever is needed. At some point I may add a vector to this
      abstract class to manage the sprites or other game objects.
    */
    class State{

    public:

        // the objects in the current scene.
        std::vector<GameObject *> objs;
        // background tiles.
        std::vector<Sprite> tiles;
        Window *window;
        // abstract state updater.
        // this is the only function required for each state.
        virtual void update(InputHandler inputHandler) = 0;
        void loadTiles(std::string mapFilename);
    };
}
