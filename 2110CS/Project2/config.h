#ifndef CONFIG_FILE
#define CONFIG_FILE

#include "cell.h"
#include "region.h"
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
#include <iostream>

using namespace std;
bool readConfigFile(string& configFilename, string& regionFile, int& timeLimit, int& refreshRate);

#endif
