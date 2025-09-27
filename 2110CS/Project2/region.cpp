#include "region.h"
using namespace std;

//this is going to initialize two by two vector and
//make it so that each cell has its correct adjacencies

bool initializeRegion(string f, vector<vector<Cell>>& cells, int& mr, int& mc) {
	ifstream in;
	in.open(f);
	if (!in.is_open()) {
		cerr << "Failed to open region file: " << f  << endl;
		return false;
	}

	string line;
	int rCount = 0;
	int cCount = 0;

	vector<string> rows;
	
	int currentColCount = 0;
	//read in the row
	while (getline(in, line)) {
		rows.push_back(line);
		rCount++;	
		stringstream ss(line);


        
        // Check the number of columns in each row
    	while (getline(ss, line, ',')) {
	    	currentColCount++;
		mc = currentColCount;
    	}
	    	currentColCount = 0;
	}
	mr = rCount;
	
	cout << "Row size: " << mr << endl;
	cout << "Column size: " << mc << endl;
	cells.resize(mr, vector<Cell>(mc));

	//clear in file
	    in.clear();
	//bring inFile back to beginning
	    in.seekg(0, ios::beg); 
	    rCount = 0;

	while(getline(in, line) && rCount < mr){
	    int cCount = 0;
	    stringstream ss(line);
	    string cellValues;
	    
	    vector<char> rowChars(mc);
	    
	    while (getline(ss, cellValues, ',')) {
		if (!cellValues.empty()) {
		    cells[rCount][cCount].SetType(cellValues[0]);
		} else {
		    cells[rCount][cCount].SetType(' ');
		}
	    cCount++;
	    }
	rCount++;
	}
in.close();

//need to initialize cell adjacencies


    for(int i=0;i<cells.size();i++){
	for(int j=0;j<cells[i].size();j++){
	    if(i>0 && j>0){ cells[i][j].SetAdjTL(&cells[i-1][j-1]);}
	    if(i>0){cells[i][j].SetAdjT(&cells[i-1][j]);}
	    if(i>0 && j < cells[i].size() - 1){cells[i][j].SetAdjTR(&cells[i-1][j+1]);}
	    if(j>0){cells[i][j].SetAdjL(&cells[i][j-1]);}
	    if(j < cells[i].size() - 1){cells[i][j].SetAdjR(&cells[i][j+1]);}
	    if(i < cells.size() - 1 && j > 0){cells[i][j].SetAdjBL(&cells[i+1][j-1]);}
	    if(i < cells.size() -1){cells[i][j].SetAdjB(&cells[i+1][j]);}
	    if(i < cells.size() - 1 && j < cells[i].size() - 1){cells[i][j].SetAdjBR(&cells[i+1][j+1]);}
	}
    }

return true;
}

