// LAB5_5152.cpp: определяет точку входа для консольного приложения.
//

#include "Person.h"
#include "PersonList.h"
#include <iostream>

int main()
{
	Person* p = new Person;
	p->ReadPerson();
	PersonList list;
	list.Add(p);
	p->ReadPerson();
	list.Add(p);
	//list.Add(&a);
	std::cout << list.Find(0)->Name<< list.Find(1)->Name << list.Find(2)->Name;
	
	
    return 0;
}

