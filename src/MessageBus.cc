#include "MessageBus.h"

/*
  Message
*/
Engine::Message::Message(std::string event){
    this->event = event;
}

std::string Engine::Message::getEvent(){
    return this->event;
}

/*
  MessageBus
*/

void Engine::MessageBus::send(Engine::Message message){
    msgQueue.push(message);
}

void Engine::MessageBus::addListener(Engine::Listener *listener){
    listeners.push_back(listener);
}

// all listeners are notified (including the sender)
void Engine::MessageBus::notify(){
    while(!msgQueue.empty()){ // ensure there are messages
        this->logMessage(msgQueue.front().getEvent());
        for(Engine::Listener *listener : listeners){
            listener->receive(msgQueue.front());
        }
        msgQueue.pop();
    }
}

/*
  Listener
*/

Engine::Listener::Listener(MessageBus *bus){
    this->bus = bus;
}

void Engine::Listener::send(Message message){
    this->bus->send(message);
    this->bus->notify();
}

void Engine::Listener::update(){ }

void Engine::Listener::receive(Message message){ }


/*
  LOGGING FUNCTIONS
*/

void Engine::MessageBus::logMessage(std::string msg){
    std::cout << msg << "\n";
}


void Engine::MessageBus::logNote(std::string msg){
    std::cout << "[NOTE] " << msg << "\n";
}


void Engine::MessageBus::logWarning(std::string msg){
    std::cout << "[WARNING] " << msg << "\n";
}


void Engine::MessageBus::logError(std::string msg){
    std::cout << "[ERROR] " << msg << "\n";
}


void Engine::MessageBus::logFatalError(std::string msg){
    std::cout << "[FATAL ERROR] " << msg << "\n";
    exit(1);
}


/*
  Console
*/

void Engine::MessageBus::getConsoleInput(){
    std::string input;
    std::cout << "> ";
    std::cin >> input;

    Engine::Message msg(input);
    this->send(msg);
}
