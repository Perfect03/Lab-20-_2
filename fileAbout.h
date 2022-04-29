#ifndef FILEABOUT_H
#define FILEABOUT_H

#include <cstddef>
class FileAbout {
    bool operator!= (const FileAbout& other) 
    {
        if(this == &other) return false;
        return exists != other.exists || size != other.size;
    }
 
    bool exists;
    size_t size;
};

#endif
