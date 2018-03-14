#include "Log.h"
#include "LuaVM.h"

// setup the lua vm
Engine::VM::VM(){
    this->l = luaL_newstate();
    luaL_openlibs(this->l);
}

void Engine::VM::addFunction(std::string name, lua_CFunction func){
    lua_register(this->l, name.c_str(), func);
}

void Engine::VM::loadScript(std::string name){
    if(luaL_dofile(this->l, name.c_str()) != LUA_OK){
        Engine::Log::fatalError("Could not load script: " + name);
    }
}

int Engine::VM::getTop(){
    return lua_gettop(this->l);
}

void Engine::VM::pushNum(int number){
    lua_pushnumber(this->l, number);
}

// get the number at the given index on the lua stack
int Engine::VM::toNumber(int index){
    return lua_tonumber(this->l, index);
}
