#include "garbageCollection.h"
#include "growth.h"

//I want the garbage man to collect garbage


   void GarbageCollection::printRoad(vector<vector<Cell>>& cells) {  

	Worker::printRoad(cells);
	
	cout << endl << "Garbage Man travel route" << endl;
	
	for(int j=0;j<cells[0].size();j++){
	    for(int i=0;i<cells.size();i++){
		if(cells[i][j].GetType() == ' ' && cells[i][j].NumTypeAdjCells(cells, '-') > 0)
		{
		    char dump = 'D';
		    cells[i][j].SetType(dump);
		    return;
		}
	    }
	}
    }

//I know this isn't the best practice but I initially wanted the garbage man
//to collect the garbage and not have it be an automated process
    bool GarbageCollect(vector<vector<Cell>>& cells, Day days){
    //THIS IS REALLY BAD but it works
	bool collect = false;	
	if(days == 1 || days == 4){
	    for(int i=0;i<cells.size();i++){
		for(int j=0;j<cells[i].size();j++){
		if(cells[i][j].NumTypeAdjCells(cells, '-') > 0 || cells[i][j].NumTypeAdjCells(cells, '#') > 0){
		    if(cells[i][j].GetType() == 'I' && cells[i][j].GetGarbage() > 0){
			cells[i][j].garbageCollected += 1;
			cells[i][j].CollectGarbage();
			DumpGrowth(cells);
			cells[i][j].garbageCollected = 0;
			collect = true;
		    }
		}
		else if(cells[i][j].NumTypeAdjCells(cells, ' ') > 0){
		  if(cells[i][j].GetType() == 'I' && cells[i][j].GetGarbage() > 0){
			cells[i][j].garbageCollected += 1;
			cells[i][j].CollectGarbage();
			collect = true;
			cells[i][j].garbageCollected = 0;
			Cell* cell = cells[i][j].firstCellofType(cells,' ');
			DumpGrowth(cells);
			if(cell != nullptr){
			    cell->SetPoll(cell->GetPoll() + 1);
			}
		   }
   
		}
		}
	    }
	}
	else if(days == 2 || days == 5){
	    for(int i=0;i<cells.size();i++){
		for(int j=0;j<cells[i].size();j++){
		if(cells[i][j].NumTypeAdjCells(cells, '-') > 0 || cells[i][j].NumTypeAdjCells(cells, '-') > 0){
		    if(cells[i][j].GetType() == 'C'  && cells[i][j].GetGarbage() > 0){
			cells[i][j].garbageCollected += 1;
			cells[i][j].CollectGarbage();
			DumpGrowth(cells);
			cells[i][j].garbageCollected = 0;
			collect = true;
		    }
		}
	
		}
		}
	    }
	else if(days == 3){
	    for(int i=0;i<cells.size();i++){
		for(int j=0;j<cells[i].size();j++){
		if(cells[i][j].NumTypeAdjCells(cells, '-') > 0 || cells[i][j].NumTypeAdjCells(cells, '-') > 0){
		    if(cells[i][j].GetType() == 'R'  && cells[i][j].GetGarbage() > 0){
			cells[i][j].garbageCollected += 1;
			cells[i][j].CollectGarbage();
			DumpGrowth(cells);
			cells[i][j].garbageCollected = 0;
			collect = true;
		    }
		}
	
		}
		}
	    }
	else{
	    return false;
	}
    return collect;
    }


void DumpGrowth(vector<vector<Cell>>& cells){
    const int totalGarbage = cells[0][0].garbageCollected; 
    int notDump = 0;
    for(int i=0;i<cells.size();i++){
	for(int j=0;j<cells[i].size();j++){
	    if(cells[i][j].GetType() == ' '){	
		notDump += cells[i][j].GetGarbage();
	    }
	}
    }
    for(int i=0;i<cells.size();i++){
	for(int j=0;j<cells[i].size();j++){
	    if(cells[i][j].GetType() == 'D'){	
		cells[i][j].SetGarbage( cells[i][j].GetGarbage() + totalGarbage - notDump);	
	    }
	}
    }


}
