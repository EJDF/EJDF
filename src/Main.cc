#include <iostream>
#include <thread>
#include <chrono>

#include "MessageBus.h"

Engine::MessageBus bus; // global for testing, wont be in reality
void threadTestOne(); // first function for testing multithreading
void threadTestTwo(); // second function for testing multithreading


/*
  Testing program showing off the MessageBus.
  Every second a mesage saying "Hello!" will be printed to console by two listeners.
  Program will run forever because both threads are stuck in an infinite loop.
*/

int main(int argc, char **argv){
    std::thread testOne(threadTestOne);
    std::thread testTwo(threadTestTwo);
    
    testOne.join();
    testTwo.join();
    return 0;
}

void threadTestOne(){
    Engine::Listener listener(&bus);
    bus.addListener(&listener);
    
    for(;;){ // infinite loop to wait for messages
        // tell the thread to sleep for one second.
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void threadTestTwo(){
    Engine::Listener listener(&bus);
    Engine::Message msg("Henlo");
    bus.addListener(&listener);
    listener.send(msg);
    for(;;){ // infinite loop to wait for messages
        listener.send(msg); // will send a message every second
        // tell teh thread to sleep for 1 secondd
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
