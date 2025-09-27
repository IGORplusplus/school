#include "cell.h"
#include "growth.h"

void garbageGrowth(vector<vector<Cell>>& cells){
    for(int i=0;i<cells.size();i++){
	for(int j=0;j<cells[i].size();j++){
	    if(cells[i][j].garbageTime > 0){
		cells[i][j].garbageTime -= 1;
	    if(cells[i][j].garbageTime == 0){
		cells[i][j].AddGarbage();
		cells[i][j].garbageCount += 1;
		if(cells[i][j].GetType() == 'C'){
		    cells[i][j].garbageTime += 3;
		}
		else if(cells[i][j].GetType() == 'I'){
		    cells[i][j].garbageTime += 2;
		}
		else if(cells[i][j].GetType() == 'R'){
		    cells[i][j].garbageTime  += 4;
		}
	    }
	    }
	}
    }

}

