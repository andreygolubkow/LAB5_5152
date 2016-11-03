// LAB5_5152.cpp: определяет точку входа для консольного приложения.
//

#include "Person.h"
#include "PersonList.h"
#include <iostream>

int main()
{
	Person* p = new Person;
	p->Age = 10;
	p->Name = "First";
	p->sex = Male;
	p->Surname = "Person";
	PersonList list(p);
	p->Age = 10;
	p->Name = "Second";
	p->sex = Male;
	p->Surname = "Person";
	list.Add(p);
	p->Age = 10;
	p->Name = "Third";
	p->sex = Male;
	p->Surname = "Person";
	list.Add(p);
	if ((list.Find(0)->Name != "First")||(list.Find(1)->Name != "Second")|| (list.Find(2)->Name != "Third"))
	{
		std::cout << "TEST Find function eror.\n";
		std::cout << "\t" << list.Find(0)->Name << "\t" << list.Find(1)->Name << "\t" << list.Find(2)->Name;
	}
	

	
    return 0;
}

