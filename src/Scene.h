#pragma once
#include "HitagiFile.h"
#include "GameState.h"
#include "LuaVM.h"

namespace Engine{

    /*
      Scene
      Abstraction for loading pre-created content
     */
    class Scene{
        VM vm;
        // the loaded file with the scene blob
        std::vector<unsigned char> hitagiFile;
    public:
        void init();
    };
}
