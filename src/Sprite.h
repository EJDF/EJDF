#pragma once
#ifdef __MINGW32__
#include <SDL.h> // on windows, the header is just SDL2.h
#else
#include <SDL2/SDL.h> // on UNIX, the header is in the SDL2 dir.
#endif
#include "Log.h"
#include "Vec2.h"
#include "Input.h"

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
        Vec2f pos; // on screen coordinates
        Vec2f velocity; // movement velocity
        double accelerationRate;
        double decelerationRate;
        double maxSpeed; // the maximum movement speed of the spite
    public:
        Sprite() { }
        Sprite(int x, int y, int w, int h, std::string filename);
        Vec2f getPos();
        Vec2 getGlobalPos();
        void move(Vec2f deltaVec);
        void draw(SDL_Surface *dest);
        void despawn();
        void animate(int deltaX, int deltaY);
        void playAnimation(unsigned int length, unsigned int startFrame);
        bool showing; // should be rendered?
    };
}
