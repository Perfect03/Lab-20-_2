#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "fileAbout.h"
class FileObserver {
public:
    virtual ~FileObserver() { }
 
    virtual void onFileChanged(const FileAbout& state) = 0;
    virtual void fileStatus(const FileAbout& state) = 0;
};

#endif
