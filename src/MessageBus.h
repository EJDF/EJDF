#pragma once
#include <iostream>
#include <queue>
#include <vector>

/*
  Engine
  Namespace for all core functionality (non-gameplay / video / audio stuff)
*/
namespace Engine{
    // FORWARD DEFINITIONS //
    class MessageBus;
    class Message;
    class Listener;
    
    /*
      Listener
      Endpoint for messages -- to be derived from (semi-abstract parent class)
     */
    class Listener{
        MessageBus *bus;

    public:
        Listener(MessageBus *bus);
        virtual void receive(Message message); // bus calls for incoming msg
        virtual void send(Message message); // abstract away bus call
        virtual void update(); // every implementation will need to update in some way
    };
    
    
    /*
      Message
      The communication format over the MessageBus
    */
    class Message{
        std::string event; // the event for the current message
    public:
        Message(std::string event);
        std::string getEvent();
        
    };

    /*
      MessageBus
      Class for passing messages and communicating
    */
    class MessageBus{
        std::queue<Message> msgQueue;
        std::vector<Listener*> listeners;

    public:
        void send(Message message); // push given message onto the message queue
        void addListener(Listener *listener);
        void notify(); // notify listeners 
    };
}
