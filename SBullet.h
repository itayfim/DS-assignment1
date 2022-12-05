#ifndef __SBULLET_H
#define __SBULLET_H
#include "List.h"
#include "City.h"
#include <iostream>

class City;
class List;

class SBullet
{
private:
	SBullet* next = nullptr;
	List* currList;
	City* currCity;
	int d;
	int line;

public:
	SBullet() = default;
	SBullet(const SBullet& other) { next = other.next; currList = other.currList; currCity = other.currCity; d = other.d; line = other.line; }
	~SBullet() = default;
	List* getCurrList() const { return currList; }
	City* getCurrCity() const { return currCity; }
	SBullet* getNext() const { return next; }
	int getD() const { return d; }
	int getLine() const { return line; }
	void setLine(int line) { this->line = line; }
	void setD(int d) { this->d = d; }
	void setCurrList(List* lst) { currList = lst; }
	void setCurrCity(City* city) { currCity = city; }
	void setNext(SBullet* next) { this->next = next; }
};

#endif