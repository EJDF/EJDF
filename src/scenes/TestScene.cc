#include "TestScene.h"
#include "../Log.h"

TestScene::TestScene(){
    Engine::Log::note("Creating tiles.");
    this->loadTiles("res/test.map");
}

void TestScene::update(Engine::Window *window, Engine::InputHandler inputHandler){
    for(Engine::Sprite tile : this->tiles){
        tile.draw(window->getSurface());
    }
}
