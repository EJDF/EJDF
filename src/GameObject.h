#pragma once
#include "GameEngine.h"
#include "Sprite.h"

namespace Engine{
    /*
      GameObject
      This is the level above sprite in terms of abstraction over SDL.
      State manages a list of pointers to these objects.
      
      Each time a gameobject is added to a scene, the ID is incrememnted, 
      regardless if those before have been removed already. The ID
      is immutable.

      Each frame, every GameObject in a given scene is updated with 
      its independent implementation of update().

      GameObject exists as a semi-abstract class to be implemented by
      each object. Players, enemies, boxes, etc. all implement this class.
     */
    class GameObject{
    protected:
        Sprite sprite;
        Window *window;
    public:
        unsigned int id; /* independent ID for current scene.
                                  This ID is incremented for each 
                                  GameObject added to a scene.*/
        GameObject() : id(0), window(NULL) { }
        GameObject(Window *window, std::string spriteFilename,
                   unsigned int id, Engine::Vec2 startPos,
                   unsigned int width, unsigned int height);
        
        unsigned int getID();
        void draw();
        void animate(unsigned int length, unsigned int startFrame);

        virtual void update(Engine::InputHandler inputHandler) = 0;
    };
}
