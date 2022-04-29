#include "FileObserver.h"
#include "fileAbout.h"
#include "observable.h"

#include <iostream>
#include <chrono>
#include <thread>
 
#include <sys/stat.h>
 
class FileMonitor : public Observable<FileObserver> {
public:
    FileMonitor(const char* fileName);
 
    void checkFile();
 
private:
    static FileAbout getFileAbout(const std::string& fileName);
 
private:
    std::string m_fileName;
    FileAbout m_prevFileAbout;
};
 
FileMonitor::FileMonitor(const char* fileName) :
    m_fileName(fileName), m_prevFileAbout(getFileAbout(m_fileName)) {
}
 
void FileMonitor::checkFile() {
    FileAbout fileAbout = getFileAbout(m_fileName);
    if(fileAbout != m_prevFileAbout) {
           notifyObservers(&FileObserver::onFileChanged, fileAbout);
           m_prevFileAbout = fileAbout;
       }
    else{
        notifyObservers(&FileObserver::fileStatus, fileAbout);
        //m_prevFileAbout = fileAbout;
    }
}
 
FileAbout FileMonitor::getFileAbout(const std::string& fileName) {
    FileAbout fileAbout;
    struct stat statBuf;
    fileAbout.exists = stat(fileName.c_str(), &statBuf) == 0;
    fileAbout.size = fileAbout.exists ? statBuf.st_size : 0;
    return fileAbout;
}
