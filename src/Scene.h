#pragma once
#include "HitagiFile.h"
#include "GameState.h"


namespace Engine{

    /*
      Scene
      Abstraction for loading pre-created content
     */
    class Scene{
        GameState state;
        // the loaded file with the scene blob
        std::vector<unsigned char> hitagiFile;
    };
}
