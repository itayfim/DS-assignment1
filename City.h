#ifndef __CITY_H
#define __CITY_H

#include <iostream>

class City // as ListNode
{
private:
	int serialNum;
	City* next;

public:
	City() = delete;
	City(int serialNum);
	City(const City& other) = delete;
	~City() = default;
	City* getNext() const { return next; }
	int getSerialNum() const { return serialNum; }
	void setNext(City* next) { this->next = next; }

};

#endif