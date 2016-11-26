#pragma once
#include "Person.h"

class  PersonList //Класс лист персон
{
public:
	 PersonList(); //Конструктор 
	 PersonList(Person* person); //конструктор
	~ PersonList();//Деструктор
	void Add(Person* person); //добавим персоны в лист
	Person* Find(int index); //Ищем в листе по индексу
	int IndexOf(Person* person); //Ищем по персоне
	void Remove(Person* person); //Удаляем
	void RemoveAt(int index); //Удаляем по индексу
	int GetCount(); //Получим кол-во персон
	void Clear(); //очистка листа
private:
	struct PersonListItem //Структура 
	{
		Person Person; //Персона
		PersonListItem* NextItem; //Следующая персона
		PersonListItem* PrevItem;// предыдущая персона 
	};
	PersonListItem* _head; //первая персона в листе
	int _count; //количество персон
	friend bool operator ==(Person &p1,Person &p2); //дружественные функции сравнения
	friend bool operator !=(Person &p1, Person &p2);
};

