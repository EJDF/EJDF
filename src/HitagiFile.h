#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stdint.h>

namespace Engine{
    /*
      HitagiFile
      This class handles the loading of the scene files.

      Specifically, it does not handle the parsing, it simply 
      contains the raw data and some helper functions to process
      the data inside of the class.

      Hitagi files start with a 6-byte header: 48 69 74 67 61 69 (Hitagi)
      

     */
    class HitagiFile{
        
        // the container of the file
        std::vector<unsigned char> file;
        // file signature
        uint32_t signature;

    public:
        HitagiFile(std::string filename);
        void printFile(){ for(char c : file) std::cout << c; }
    };
}
