#ifndef __LIST_H
#define __LIST_H

#include <iostream>
class City;

class List
{
private:
	City* head;
	City* tail;

public:
	List(); // with dummy head
	List(const List& other) = delete;
	~List();
	void insertCity(City* toInsert); // in a sorted manner
	bool isEmpty() const;
	void addNodeToTail(City* toInsert);
	const City* getHead() const { return head; }
};

#endif