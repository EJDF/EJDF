#include "TestScene.h"
#include "../Log.h"
#include "../Player.h"
#include "../Vec2.h"

TestScene::TestScene(Engine::Window *window){
#ifdef __EJDF_DEBUG
    Engine::Log::note("Creating tiles.");
#endif
    this->window = window;
    // load all of the tiles in `test.map'.
    this->loadTiles("res/test.map");
    // add a test player.
#ifdef __EJDF_DEBUG
    Engine::Log::note("Creating a player.");
#endif
    this->objs.push_back(new Engine::Player(this->window,
                                            "res/test.bmp", 0, Engine::Vec2(100,0),
                                            32, 32));
}

void TestScene::update(Engine::InputHandler inputHandler){
    // draw all of the background tiles in the current state.
    for(Engine::Sprite tile : this->tiles){
        tile.draw(this->window->getSurface());
    }
    // draw all of the game objects in the current state.
    for(auto &obj : this->objs){
        obj->update(inputHandler);
        obj->draw();
    }
}
