#pragma once


extern "C"{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <string>
/*
  Lua's API is a C library so it must be included through an "extern" block
*/

namespace Engine{
    /*
      VM
      A c++ wrapper around the Lua API for more pragmatic use.
     */
    class VM{
        // the main lua state
        lua_State *l;
    public:
        VM();
        void addFunction(std::string name, lua_CFunction func);
        void loadScript(std::string name);
        int getTop();
        void pushNum(int number);
        int toNumber(int index);
    };
}
