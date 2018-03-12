#include "LuaVM.h"

// setup the lua vm
Engine::VM::VM(){
    this->l = luaL_newstate();
}

void Engine::VM::addFunction(std::string name, lua_CFunction func){
    lua_register(this->l, name.c_str(), func);
}
