#pragma once
#include <SDL2/SDL.h>
#include "Log.h"
#include "Vec2.h"

namespace Engine{
    /*
      Sprite
      This is the low-level abstraction over SDL rectangles.
      It is a wrapper around SDL functions providing a somewhat higher level
      version.
      
      Sprite's use should be avoided in-game. Instead, a higher level abstraction
      like GameObject's derivatives.

      Sprite images should be a linear list of frames (spritesheet).
      They should be ordered as:
      FRAME: 0 1 2 3 4 5 ... n. They should all be on the same line.
    */
    class Sprite{
        SDL_Surface *surface;
        SDL_Rect rect;
        SDL_Rect destRect;
        int width, height;
        Vec2 pos; // on screen coordinates
        //Vec2 globalPos; // global in-game position (currently unused)
    public:
        Sprite(int x, int y, int w, int h, std::string filename);
        Vec2 getPos();
        Vec2 getGlobalPos();
        void move(Vec2 deltaVec);
        void draw(SDL_Surface *dest);
        void despawn();
        void animate(int deltaX, int deltaY);
        void playAnimation(unsigned int length, unsigned int startFrame);
    };
}
