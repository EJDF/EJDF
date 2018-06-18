#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "IOManager.h"
#include "State.h"

/* 
   loadMap
   load a .map file into the state's memory.
   loads into the `tiles' vector.
   
   map files are a simple linear array of numbers
   those numbers correspond to the tile image.
*/
void Engine::State::loadTiles(std::string mapFilename){
    std::fstream file(mapFilename, std::ios_base::in);
    
    // load the file into the `tiles' vector.
    std::string curTile;
    for(int y = 0; y < 640; y+= 32){
        for(int x = 0; x < 800; x += 32){
            file >> curTile; // get the current tile
            // load the image as a new sprite into the `tiles' vector.
            this->tiles.
                push_back(Sprite(x, y, 32, 32,
                                 "res/tiles/" + curTile + ".bmp"));
        }
    }
}


