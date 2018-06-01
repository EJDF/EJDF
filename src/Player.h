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
    class Player : Actor{
    public:
        Player();
        void move(InputHandler inputHandler);
        void update(Engine::InputHandler inputHandler);
    };
}
