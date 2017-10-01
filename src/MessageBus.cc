#include "MessageBus.h"
#include "Log.h"

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
        Engine::Log::message(msgQueue.front().getEvent());
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
  Console
*/

void Engine::MessageBus::getConsoleInput(){
    std::string input;
    std::cout << "> ";
    std::cin >> input;

    Engine::Message msg(input);
    this->send(msg);
}
