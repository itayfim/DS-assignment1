#ifndef __COUNTRY_H
#define __COUNTRY_H

#include <iostream>
#include "List.h"

class List;

class Country
{
private:
	List* cities = nullptr;
	int size;

public:
	Country(int size);
	Country(const Country& other) = delete;
	~Country();
	int getSize() const { return size; } 
	List& getCity(int index) { return cities[index]; } 
	int getCityIndex(const List& toFind) const;
};

#endif