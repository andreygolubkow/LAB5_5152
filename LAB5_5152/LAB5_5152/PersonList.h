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
	int IndexOf(Person* person);
	void Remove(Person* person);
	void RemoveAt(int index);
	int GetCount();
	void Clear();
private:
	struct PersonListItem
	{
		Person Person;
		PersonListItem* NextItem;
		PersonListItem* PrevItem;
	};
	PersonListItem* _head;
	int _count;
	friend bool operator ==(Person &p1,Person &p2);
	friend bool operator !=(Person &p1, Person &p2);
};

