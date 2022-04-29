#ifndef FILEABOUT_H
#define FILEABOUT_H

#include <cstddef>
struct FileAbout { // структура, содержащая характеристики о файле
    bool operator!= (const FileAbout& other) // вспомогательный оператор для проверки, изменился ли файл
    {
        if(this == &other) return false;
        return exists != other.exists || size != other.size;
    }
    bool exists; // переменная, показывающая, существует ли файл
    size_t size; // количество символов в файле
};

#endif
