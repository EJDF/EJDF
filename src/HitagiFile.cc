#include "HitagiFile.h"
#include "IOManager.h"

Engine::HitagiFile::HitagiFile(std::string filename){
    Engine::IOManager::readFile(filename, this->file);
    this->printFile();
}
