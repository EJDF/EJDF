#pragma once

/*
  Vec2
  A 2-dimensional vector structure with support for standard c++ operators.
*/
namespace Engine{
    struct Vec2{
        int x,y;

        Vec2(int x, int y){
            this->x = x;
            this->y = y;
        }
    
        // add a vector
        Vec2 operator+(Vec2 v1){
            return Vec2(this->x + v1.x, this->y + v1.y);
        }

        // subtract a vector
        Vec2 operator-(Vec2 v1){
            return Vec2(this->x - v1.x, this->y - v1.y);
        }
    };
}
