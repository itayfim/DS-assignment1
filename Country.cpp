#include "Country.h"
using namespace std;

Country::Country(int size)
{
	cities = new List[size];
	this->size = size;
}

Country::~Country()
{
	delete[]cities;
}

int Country::getCityIndex(const List& toFind) const
{
	for (int i = 0; i < size; i++)
	{
		if (&(cities[i]) == &toFind)
			return i;
	}
	return -1; // in case that didnt find
}