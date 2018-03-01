#pragma once

/*
  InputHandler
  Structure for managing state of what keys have been pressed
*/
namespace Engine{
    struct InputHandler{
        bool left = false;
        bool right = false;
        bool down = false;
        bool up = false;
    };
}
