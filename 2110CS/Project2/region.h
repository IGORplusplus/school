#ifndef REGION
#define REGION

#include "cell.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

bool initializeRegion(std::string f, std::vector<std::vector<Cell>>& cells, int& mr, int& mc);

#endif
