#include "PersonList.h"



PersonList::PersonList()
{
	_head = new PersonListItem();
	_head->Person.ReadPerson();
	_head->NextItem = nullptr;
	_head->PrevItem = nullptr;
	_count = 1;
}

PersonList::~PersonList()
{

}

void PersonList::Add(Person * person)
{
	PersonListItem* personListItem = new PersonListItem;
	personListItem->Person = person;
	personListItem->NextItem = nullptr;

	PersonListItem* currentItem = _head;
	for (int i = 1; i < _count; i++)
	{

		currentItem = currentItem->NextItem;
	}
	currentItem->NextItem = personListItem;
	personListItem->PrevItem = currentItem;
	_count++;
}

Person* PersonList::Find(int index)
{
	if (index > _count || index<1)
	{
		return &_head->Person;
	}
	else
	{
		PersonListItem* currentItem;
		currentItem = _head;
		for (int i = 1; i < index; i++)
		{
			currentItem = currentItem->NextItem;
		}
		return &currentItem->Person;
	}
}
