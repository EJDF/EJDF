#pragma once
#include <cmath>

/*
  Vec2
  A 2-dimensional vector structure with support for standard c++ operators.
  supports +, -, *.
*/
namespace Engine{
    struct Vec2{
        int x,y;

        // default constructor zeros out location.
        Vec2(){
            this->x = 0;
            this->y = 0;
        }
        
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

        // scalar multiplication for vector
        Vec2 operator*(int scalar){
            return Vec2(this->x * scalar, this->y * scalar);
        }

        // multiply two vectors together
        Vec2 operator*(Vec2 v2){
            return Vec2(this->x * v2.x, this->y * v2.y);
        }

        // calculate the dot product of two vectors
        int dot(Vec2 v1){
            return ((this->x * v1.x) + (this->y * v1.y));
        }
        
        // calculate the magnitude of the vector
        double getMagnitude(){
            return sqrt(abs(this->x * this->x) + abs(this->y * this->y));
        }
    };

    // a floating-point vector.
    struct Vec2f{
        double x,y;

        // default constructor zeros out location.
        Vec2f(){
            this->x = 0.0;
            this->y = 0.0;
        }
        
        Vec2f(double x, double y){
            this->x = x;
            this->y = y;
        }
    
        // add a vector
        Vec2f operator+(Vec2f v1){
            return Vec2f(this->x + v1.x, this->y + v1.y);
        }

        // subtract a vector
        Vec2f operator-(Vec2f v1){
            return Vec2f(this->x - v1.x, this->y - v1.y);
        }

        // scalar multiplication for vector
        Vec2f operator*(double scalar){
            return Vec2f(this->x * scalar, this->y * scalar);
        }

        // multiply two vectors together
        Vec2f operator*(Vec2f v2){
            return Vec2f(this->x * v2.x, this->y * v2.y);
        }

        // calculate the dot product of two vectors
        double dot(Vec2f v1){
            return ((this->x * v1.x) + (this->y * v1.y));
        }
        
        // calculate the magnitude of the vector
        double getMagnitude(){
            return sqrt(abs(this->x * this->x) + abs(this->y * this->y));
        }
    };
    
}
