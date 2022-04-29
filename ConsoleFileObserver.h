#ifndef CONSOLEFILEOBSERVER_H
#define CONSOLEFILEOBSERVER_H

#include "FileObserver.h"
#include <iostream>

//конкретный наблюдатель (наследник класса FileObserver), который выводит информацию в консоль. Можно создать и других наследников,
// выводящих информацию другими способами
class ConsoleFileObserver : public FileObserver {
public:
    ~ConsoleFileObserver();

    void onFileChanged(const FileAbout& state);  // функции уже чуточку конкретизировались. Аргументом являются конкретные данные о файле
    void fileStatus(const FileAbout& state);
};

void ConsoleFileObserver::onFileChanged(const FileAbout& state) { // эта функция нужна для 2-3 ситуаций из условия задания, когда файл изменен
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "FILE WAS CHANGED" << std::endl;
    std::cout << "Exists: " << ((state.exists==1)?"Yes":"No") << std::endl;
    std::cout << "Size: " << state.size << std::endl; // выводится информация о файле и уведомление, что файл изменён
    std::cout << std::endl << std::endl;
}

void ConsoleFileObserver::fileStatus(const FileAbout& state) { // функция для 1-й ситуации, когда файл не изменялся
    std::cout << std::endl << std::endl << std::endl;
    if(state.size !=0 && state.exists ==1) {
    std::cout << "File exists and not empty. " << std::endl ;
    std::cout << "Size: " << state.size << std::endl; // выводится информация о файле и надпись, что он существует и не пуст (согласно условию)
    std::cout << std::endl << std::endl;
    }
    else if (state.exists==0) std::cout << "File does not exists. ";
    else std::cout << "File is empty";
}

ConsoleFileObserver::~ConsoleFileObserver() {
}

#endif
