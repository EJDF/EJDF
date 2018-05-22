#pragma once
#include <iostream>
#include <queue>
#include <vector>

/*
  The purpose of a messagebus is to provide a way for threads to communicate.
  It provides a "subscriber/listener" functionality that allows for a sorta
  Javascript-style event system. Any class can be set as a listener, and that
  provides them with a reference to an event.

  Anyone with a reference to a message bus can listen for events on that
  channel. Due to the announcement type, a class should only subscribe to
  what it needs because otherwise it will get bogged down with unnecessary
  announcements.
*/

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

      Thread classes that are going to be listening for events should derive
      from this.
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

      It effectively just carries a string, thus RPC can only
      be implemented on the side of the listener. 

      In theory, this could later be designed to send more 
      information, like a JSON object or XML or something. 
      However, it's really just designed to send a short, 
      concise string for RPC.
    */
    class Message{
        std::string event; // the event for the current message
    public:
        Message(std::string event);
        std::string getEvent();
        
    };

    /*
      MessageBus
      Class for passing messages and communicating.

      A reference to a given bus is given to listeners
      when the abstract class is derived down the line.

      This bus operates on a queue which provides some 
      sembelence of thread safety.
    */
    class MessageBus{

        // the queue that manages messages on the bus
        std::queue<Message> messageQueue;
        // the number of listeners on a given bus is dynamic
        std::vector<Listener*> listeners; 

    public:        
        void send(Message message); // push given message onto the message queue
        void addListener(Listener *listener);
        void notify(); // notify listeners 
    };
}
