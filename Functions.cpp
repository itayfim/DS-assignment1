#include "mainHeader.h"
#include "Stack.h"

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
	removeDuplicates(country);
}

void removeDuplicates(Country& country)
{
	int size = country.getSize();
	City* curr = nullptr, * temp = nullptr;
	for (int i = 0; i < size; i++)
	{
		curr = country.getCity(i).getHead()->getNext();
		while (curr->getNext() != nullptr)
		{
			if (curr->getSerialNum() == curr->getNext()->getSerialNum())
			{
				temp = curr->getNext();
				curr->setNext(curr->getNext()->getNext());
				delete temp;
			}
			curr = curr->getNext();
		}
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

int TownDistance(Country& country, List& currCity, List& destCity, int* colors)
{
	Stack S;
	SBullet curr;
	int returnFromRec = 0, dist = INVALID;
	setFieldForCurr(curr, &currCity, currCity.getHead()->getNext(), INVALID, START);
	do {
		if (returnFromRec)
			curr = S.Pop();
		if (curr.getLine() == AFTER)
		{
			returnFromRec = 1;
			if (dist != INVALID)
			{
				curr.setD(dist);
				dist = curr.getD() + 1;
			}
			else
			{
				curr.setCurrCity(curr.getCurrCity()->getNext());
				if (curr.getCurrCity() != nullptr)
				{
					curr.setLine(START);
					returnFromRec = 0;
				}
			}
		}
		if (curr.getLine() == START)
		{
			country.setBlack(country.getCityIndex(*curr.getCurrList()));
			if (curr.getCurrList() == &destCity)
			{
				returnFromRec = 1;
				dist = 0;
			}
			else
			{
				if (country.onlyBlackCities(*curr.getCurrList()))
				{
					returnFromRec = 1;
					dist = INVALID;
				}
				else
				{
					dist = INVALID;
					if (curr.getCurrCity() != nullptr)
					{
						if (country.getColor(curr.getCurrCity()->getSerialNum() - 1) == WHITE)
						{
							curr.setD(dist);
							curr.setLine(AFTER);
							S.Push(curr);
							curr.setCurrList(&(country.getCity(curr.getCurrCity()->getSerialNum() - 1)));
							curr.setCurrCity(curr.getCurrList()->getHead()->getNext());
							curr.setLine(START);
							returnFromRec = 0;
						}
						else
							curr.setCurrCity(curr.getCurrCity()->getNext());
					}
				}
			}
		}
	} while (!S.isEmpty());
	return dist;
}


void setFieldForCurr(SBullet& curr, List* currList, City* currCity, int d, int line)
{
	curr.setCurrList(currList);
	curr.setCurrCity(currCity);
	curr.setD(d);
	curr.setLine(line);
}

int TownDistanceRec(Country& country, List& currCity, List& destCity, int* colors)
{
	country.setBlack(country.getCityIndex(currCity));
	if (&currCity == &destCity)
		return 0;
	else 
	{
		if (country.onlyBlackCities(currCity))
			return INVALID;
		else
		{
			int d = INVALID;
			City* curr = currCity.getHead()->getNext();
			while (curr != nullptr)
			{
				if(country.getColor(curr->getSerialNum() - 1) == WHITE)
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

