#include "growth.h"
#include <iostream>

using namespace std;

bool ResGrowthFunction(vector<vector<Cell>>& cells, position& pos, int& pop){
	int highLineCount = 0;
	int highPopCount = 0;
	bool growth = false;
	bool powerLine = false;
	int priority = 0;
  for(int i=cells.size()-1; i>=0;i--) {
      for(int j=cells[i].size()-1; j>=0;j--) {
		
	if(cells[i][j].GetType() == 'R'){


//int Cell::NumPopAdjCells(vector<vector<Cell>> adjCells, char type, int targetPop){
	
	  //use check adjacent cell functions and mark the most eligible to grow unless a more
	  //eligible to grow cell pops up
	
	if(cells[i][j].NumPopAdjCells(cells, 'R', 4)>= 8 && cells[i][j].GetPop() == 4 && priority <= 5){
		priority = 5;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'R')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'R');
		}
        } 
		else if(cells[i][j].NumPopAdjCells(cells, 'R', 3)>= 6 && cells[i][j].GetPop() == 3  && priority <= 4){
		priority = 4;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'R')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'R');
		}
        } 
		else if(cells[i][j].NumPopAdjCells(cells, 'R', 2)>= 4 && cells[i][j].GetPop() == 2  && priority <= 3){
		priority = 3;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'R')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'R');
		}
        }
		else if(cells[i][j].NumPopAdjCells(cells, 'R', 1)>= 2 && cells[i][j].GetPop() == 1&& priority <= 2){
		priority = 2;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'R')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'R');
		}
        }


		//this has a very janky way of dealing with the powerLine
		//lines but it somewhat works
		//would it necessarily scale to a bigger city, probably not
		else if(cells[i][j].NumPopAdjCells(cells, 'R', 1)>= 1 && cells[i][j].GetPop() == 0 && priority <= 1 && powerLine == false) 
		{
		priority = 1;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'R')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'R');
		}	
        }   


		else if(cells[i][j].NumTypeAdjCells(cells, 'T') + cells[i][j].NumTypeAdjCells(cells, '#') >= highLineCount && cells[i][j].GetPop() == 0 && priority <= 0){
		highLineCount = cells[i][j].NumTypeAdjCells(cells, 'T');
		priority = 0;
		powerLine = true;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'R')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'R');
		}
//int Cell::TotPopAdjCells(vector<vector<Cell>> adjCells, char type){
	}	
      }

  }
}
	 cells[pos.x][pos.y].newPop = cells[pos.x][pos.y].newPop + 1;
	 if(growth){ pop = pop + 1;} 
	 return growth;
}
