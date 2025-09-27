//commercial growth function definition
#include "growth.h"

using namespace std;
//bool ComGrowthFunction(vector<vector<Cell>>& cells, int& pop, int& goods, position& pos);
bool ComGrowthFunction(vector<vector<Cell>>& cells, int& pop, int& goods, position& pos){
	int highPopCount = 0;
	bool growth = false;
	bool powerLine = false;
	int priority = 0;


if(pop >= 1 && goods >= 1){
  for(int i=cells.size() - 1; i>=0;i--) {
      for(int j=cells[i].size() - 1; j>=0; j--) {
		
	if(cells[i][j].GetType() == 'C'){


	if(cells[i][j].NumPopAdjCells(cells, 'C', 1)>= 2 && cells[i][j].GetPop() == 1 && priority <= 2){
		priority = 2;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'C')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'C');
		}
        }	else if(cells[i][j].NumPopAdjCells(cells, 'C', 1)>= 1 && cells[i][j].GetPop() == 0  && priority <= 1){
		priority = 1;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'C')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'C');
		}
        }
		else if(cells[i][j].NumTypeAdjCells(cells, 'T') + cells[i][j].NumTypeAdjCells(cells, '#') > 0 && cells[i][j].GetPop() == 0 && priority <= 0){
		priority = 0;
		powerLine = true;
		growth = true;
		if( highPopCount <= cells[i][j].TotPopAdjCells(cells, 'C')){
		pos.x = i;
		pos.y = j;
		highPopCount = cells[i][j].TotPopAdjCells(cells, 'C');
		}
	}	
      }

  }
}
	 cells[pos.x][pos.y].newPop = cells[pos.x][pos.y].newPop + 1;
}
    if(growth) {pop = pop - 1; goods = goods - 1;}
    return growth; 
}
