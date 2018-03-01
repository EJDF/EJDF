#include "Log.h"
#include "GameEngine.h"
#include "Event.h"

// for demo mode, load the demo state.
#include "DemoState.h"

// maximum number of frames per second
#define MAX_FRAMES 60

// init the game engine
Engine::GameEngine::GameEngine(){
    // create the window
    this->window.initWindow();
    
    this->window.resetWindow();

    this->currentState = new Demo();

    this->currentState->init(this->window);
    
    this->mainLoop();
}

// free all the stuff allocated
Engine::GameEngine::~GameEngine(){
    // TOOD: dealloc gamestate
    //delete this->currentState;
}

// initialize the SDL window
int Engine::Window::initWindow(){
    // initialize the SDL variables to NULL because it's a C library.
    this->window = NULL;
    this->surface = NULL;

    // create a window called EJDF of size 800x600.
    this->window = SDL_CreateWindow("EJDF", SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED, 800, 600,
                                    SDL_WINDOW_SHOWN);

    // check if window creation worked
    if(!this->window)
        Engine::Log::fatalError(std::string("Could not init SDL",SDL_GetError()));

    this->surface = SDL_GetWindowSurface(this->window);

    if(!this->surface)
        Engine::Log::fatalError(std::string("Could not get a window context",
                                            SDL_GetError()));
    return 0;
}

// update the current state along with the SDL window.
void Engine::GameEngine::update(Engine::InputHandler inputHandler){
    this->currentState->update(this->window, inputHandler);
    SDL_UpdateWindowSurface(this->window.getWindow());

}

void Engine::GameEngine::mainLoop(){
    int initTick; // first tick
    SDL_Event event; // SDL event used for polling events
    bool quit = false; // condition to exit the main loop

    Engine::InputHandler inputHandler; // controls input

    while(!quit){
        initTick = SDL_GetTicks(); // set the start time for the loop iteration
        this->window.resetWindow(); // clear the screen
        
        this->update(inputHandler); // update the state and the window
        
        while(SDL_PollEvent(&event)){ // get SDL events
            if(!eventHandler(event, &inputHandler)){
                quit = true;
                break;
            }
        }
        
        // TODO: entity handling updates

        // frame limiting
        // change in time since start of current loop
        int deltaTime = (SDL_GetTicks() - initTick); 
        if((1000 / MAX_FRAMES) > deltaTime){
            SDL_Delay((1000 / MAX_FRAMES) - deltaTime); // limit FPS to MAX_FRAMES
        }
        
    }
}

// reset the window to white
inline void Engine::Window::resetWindow(){
    SDL_FillRect(this->surface, NULL,
                 SDL_MapRGB(this->surface->format, 255, 255, 255));

}

// change the current game state
inline void Engine::GameEngine::changeState(Engine::GameState *newState){
    this->currentState = newState;
}

/*
  Getters for the low-level SDL parts of the engine.
*/
SDL_Window *Engine::Window::getWindow(){
    return this->window;
}

SDL_Surface *Engine::Window::getSurface(){
    return this->surface;
}
