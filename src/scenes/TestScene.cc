#include "TestScene.h"
#include "../Log.h"

TestScene::TestScene(){
    Engine::Log::note("Creating tiles.");
    
    // example tiles, just fill up the whole screen
    for(int y=0; y<20; y++){
        for(int x=0; x<25; x++){
            this->tiles.
                push_back(Engine::Sprite(x * 32, y * 32, 32, 32,
                                         (x % 2 == 0) ? "res/tile1.bmp" : "res/tile2.bmp"));
        }
    }
}

void TestScene::update(Engine::Window *window, Engine::InputHandler inputHandler){
    for(Engine::Sprite tile : this->tiles){
        tile.draw(window->getSurface());
    }
}
