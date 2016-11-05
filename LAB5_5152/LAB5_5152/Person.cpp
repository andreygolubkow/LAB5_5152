#include "Person.h"

Person::Person(std::string firstName, std::string lastName, int age, Sex seX) //On Create
{
	Name = firstName;
	Surname = lastName;
	Age = age;
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

void Person::FillRandomPerson()
{
	srand(1512);
	int nameRnd = 1 + rand() % 4;
	switch (nameRnd)
	{
	case (1):
		Name = "Artur";
		break;
	case (2):
		Name = "Ivan";
		break;
	case (3):
		Name = "Petr";
		break;
	default:
		Name = "Artur";
		break;
	}

	int surnameRnd = 1 + rand() % 4;
	switch (surnameRnd)
	{
	case (1):
		Surname = "Ivanov";
		break;
	case (2):
		Surname = "Sidorov";
		break;
	case (3):
		Surname = "Mihalkov";
		break;
	default:
		Surname = "Ivanov";
		break;
	}

	Age = 10 + rand() % 31;

	int SexRnd = 1 + rand() % 3;
	switch (SexRnd)
	{
	case(1):
		sex = Male;
		break;
	case(2):
		sex = Female;
		break;
	default:
		sex = Male;
		break;
	}
}

std::istream & operator >> (std::istream & is, Person & person)
{
	std::string ageStr = "";
	is >> person.Name >> person.Surname;
	
	person.Age = -1;
	while (person.Age < 0)
	{
		bool flag = false;
		while (flag == false)
		{
			is >> ageStr;
			flag = true;
			for (int i = 0; i < ageStr.length() ; i++)
			{
				if (ageStr.c_str()[i] < 48 || ageStr.c_str()[i]>57)
				{
					flag = false;
					break;
				}
			}
			if (flag == false)
			{
				std::cout << "Invalid Age, try again: ";
			}
		}
		person.Age = atoi(ageStr.c_str());
		if (person.Age < 0)
		{
			std::cout << "Invalid Person Age, try again:";
		}
	}
	return is;
}

std::ostream & operator<<(std::ostream & os, Person const & person)
{
	os << "Name: "<<person.Name <<" Surname: "<< person.Surname <<" Age: "<< person.Age <<" Sex: "<< person.sex;
	return os;
}
