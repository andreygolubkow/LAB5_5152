#include "PersonList.h"



PersonList::PersonList()
{
	_head = new PersonListItem();
	_head->Person.ReadPerson();
	_head->NextItem = nullptr;
	_head->PrevItem = nullptr;
	_count = 1;
}

PersonList::PersonList(Person* person)
{
	_head = new PersonListItem();
	_head->Person = person;
	_head->NextItem = nullptr;
	_head->PrevItem = nullptr;
	_count = 1;
}

PersonList::~PersonList()
{
/*	for (int i = _count; i > -1; i--)
	{
		Remove(Find(i));
	}*/
}

void PersonList::Add(Person * person)
{
	if (_count > 0)
	{
		PersonListItem* personListItem = new PersonListItem;
		personListItem->Person = new Person(person);
		personListItem->NextItem = nullptr;
		PersonListItem* currentItem = _head;
		for (int i = 1; i < _count; i++)
		{

			currentItem = currentItem->NextItem;
		}
		currentItem->NextItem = personListItem;
		personListItem->PrevItem = currentItem;
		_count++;
	} else
	if (_count == 0)
	{
		PersonListItem* personListItem = new PersonListItem;
		personListItem->Person = new Person(person);
		personListItem->NextItem = nullptr;
		personListItem->PrevItem = nullptr;
		_head = personListItem;
		_count = 1;
	}

}

Person* PersonList::Find(int index)
{
	if (index > _count || index < 0)
	{
		return nullptr;
	}
	else
	{
		if (index > _count || index < 1)
		{

			return &_head->Person;
		}
		else
		{
			PersonListItem* currentItem;
			currentItem = _head;
			for (int i = 1; i <= index; i++)
			{

				currentItem = currentItem->NextItem;
			}
			return &currentItem->Person;
		}
	}
}

int PersonList::IndexOf(Person * person)
{
	int i = 0;
	int result = -1;
	for (i = 0; (i < _count); i++)
	{
		if ((*Find(i) == *person))
		{
			result = i;
		}
	}
	
	return result;
}

void PersonList::Remove(Person * person)
{
	int index = IndexOf(person);
	if (index == 0)
	{
		if (_head != nullptr)
		{
			PersonListItem * pTmpPointer = _head;
			_head = _head->NextItem;
			_head->PrevItem = nullptr;
			delete pTmpPointer;
			_count--;
		}
	} else
	if (index == _count-1)
	{
		PersonListItem* currentItem = _head;
		for (int i = 1; i <= _count-1; i++)
		{
			currentItem = currentItem->NextItem;
		}
		PersonListItem* currentTmpItem = currentItem;
		currentItem = currentItem->PrevItem;
		currentItem->NextItem = nullptr;
		delete currentTmpItem;
		_count--;
	}
	else
	if (index >0)
	{
		PersonListItem* currentItem = _head;
		for (int i = 1; i <=index; i++)
		{
			currentItem = currentItem->NextItem;
		}
		PersonListItem* currentTmpItem = currentItem;
		currentItem->NextItem->PrevItem = currentItem->PrevItem;
		currentItem->PrevItem->NextItem = currentItem->NextItem;
		delete currentTmpItem;
		_count--;
	}
}

void PersonList::RemoveAt(int index)
{
	Remove(Find(index));
}

int PersonList::GetCount()
{
	return _count;
}

void PersonList::Clear()
{
	for (int i = _count - 1; i > 0; i--)
		RemoveAt(i);
	_head->NextItem = nullptr;
	delete _head;
	_head = nullptr;
	_count = 0;
}

bool operator==(Person & p1, Person & p2)
{
	
	if ((&p1!=nullptr && &p2 != nullptr)&&(p1.Age == p2.Age) && (p1.Name == p2.Name) && (p1.sex == p2.sex) && (p1.Surname == p2.Surname))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(Person & p1, Person & p2)
{
	return !(p1 == p2);
}
