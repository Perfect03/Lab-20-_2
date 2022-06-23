#include <QCoreApplication>
#include <iostream>
#include <thread>
#include "ConsoleFileObserver.h"
#include "fileAbout.h"
#include "FileMonitor.h"
#include "FileObserver.h"
#include "observable.h"
#include <QFile>
#include <QString>

int main() {
    QString path = PRJ_PATH; // путь к папке с проектом
    QString file1 = path + "/Input/file1.txt"; // ПУТЬ К ФАЙЛАМ
    QString file2 = path + "/Input/file2.txt";
    FileMonitor monitor1( file1.toStdString().c_str() ); // нужно преобразовать путь QString -> const char*, т.к.
    FileMonitor monitor2( file2.toStdString().c_str() ); // изначально путь PRJ_PATH был в формате QString


    //можно прописывать путь так, если пользователь хочет наблюдать файл не в папке с проектом:
    //FileMonitor monitor1( "C:/Folder1/Folder2/file1.txt" );
    //FileMonitor monitor2( "C:/Folder1/Folder2/file2.txt" );

    ConsoleFileObserver observer; // создаём самого наблюдателя
    monitor1.registerObserver( &observer ); // связываем файловые переменные с наблюдателем
    monitor2.registerObserver( &observer );

    while( true ) {
        monitor1.checkFile();
        monitor2.checkFile();
        std::this_thread::sleep_for( std::chrono::milliseconds( 5000 ) );
    }
 // программу можно построить по другому - выводить информацию только при изменениях в файле (так должно быть по логике наблюдателя)
 //, а не через каждый промежуток времени. Но тогда 1-я ситуация из условия лабораторной была бы неосуществима (она не подразумевает
 // изменения), поэтому я построил программу согласно условию. Результат "наблюдений" выводится каждые 5с, и если файл не изменён -
  // - то это 1-я ситуация из условия.
    return 0;
}
