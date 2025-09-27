//inherited industrial class
#include "cell.h"
#include "growth.h"
#include <iostream>
#include <iomanip>
#include <sstream>


using namespace std;

//this needs to be fixed a lot
bool IndGrowthFunction(vector<vector<Cell>>& cells, int& pop, int& goods, position& pos){
	int highPopCount = 0;
	bool growth = false;
	bool powerLine = false;
	int priority = 0;

	//industrial specific values
	int initGoods = goods;

if(pop >= 2){
  for(int i=cells.size() - 1; i>=0;i--) {
      for(int j=cells[i].size() - 1; j>=0; j--) {
		
	if(cells[i][j].GetType() == 'I'){


	if(cells[i][j].NumPopAdjCells(cells, 'I', 2)>= 4 && cells[i][j].GetPop() == 2 && priority <= 3){
		priority = 3;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'I')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'I');
		}
        } 
		else if(cells[i][j].NumPopAdjCells(cells, 'I', 1)>= 2 && cells[i][j].GetPop() == 1  && priority <= 4){
		priority = 2;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'I')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'I');
		}
        } 
		else if(cells[i][j].NumPopAdjCells(cells, 'I', 1)>= 1 && cells[i][j].GetPop() == 0  && priority <= 3){
		priority = 1;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'I')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'I');
		}
        }
		else if(cells[i][j].NumPopAdjCells(cells, 'I', 1)>= 2 && cells[i][j].GetPop() == 1&& priority <= 2){
		priority = 1;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'I')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'I');
		}
        }


		//this has a very janky way of dealing with the powerLine
		//lines but it somewhat works
		//would it necessarily scale to a bigger city, probably not
		else if(cells[i][j].NumPopAdjCells(cells, 'I', 1)>= 1 && cells[i][j].GetPop() == 0 && priority <= 1 && powerLine == false) // && powerLine == false
		{ //powerline false seems kind of useless
		priority = 1;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'I')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'I');
		}	
        }   


		else if(cells[i][j].NumTypeAdjCells(cells, 'T') + cells[i][j].NumTypeAdjCells(cells, '#') > 0 && cells[i][j].GetPop() == 0 && priority <= 0){
		priority = 0;
		powerLine = true;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'I')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'I');
		}
//int Cell::TotPopAdjCells(vector<vector<Cell>> adjCells, char type){
	}	
      }

  }
}
}
	    //just a little extra verification
    if(growth) {
	cells[pos.x][pos.y].newPop = cells[pos.x][pos.y].newPop + 1;
	pop = pop - 2;   
	goods = goods + 1;
	cells[pos.x][pos.y].garbageTime = 2;
    }
    return growth; 
}


//pollution spread
//need to make this function like in the example
void pollutionSpread(vector<vector<Cell>>& cells, position& pos){

    int newPoll = 0; 

    //another layer of verification
    if(cells[pos.x][pos.y].GetType() == 'I'){
	    newPoll = cells[pos.x][pos.y].GetPop() + cells[pos.x][pos.y].newPop;
	    cells[pos.x][pos.y].SetPoll(newPoll);
    	
    newPoll = newPoll - 1;
    //fix this
    if(cells[pos.x][pos.y].GetAdjTL() != nullptr){
	Cell* cell = cells[pos.x][pos.y].GetAdjTL();
	cell->SetPoll(newPoll + cell->GetPoll());
    }
    if(cells[pos.x][pos.y].GetAdjT() != nullptr){
	Cell* cell = cells[pos.x][pos.y].GetAdjT();
	cell->SetPoll(newPoll + cell->GetPoll());
    }
    if(cells[pos.x][pos.y].GetAdjTR() != nullptr){
	Cell* cell = cells[pos.x][pos.y].GetAdjTR();
	cell->SetPoll(newPoll + cell->GetPoll());
    }
    if(cells[pos.x][pos.y].GetAdjL() != nullptr){
	Cell* cell = cells[pos.x][pos.y].GetAdjL();
	cell->SetPoll(newPoll + cell->GetPoll());
    }
    if(cells[pos.x][pos.y].GetAdjR() != nullptr){
	Cell* cell = cells[pos.x][pos.y].GetAdjR();
	cell->SetPoll(newPoll + cell->GetPoll());
    }
    if(cells[pos.x][pos.y].GetAdjBL() != nullptr){
	Cell* cell = cells[pos.x][pos.y].GetAdjBL();
	cell->SetPoll(newPoll + cell->GetPoll());
    }
    if(cells[pos.x][pos.y].GetAdjB() != nullptr){
	Cell* cell = cells[pos.x][pos.y].GetAdjB();
	cell->SetPoll(newPoll + cell->GetPoll());
    }
    if(cells[pos.x][pos.y].GetAdjBR() != nullptr){
	Cell* cell = cells[pos.x][pos.y].GetAdjBR();
	cell->SetPoll(newPoll + cell->GetPoll());
    }
    }

    cells[pos.x][pos.y].garbageTime = 5;
//now spread pollution from this cell
}


void PrintPollutionMap(vector<vector<Cell>>& cells){

    const int width = 6;
    cout << setw(width) << left << "";
    for(int i=0;i<cells[0].size();i++){
	cout << setw(width) << left << i;
    }
    cout << endl;

	for(int i=0; i<cells.size(); i++){
	//I would componentize this if I was smart sorry
		cout << setw(width) << left << i;
		for(int j=0; j<cells[i].size(); j++) {
		    stringstream ss;
		    ss << cells[i][j].GetType();
		    if(cells[i][j].GetPoll() != 0){
			ss << "(" << cells[i][j].GetPoll() << ")";
		    }
		    string out = ss.str();
		    cout << setw(width) << left << out;
		}
	cout << endl;
	}
}
