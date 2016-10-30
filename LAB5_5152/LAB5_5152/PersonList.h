#pragma once
#include "Person.h"
#include <vector>

class  PersonList
{
public:
	 PersonList();
	~ PersonList();
	void Add(Person* person);
	Person* Find(int index);
	int IndexOf(Person* person);
	void Remove(Person* person);
	void RemoveAt(int index);
	void Clear();
	int GetCount();

private:
	PersonListItem* _head;
	int _count;

};

 PersonList:: PersonList()
{
}

 PersonList::~ PersonList()
{
}