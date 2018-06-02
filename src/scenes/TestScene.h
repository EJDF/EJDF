#pragma once
#include "../State.h"


class TestScene : public Engine::State{
public:
    TestScene(Engine::Window *window);
    void update(Engine::InputHandler inputHandler);
};
