#include "worker.h"
#include <cstdlib>
#include <utility>
#include <iomanip>
#include <sstream>

    //this is not really initializing route its just printing it
    void Worker::printRoad(vector<vector<Cell>>& cells){

    const int width = 8;
    cout << setw(width) << left << "";
    for(int i=0;i<cells.size();i++){
	cout << setw(width) << left << i;
    }
    cout << endl;

	for(int i=0; i<cells.size(); i++){
	//I would componentize this if I was smart sorry
		cout << setw(width) << left << i;
		for(int j=0; j<cells[i].size(); j++) {
		    stringstream ss;
		    if(cells[i][j].GetType() == '-' || cells[i][j].GetType() == '#'){
			ss << cells[i][j].GetType();
		    }
		    else{ ss << ' ';}
		    string out = ss.str();
		    cout << setw(width) << left << out;
		}
	    cout << endl;
    }
	printf("\n\n\n");
    }
    



    void Worker::FindStartPosition(vector<vector<Cell>> cells, char type, char station){
	for(int i=0;i<cells.size();i++){

	    for(int j=0;j<cells[i].size();j++){

		if(cells[i][j].GetType() == type){
		    cells[i][j].SetType(station);
		    this->pos.x = i;
		    this->pos.y = j;
		    return;
		}

	    }
	}

    }

   void Worker::GrowStation(vector<vector<Cell>>& cells, char station){
	for(int i=0;i<cells.size();i++){

	    for(int j=0;j<cells[i].size();j++){

		if(cells[i][j].NumTypeAdjCells(cells, station) > 0){
		    cells[i][j].SetType(station);
		}

	    }
	}

   }
    
