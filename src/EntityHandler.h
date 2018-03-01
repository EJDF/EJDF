#pragma once
#include <vector>
#include "GameEngine.h"
#include "Sprite.h"


namespace Engine{
    /*
      Entity Handler
      Handles entities in a given scene
     */
    class EntityHandler{
        std::vector<Engine::Sprite> entities;
        Engine::Window window;
    public:
        void init(Engine::Window window);
        void updateEntities();
        void add(Engine::Sprite sprite);
    };
}
