#include "person.h"

Person::Person()
{

}

Person::Person(QString last_name, QString first_name, QString patronymic)
    : last_name_(last_name), first_name_(first_name), patronymic_(patronymic)
{

}

Person::Person(QString full_name)
{
    QStringList words = full_name.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts); // разбиваем полученную строку на непустые слова

	if (words.size() != 2 && words.size() != 3) // в строке должно быть 2 или 3 слова (ФИ или ФИО)
	{
		throw "Error: String has incorrect format."; // исключение
	}

	last_name_ = words[0]; // используем 1-е слово в качестве фамилии
	first_name_ = words[1]; // 2-е в качестве имени

	if (words.size() == 3) // 3-е в качестве отчества (при наличии)
	{
		patronymic_ = words[2];
	}
}
