#include "mainHeader.h"

using namespace std;

void main()
{
	int numOfCities, numOfRoads, detination, startingPoint, distance;
	bool goodInput;
	cout << "Please enter num of cities and num of roads" << endl;
	do {
		goodInput = true;
		cin >> numOfCities >> numOfRoads;
		if (numOfRoads > (numOfCities * (numOfCities - 1) / 2)) // formula of complete graph
		{
			goodInput = false;
			cout << "The number of roads exceeds the maximum number of roads according to the number of cities, please try again." << endl;
		}
	} while (!goodInput);
	Country country(numOfCities);
	getRoads(country, numOfRoads, numOfCities);
	getDestAndStart(detination, startingPoint, numOfCities);
	distance = TownDistanceRec(country, country.getCity(startingPoint - 1), country.getCity(detination - 1), country.getColors());
	cout << "The recursive function returned: " << distance << endl;
	country.setWhites();
	distance = TownDistance(country, country.getCity(startingPoint - 1), country.getCity(detination - 1), country.getColors());
	cout << "The iterative function returned: " << distance << endl;
}