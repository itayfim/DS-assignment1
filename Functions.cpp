#include "mainHeader.h"

using namespace std;

void getRoads(Country& country, int numOfRoads, int numOfCities)
{
	int first, second;
	cout << "Please enter " << numOfRoads << " roads" << endl;
	for (int i = 0; i < numOfRoads; i++)
	{
		cin >> first >> second;
		City* new1 = new City(second);
		country.getCity(first - 1).insertCity(new1);
		City* new2 = new City(first);
		country.getCity(second - 1).insertCity(new2);
	}
}

void setWhites(int* colors, int size)
{
	for (int i = 0; i < size; i++)
		colors[i] = WHITE;
}

void getDestAndStart(int& detination, int& startingPoint, int numOfCities)
{
	bool goodInput;
	do
	{
		goodInput = true;
		cout << "Please enter starting point and destination" << endl;
		cin >> startingPoint >> detination;
		if (startingPoint > numOfCities || startingPoint < 1
			|| detination > numOfCities || detination < 1)
		{
			goodInput = false;
			cout << "Please insert numbers between 1 to " << numOfCities << endl;
		}

	} while (!goodInput);
}

int TownDistanceRec(Country& country, List& currCity, List& destCity, int* colors)
{
	colors[country.getCityIndex(currCity)] = BLACK;
	if (&currCity == &destCity)
		return 0;
	else 
	{
		if (onlyBlackCities(currCity, colors))
			return INVALID;
		else
		{
			int d = INVALID;
			City* curr = currCity.getHead()->getNext();
			while (curr != nullptr)
			{
				if (colors[curr->getSerialNum() - 1] == WHITE)
				{
					d = TownDistanceRec(country, country.getCity(curr->getSerialNum() - 1), destCity, colors);
					if (d != INVALID)
						return d + 1;
				}
				curr = curr->getNext();
			}
			return INVALID;
		}
	}
}

bool onlyBlackCities(List& currCity, int* colors)
{
	bool res = true;
	City* curr = currCity.getHead()->getNext();
	while (curr != nullptr)
	{
		if (colors[curr->getSerialNum() - 1] == WHITE)
			return false;
		curr = curr->getNext();
	}
	return res;
}