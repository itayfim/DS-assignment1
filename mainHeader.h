#ifndef __MAIN_H
#define __MAIN_H

#include "City.h"
#include "Country.h"
#include "List.h"
#include "SBullet.h"
#include "Stack.h"

#define WHITE 0
#define BLACK 1
#define INVALID -1
#define START 0
#define AFTER 1

void getRoads(Country& country, int numOfRoads, int numOfCities);
void setWhites(int* colors, int size);
void getDestAndStart(int& detination, int& startingPoint, int numOfCities);
int TownDistanceRec(Country& country, List& currCity, List& destCity, int* colors);
int TownDistance(Country& country, List& currCity, List& destCity, int* colors);
void removeDuplicates(Country& country);
void setFieldForCurr(SBullet& curr, List* currList, City* currCity, int d, int line);

#endif