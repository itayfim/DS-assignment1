#include "Country.h"
#include "City.h"
using namespace std;

Country::Country(int size)
{
	cities = new List[size];
	colors = new int[size];
	for (int i = 0; i < size; i++)
		colors[i] = WHITE;
	this->size = size;
}

Country::~Country()
{
	delete[]colors;
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

bool Country::onlyBlackCities(List& currCity) const
{
	bool res = true;
	const City* curr = currCity.getHead()->getNext();
	while (curr != nullptr)
	{
		if (colors[curr->getSerialNum() - 1] == WHITE)
			return false;
		curr = curr->getNext();
	}
	return res;
}

void Country::setWhites()
{
	for (int i = 0; i < size; i++)
		colors[i] = WHITE;
}
