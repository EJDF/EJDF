#include <fstream>
#include "IOManager.h"
#include "Log.h"

// read file into given vector
void Engine::IOManager::readFile(std::string filename,
                                 std::vector<unsigned char> &buffer){

    std::ifstream file(filename, std::ios::binary);
    if(file.fail()) // make sure you can read the file
        Engine::Log::fatalError("Unable to open file " + filename);

    // get the filesize
    int fileSize;
    file.seekg(0, std::ios::end); // seek to the end of the file
    fileSize = file.tellg(); // get number of characters moved so far (entire file)
    file.seekg(0, std::ios::beg); // go back to the start of the file

    fileSize -= file.tellg(); // remove the fileheader from the filesize

    buffer.resize(fileSize); // resize to fileSize bytes
    file.read((char *)&buffer[0], fileSize); // read the file into buffer
    file.close();
}
