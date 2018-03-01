#pragma once
#include <SDL2/SDL.h>
#include "Log.h"
#include "Vec2.h"

namespace Engine{
    /*
      Sprite
      This is the low-level abstraction over SDL rectangles.
      It is a wrapper around SDL functions providing a somewhat higher level
      version. This is not to be used in game code, instead the higher level classeses
      should be used in order to draw to the screen.
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
    };
}
