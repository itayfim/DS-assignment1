#ifndef __MAIN_H
#define __MAIN_H

#include "City.h"
#include "Country.h"
#include "List.h"

#define WHITE 0
#define BLACK 1
#define INVALID -1

void getRoads(Country& country, int numOfRoads, int numOfCities);
void setWhites(int* colors, int size);
void getDestAndStart(int& detination, int& startingPoint, int numOfCities);
int TownDistanceRec(Country& country, List& currCity, List& destCity, int* colors);
bool onlyBlackCities(List& currCity, int* colors);

#endif