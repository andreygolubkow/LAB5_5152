#include "Person.h"

Person::Person(std::string firstName, std::string lastName, int age, Sex seX) //On Create
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


void Person::ReadPerson()
{
	std::cout << "\nEnter person name:";
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

std::istream & operator >> (std::istream & is, Person & person)
{
	is >> person.Name>>person.Surname>>person.Age>>person.sex;
	return is;
}
