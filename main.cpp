#include <QCoreApplication>
#include <iostream>
#include "stack.h"
#include "person_keeper.h"
#include "person.h"

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

   setlocale(LC_ALL, "Russian");

    Stack<const char *> t;
    t.Push("+");
    t.Push("+");
    t.Push("B");
    cout << "Size of stack before node removal: " << t.Size() << endl;
    t.Pop();
    cout << "Size of stack after node removal: " << t.Size() << endl;
    t.Push("C");


    cout << "Elements of stack: " << endl;
    while (true)
    {
        cout << t.Pop() << endl;
    }

    Stack<int> z;
    z.Push(2);
    while (true)
    {
        cout << z.Pop() << endl;
    }

    // ПРОВЕРКА ИСКЛЮЧЕНИЯ

    Stack<int> w;
    w.Pop(); // пробуем извлечь элемент из пустого стека - получаем исключение

    //2-я часть
    // все примеры нужно проверять по отдельности ввиду особенностей Singleton-класса.
    auto& b = PersonKeeper::Instance();
    b.ReadPersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/persons/1.txt");
    cout << endl << "Count of names: " << b.Size() << endl;
    b.WritePersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/for_write/1.txt");

    auto& c = PersonKeeper::Instance();
    c.ReadPersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/persons/2.txt");
    c.WritePersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/for_write/2.txt");

    auto& e = PersonKeeper::Instance(); // пример, когда строка с ФИО содержит 2 слова
    e.ReadPersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/persons/4.txt");
    e.WritePersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/for_write/4.txt");

    auto& d = PersonKeeper::Instance(); // пример, когда строка с ФИО содержит 1 слово
    d.ReadPersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/persons/3.txt");
    d.WritePersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/for_write/3.txt");

    auto& f = PersonKeeper::Instance(); // пример, когда строка с ФИО содержит 4 слова
    f.ReadPersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/persons/5.txt");
    f.WritePersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/for_write/5.txt");

    auto& g = PersonKeeper::Instance(); // пример с пустой строкой между именами
    g.ReadPersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/persons/6.txt");
    g.WritePersons("C:/Users/User/Documents/GT_1/build-GT_1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug/for_write/6.txt");
}
