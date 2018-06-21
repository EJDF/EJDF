#pragma once
#include "Actor.h"

namespace Engine{
    /*
      Player
      This is the player-controlled character.
      Only one of these should be in any given scene.
      If co-op functionality is added later on, then this will
      need a full rewrite of sorts, or other players will simply
      be "NPC"s.
     */
    class Player : public Actor{
    public:
        Player(Window *window, std::string spriteFilename,
                       unsigned int id, Vec2 startPos,
                       unsigned int width, unsigned int height);
        void move(Vec2f deltaVec);
        void update(InputHandler inputHandler);
    };
}
