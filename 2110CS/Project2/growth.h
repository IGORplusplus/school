#ifndef GROWTH_H
#define GROWTH_H

#include "cell.h"
#include "randomStructs.h"
#include <vector>

using namespace std;

//residential functions
bool ResGrowthFunction(vector<vector<Cell>>& cells, position& pos, int& pop);

//Industrial Functions
bool IndGrowthFunction(vector<vector<Cell>>& cells, int& pop, int& goods, position& pos);

void pollutionSpread(vector<vector<Cell>>& cells, position& pos);
void PrintPollutionMap(vector<vector<Cell>>& cells);

void garbageGrowth(vector<vector<Cell>>& cells);
//going to implement this along with the pollution spread map
void PrintGarbageMap(vector<vector<Cell>>& cells);
bool GarbageCollect(vector<vector<Cell>>& cells, Day days);
void DumpGrowth(vector<vector<Cell>>& cells);

//Commercial Functions
bool ComGrowthFunction(vector<vector<Cell>>& cells, int& pop, int& goods, position& pos);

bool GrowthFunction(vector<vector<Cell>>& cells, position& pos, int& pop, int& goods, Day& days);

#endif
