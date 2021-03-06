// LAB5_5152.cpp: определяет точку входа для консольного приложения.
//

#include "Person.h"
#include "PersonList.h"
#include <iostream>
#include <cstdlib>
void Test()
{
	Person* p = new Person; //Создали персону
	p->Age = 10;
	p->Name = "First";
	p->sex = Male;
	p->Surname = "Person";
	PersonList list(p); //Добавили персону в лист
	p->Age = 10;
	p->Name = "Second";
	p->sex = Male;
	p->Surname = "Person";
	list.Add(p); //Добавили еще персону
	p->Age = 10;
	p->Name = "Third";
	p->sex = Male;
	p->Surname = "Person";
	list.Add(p);//проверяем работу фунций 
	if ((list.Find(0)->Name != "First") || (list.Find(1)->Name != "Second") || (list.Find(2)->Name != "Third"))
	{
		std::cout << "TEST Find function eror.\n";
		std::cout << "\t" << list.Find(0)->Name << "\t" << list.Find(1)->Name << "\t" << list.Find(2)->Name;
	}
	if ((list.IndexOf(list.Find(0)) != 0) || (list.IndexOf(list.Find(2)) != 2))
	{
		std::cout << "TEST IndexOf function eror.\n";
		std::cout << "\t" << list.IndexOf(list.Find(0)) << "\t" << list.IndexOf(list.Find(2));
	}
	list.Remove(list.Find(2));
	if ((list.Find(0)->Name != "First") || (list.Find(1)->Name != "Second"))
	{
		std::cout << "TEST Remove function eror.\n";
		std::cout << "\t" << list.Find(0)->Name << "\t" << list.Find(1)->Name;
	}
	list.Remove(list.Find(0));
	if ((list.Find(0)->Name != "Second"))
	{
		std::cout << "TEST Remove function eror.\n";
		std::cout << "\t" << list.Find(0)->Name << "\t";
	}
	list.Add(p);
	p->Age = 10;
	p->Name = "Fourth";
	p->sex = Male;
	p->Surname = "Person";
	list.Add(p);
	list.Remove(list.Find(1));//проверяем поиск
	if ((list.Find(0)->Name != "Second") || (list.Find(1)->Name != "Fourth"))
	{
		std::cout << "TEST Remove function eror.\n";
		std::cout << "\t" << list.Find(0)->Name << "\t" << list.Find(1)->Name;
	}
	delete p;
}

int main()
{
	Test();
	Person personA("testA", "personA", 18, Male);
	Person personB("testB", "personB", 18, Male);
	Person personC("testC", "personC", 18, Female);
	PersonList listA(&personA);
	PersonList listB(&personA);
	listA.Add(&personB);
	listA.Add(&personC);
	listB.Add(&personB);
	listB.Add(&personC);
	std::cout << "\t LIST A \n";
	for (int i = 0; i < listA.GetCount() ; i++)
		std::cout << "\n" << *listA.Find(i) << std::endl;
	std::cout << "\t LIST B \n";
	for (int i = 0; i < listB.GetCount() ; i++)
		std::cout << "\n" << *listB.Find(i) << std::endl;
	system("pause");
	Person personD("testD", "personD", 20, Male);
	listA.Add(&personD);
	listB.Add(listA.Find(1));
	for (int i = 0; i < listA.GetCount(); i++)
		std::cout << "\n" << *listA.Find(i) << std::endl;
	std::cout << "\t LIST B \n";
	for (int i = 0; i < listB.GetCount(); i++)
		std::cout << "\n" << *listB.Find(i) << std::endl;
	system("pause");
	listA.RemoveAt(1);
	for (int i = 0; i < listA.GetCount(); i++)
		std::cout << "\n" << *listA.Find(i) << std::endl;
	std::cout << "\t LIST B \n";
	for (int i = 0; i < listB.GetCount(); i++)
		std::cout << "\n" << *listB.Find(i) << std::endl;
	system("pause");
	listB.Clear();
	std::cout << "Enter person A[Name Surname Age Sex] :";
	std::cin >> personA;
    return 0;
}

