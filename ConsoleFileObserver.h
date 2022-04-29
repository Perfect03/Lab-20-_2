#ifndef CONSOLEFILEOBSERVER_H
#define CONSOLEFILEOBSERVER_H

#include "FileObserver.h"
#include <iostream>

class ConsoleFileObserver : public FileObserver {
public:
    ~ConsoleFileObserver();

    void onFileChanged(const FileAbout& state);
    void fileStatus(const FileAbout& state);
};

void ConsoleFileObserver::onFileChanged(const FileAbout& state) { // ф-я для 2-3 ситуаций, когда файл изменен
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "FILE WAS CHANGED" << std::endl;
    std::cout << "Exists: " << ((state.exists==1)?"Yes":"No") << std::endl;
    std::cout << "Size: " << state.size << std::endl;
    std::cout << std::endl << std::endl;
}

void ConsoleFileObserver::fileStatus(const FileAbout& state) { // ф-я для 1-й ситуации, когда файл не изменялся
    std::cout << std::endl << std::endl << std::endl;
    if(state.size !=0 && state.exists ==1) {
    std::cout << "File exists and not empty. " << std::endl ;
    std::cout << "Size: " << state.size << std::endl;
    std::cout << std::endl << std::endl;
    }
    else if (state.exists==0) std::cout << "File does not exists. ";
    else std::cout << "File is empty";
}

ConsoleFileObserver::~ConsoleFileObserver() {
}

#endif
