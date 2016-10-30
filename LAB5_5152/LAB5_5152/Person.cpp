#include "Person.h"

Person::Person(std::string firstName = "", std::string lastName = "", int age = 0, Sex seX = Male) //On Create
{
	Name = firstName;
	Surname = lastName;
	Age = Age;
	sex = seX;
}

Person::Person(Person * person)
{
	Name = person->Name;
	Surname = person->Surname;
	Age = person->Age;
	sex = person->sex;
	
}

Person::Person() //From Keyboard
{
	std::cout << "\nEnter person first name:";
	std::cin.clear();
	std::cin >> Name;
	std::cout << "\nEnter person surname:";
	std::cin >> Surname;
	std::cout << "\nEnter person age:";
	std::cin >> Age;
	std::cout << "\nEnter person sex(Male,Female):";
	std::cin >> sex;
	std::cin.clear();
}