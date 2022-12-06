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
		if (numOfRoads > (numOfCities * (numOfCities - 1) / 2)) // formula of complete graph, input check
		{
			goodInput = false;
			cout << "The number of roads exceeds the maximum number of roads according to the number of cities, please try again." << endl;
		}
	} while (!goodInput);
	Country country(numOfCities);
	// get input from user:
	getRoads(country, numOfRoads, numOfCities);
	getDestAndStart(detination, startingPoint, numOfCities);
	// recursive function:
	distance = TownDistanceRec(country, country.getCity(startingPoint - 1), country.getCity(detination - 1), country.getColors());
	cout << "The recursive function returned: " << distance << endl;
	// resets the color array to whites
	country.setWhites();
	// iterative function:
	distance = TownDistance(country, country.getCity(startingPoint - 1), country.getCity(detination - 1), country.getColors());
	cout << "The iterative function returned: " << distance << endl;
}