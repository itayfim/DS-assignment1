#ifndef __COUNTRY_H
#define __COUNTRY_H

#include <iostream>
#include "List.h"
#define WHITE 0
#define BLACK 1

class List;

class Country
{
private:
	List* cities = nullptr;
	int* colors = nullptr;
	int size;

public:
	Country(int size);
	Country(const Country& other) = delete;
	~Country();
	int getSize() const { return size; } 
	List& getCity(int index) { return cities[index]; } 
	int getCityIndex(const List& toFind) const;
	int* getColors() const { return colors; }
	const int getColor(int i) const { return colors[i]; }
	void setBlack(int i) { colors[i] = BLACK; }
	bool onlyBlackCities(List& currCity) const;
	void setWhites();
};

#endif