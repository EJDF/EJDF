#include "Sprite.h"
#include "Log.h"

Engine::Sprite::Sprite(int x, int y, int w, int h, std::string filename)
    : pos(x, y){

    this->width = w;
    this->height = h;
    
    this->surface = NULL; // initialize as null for error checking
    this->surface = SDL_LoadBMP(filename.c_str()); // load image

    if(!surface) // check if bmp load was a success
        Engine::Log::fatalError(std::string("Failed to load sprite "
                                            , SDL_GetError()));
    
    // make background transparent (white)
    SDL_SetColorKey(this->surface, SDL_TRUE,
                    SDL_MapRGB(this->surface->format, 255, 255, 255));

    if(!surface) // check if color key worked
        Engine::Log::fatalError(std::string("Failed to init sprite "
                                            , SDL_GetError()));


    // setup rect
    rect.w = this->width;
    rect.h = this->height;

    // since this is a buffer, just leave it at (0,0)
    rect.x = 0;
    rect.y = 0;

    destRect.w = this->width;
    destRect.h = this->height;

    destRect.x = this->pos.x;
    destRect.y = this->pos.y;

    // all sprites are showing by default.
    // showing is a public member variable.
    this->showing = true;

    // movement physics constants
    this->accelerationRate = .03;
    this->decelerationRate = 0.1;
    this->maxSpeed = 4.0;
    
}

void Engine::Sprite::draw(SDL_Surface *dest){
    if(!(this->showing)) return; // if the sprite is not showing, don't draw.
    SDL_BlitSurface(this->surface, &this->rect, dest, &destRect);
}

Engine::Vec2f Engine::Sprite::getPos(){
    return this->pos;
}

// vector is how far it's moving
void Engine::Sprite::move(Engine::Vec2f deltaVec){

    // horizontal movement.
    if(deltaVec.x == 1) this->velocity.x += this->accelerationRate;
    else if(deltaVec.x == -1) this->velocity.x -= this->accelerationRate;
    else this->velocity.x = this->velocity.x * this->decelerationRate;

    // vertical movement
    if(deltaVec.y == 1) this->velocity.y += this->accelerationRate;
    else if(deltaVec.y == -1) this->velocity.y -= this->accelerationRate;
    else this->velocity.y = this->velocity.y * this->decelerationRate;
    
    // ensure that the sprite does not move too fast
    // clamp the speed.
    // a^2 + b^2 = c^2 : pyguy's theory
    double speed = sqrt((this->velocity.x * this->velocity.x) +
                        (this->velocity.y * this->velocity.y));
    if(speed > this->maxSpeed)
        // scalar to clamp it down
        this->velocity = this->velocity * (this->maxSpeed / speed);

    // update the position.
    this->pos = this->pos + this->velocity;
    destRect.x = this->pos.x;
    destRect.y = this->pos.y;
}

void Engine::Sprite::despawn(){
    SDL_FreeSurface(this->surface);
}


/* 
   animate the sprite by providing a change in offset for the frame
   assuming the sprite is 8x8 and you have a spritesheet with another 
   frame to the right of the current one you would provide a deltaX 
   offset of 8px because that would move the frame 8 frames to the right.
   All this function does is modifies the frame offset
*/

void Engine::Sprite::animate(int deltaX, int deltaY){
    this->rect.x += deltaX;
    this->rect.y += deltaY;
}

/*
  plays an animation given a length (in frames) and what frame is being started on.
  length of 5 and a start frame of 1 would play from frame 1 to frame until frame 6.
  spritesheets are like: 0 1 2 3 4 5 ... n
*/
void Engine::Sprite::playAnimation(unsigned int length, unsigned int startFrame){
    for(unsigned int frame = startFrame * this->width; frame < length; frame++){
        this->animate((frame * this->width), 0);
    }
}
