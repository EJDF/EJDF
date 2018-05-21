#pragma once
#include "../State.h"


class TestScene : public Engine::State{
public:
    TestScene();
    void update(Engine::Window *window, Engine::InputHandler inputHandler);
};
