#include <iostream>
#include <string>
/*
  Console logging functions for various levels of importance
*/
namespace Engine{
    namespace Log{
        void message(std::string msg); // information
        void note(std::string msg); // semi-important information
        void warning(std::string msg); // important information
        void error(std::string msg); // error
        void fatalError(std::string msg); // error and close the program
    }
}
