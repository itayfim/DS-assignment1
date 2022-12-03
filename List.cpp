#include "List.h"
#include "City.h"
using namespace std;
#define INVALID -1

List::List() // with dummy head
{
	City* dummyhead = new City(INVALID);
	head = dummyhead;
	tail = dummyhead;
}

List::~List()
{
	City* curr = this->head;
	City* temp;
	while (curr != nullptr)
	{
		temp = curr->getNext();
		delete curr;
		curr = temp;
	}
}

void List::insertCity(City* toInsert) // in a sorted manner
{
	bool founded = false;
	if (this->isEmpty() || toInsert->getSerialNum() > tail->getSerialNum()) // first City in the list
		addNodeToTail(toInsert);
	else
	{
		City* curr = head;
		while (curr != nullptr && !founded)
		{
			if (toInsert->getSerialNum() > curr->getSerialNum()
				&& toInsert->getSerialNum() < curr->getNext()->getSerialNum()) // curr->getNext != nullptr anyway
			{
				toInsert->setNext(curr->getNext());
				curr->setNext(toInsert);
				founded = true;
			}
			curr = curr->getNext();
		}
	}
}

void List::addNodeToTail(City* toInsert)
{
	tail->setNext(toInsert);
	tail = toInsert;
}

bool List::isEmpty() const
{
	return (head == tail);
}