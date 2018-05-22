#include "MessageBus.h"
#include "Log.h"

/* Message */
Engine::Message::Message(std::string event){
    this->event = event;
}

std::string Engine::Message::getEvent(){
    return this->event;
}

/* MessageBus */
void Engine::MessageBus::send(Engine::Message message){
    messageQueue.push(message);
}

void Engine::MessageBus::addListener(Engine::Listener *listener){
    listeners.push_back(listener);
}

// all listeners are notified (including the sender)
void Engine::MessageBus::notify(){
    while(!messageQueue.empty()){ // ensure there are messages
        Engine::Log::message(messageQueue.front().getEvent());
        for(Engine::Listener *listener : listeners){
            listener->receive(messageQueue.front());
        }
        messageQueue.pop();
    }
}

/* 
   Listener 
   Default implementation
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
