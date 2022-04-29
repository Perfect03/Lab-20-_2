#include <QCoreApplication>
#include <iostream>
#include <thread>
#include "ConsoleFileObserver.h"
#include "fileAbout.h"
#include "FileMonitor.h"
#include "FileObserver.h"
#include "observable.h"

int main() {
    setlocale(LC_ALL, "Russian");
    FileMonitor monitor( "C:/Users/User/Documents/Lab-20-_2/build-GT_1-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/file.txt" );
    ConsoleFileObserver observer;
    monitor.registerObserver( &observer );
 
    //monitor.checkFile(); // для 1-й ситуации из условия задания - она возможна только в самом начале наблюдения.

    // остальные ситуации подразумевают собой изменения файла, за которыми "наблюдатель" и должен наблюдать.
    // Для них можно создать бесконечный цикл:

    while( true ) {
        monitor.checkFile();
        std::this_thread::sleep_for( std::chrono::milliseconds( 5000 ) );
    }
 // программу можно построить по другому - выводить информацию только при изменениях в файле (так должно быть по логике наблюдателя)
 //, а не через каждый промежуток времени. Но тогда 1-я ситуация из условия лабораторной была бы неосуществима (она не подразумевает
 // изменения), поэтому я построил программу согласно условию.
    return 0;
}
