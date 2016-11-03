#pragma once
#include "Person.h"

class  PersonList
{
public:
	 PersonList();
	 PersonList(Person* person);
	~ PersonList();
	void Add(Person* person);
	Person* Find(int index);
	/*int IndexOf(Person* person);
	void Remove(Person* person);
	void RemoveAt(int index);
	void Clear();
	int GetCount();
	*/
private:
	struct PersonListItem
	{
		Person Person;
		PersonListItem* NextItem;
		PersonListItem* PrevItem;
	};
	PersonListItem* _head;
	int _count;
};

