#pragma once
#include <vector>
#include <iostream>
#include <string>

namespace Engine{
    /*
      HitagiFile
      This class handles the loading of the scene files.
      Specifically, it does not handle the parsing, it simply 
      contains the raw data and some helper functions to process
      the data inside of the class.

      HitagiFiles exist as a blob file containing all the scripts
      and bitmaps of the game. It starts with a header that simply
      reads hitagi-engine followed by 0x0A indicating a newline.
      From there headers with the name of the file followed by
      <-EOF-> separate the files.
     */
    class HitagiFile{
        
        // the container of the file
        std::vector<unsigned char> file;

    public:
        HitagiFile(std::string filename);
        void printFile(){ for(char c : file) std::cout << c; }
    };
}
