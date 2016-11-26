#pragma once
#include "Sex.h"
#include <string>

class  Person //Создали класс персоны
{
public:
	std::string Name;
	std::string Surname;
	int Age;
	Sex sex;
	Person(std::string firstName = "", std::string lastName = "", int age = 0, Sex seX = Male); //Конструктор для класса
	Person(Person* person);//Еще конструктор
	void ReadPerson();//Функция чтения персоны с клавы
	void FillRandomPerson();//функция создание рандомной персоны
private:

};

std::istream& operator >> (std::istream& is, Person& person); //Переопределение операторов >> и <<
std::ostream& operator <<(std::ostream & os, Person const & person);