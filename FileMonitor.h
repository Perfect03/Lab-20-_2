#include "FileObserver.h"
#include "fileAbout.h"
#include "observable.h"

#include <iostream>
#include <chrono>
#include <thread>

#include <sys/stat.h>

class FileMonitor : public Observable<FileObserver> { // класс, посылающий наблюдателям сигнал об изменениях с файлами
public:
    FileMonitor(const char* fileName);

    void checkFile();

private:
    static FileAbout getFileAbout(const std::string& fileName);

private:
    std::string m_fileName;
    FileAbout m_prevFileAbout;
};

FileMonitor::FileMonitor(const char* fileName) : // в конструкторе инициализируется переменная как текущего, так и предыдущего файла для их сравнения
    m_fileName(fileName), m_prevFileAbout(getFileAbout(m_fileName)) {
}

void FileMonitor::checkFile() { // проверка изменений в файлах
    FileAbout fileAbout = getFileAbout(m_fileName);
    if(fileAbout != m_prevFileAbout) { // если файлы изменились, то вызывается функция onFileChanged
           notifyObservers(&FileObserver::onFileChanged, fileAbout);
           m_prevFileAbout = fileAbout; // и перезаписывается переменная предыдущего файла
       }
    else{ // если файлы изменились, то вызывается функция fileStatus, которая просто выводит информацию о файле
        notifyObservers(&FileObserver::fileStatus, fileAbout); // в обоих случаях посылается сигнал наблюдателям. В этом и состоит задача данного класса
        //m_prevFileAbout = fileAbout;
    }
}

FileAbout FileMonitor::getFileAbout(const std::string& fileName) {
    FileAbout fileAbout;
    struct stat statBuf;
    fileAbout.exists = stat(fileName.c_str(), &statBuf) == 0; // здесь мы узнаём непосредственно о состоянии файла, используя библиотеку stat
    fileAbout.size = fileAbout.exists ? statBuf.st_size : 0;
    return fileAbout;
}
