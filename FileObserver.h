#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "fileAbout.h"
class FileObserver { // класс-интерфейс для нашего наблюдателя
public:
    virtual ~FileObserver() { } // деструктор традиционно виртуальный, т.к. он наследуется

     //виртуальные функции-обработчики, которые пока что ничего не делают, а позже будут конкретизироваться:
    virtual void onFileChanged(const FileAbout& state) = 0;
    virtual void fileStatus(const FileAbout& state) = 0;
};

#endif
