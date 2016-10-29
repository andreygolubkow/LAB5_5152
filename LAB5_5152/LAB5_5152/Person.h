#pragma once
#include "Sex.h"
#include <string>

class  Person
{
public:
	std::string Name;
	std::string Surname;
	int Age;
	Sex sex;
	Person(std::string firstName = "", std::string lastName = "", int age = 0, Sex seX = Male); //On Create
	Person(); //From Keyboard

private:

};
