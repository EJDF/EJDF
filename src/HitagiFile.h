#pragma once
#include <vector>
#include <iostream>
#include <string>

namespace Engine{
    class HitagiFile{
        
        // the container of the file
        std::vector<unsigned char> file;

    public:
        HitagiFile(std::string filename);
        void printFile(){ for(char c : file) std::cout << c; }
    };
}
