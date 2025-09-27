#ifndef GROWTH_H
#define GROWTH_H

#include "cell.h"
#include <vector>

using namespace std;

//residential functions
bool ResGrowthFunction(vector<vector<Cell>>& cells, position& pos, int& pop);

//Industrial Functions
bool IndGrowthFunction(vector<vector<Cell>>& cells, int& pop, int& goods, position& pos);
void pollutionSpread(vector<vector<Cell>>& cells, position& pos);

//Commercial Functions
bool ComGrowthFunction(vector<vector<Cell>>& cells, int& pop, int& goods, position& pos);

bool GrowthFunction(vector<vector<Cell>>& cells, position& pos, int& pop, int& goods);

#endif
