#include "TestScene.h"
#include "../Log.h"

TestScene::TestScene(){
    Engine::Log::note("created");
}

void TestScene::update(Engine::Window *window, Engine::InputHandler inputHandler){
    Engine::Log::note("test");
}
