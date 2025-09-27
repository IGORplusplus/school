#include "config.h"
#include <algorithm>
#include <cctype>

using namespace std;

bool readConfigFile(string& configFilename, string& regionFile, int& timeLimit, int& refreshRate) {
    ifstream inFile(configFilename);
	while(!inFile.is_open()) {

	    cout << "Failed to open config file: "  << configFilename << endl;
	    cout << "Enter in the correct name of the config file: " << endl;
	    cin >> configFilename;
	    cin.ignore();
	    inFile.close(); 
	    inFile.open(configFilename);
	    if(!inFile.is_open()){
		cout << "Do you want to quit, y or n?" << endl;
		char option;
		cin >> option;
		if(option=='y' || option=='Y'){ return false; }
		else{continue;}
	    }
	}
	
	string line;
	if(getline(inFile, line)){
		regionFile = line.substr(line.find(':') + 1);
		regionFile.erase(remove_if(regionFile.begin(), regionFile.end(), ::isspace), regionFile.end());	
	// there was a real weird bug here	cout << regionFile.size() << endl;}
	if(getline(inFile, line)){
		timeLimit = stoi(line.substr(line.find(':') + 1));}
	if(getline(inFile, line)){
		refreshRate = stoi(line.substr(line.find(':') + 1));}
	inFile.close();
	return true;
	
}
return false;
}
