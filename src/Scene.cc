#include "Scene.h"
#include "Log.h"

int testFunc(){
    Engine::Log::note("function called");
    return 0;
}

void Engine::Scene::init(){
    this->vm = Engine::VM::VM();

    // make the API visible
    this->vm.addFunction("testFunc", (lua_CFunction)testFunc);

    // load the init script (in this case a test)
    this->vm.loadScript("res/scripts/test.lua");
}
