//initial cell class that will be inherited by the other classes and will first test out the residential function
#include "cell.h"


//Return the character type

//Get functions for every adjacent cell
Cell* Cell::GetAdjTL(){
return topL;
}
Cell* Cell::GetAdjT(){
return top;
}
Cell* Cell::GetAdjTR(){
return topR;
}
Cell* Cell::GetAdjL(){
return left;
}
Cell* Cell::GetAdjR(){
return right;
}
Cell* Cell::GetAdjBL(){
return botL;
}
Cell* Cell::GetAdjB(){
return bot;
}
Cell* Cell::GetAdjBR(){
return botR;
}
char Cell::GetType(){
    return type;
}
int Cell::GetPop(){
    return population;
}
int Cell::GetPoll(){
    return pollution;
}


//Set functions for all adjacent cells
void Cell::SetAdjTL(Cell* adjCell){
topL = adjCell;
}
void Cell::SetAdjT(Cell* adjCell){
top = adjCell;
}
void Cell::SetAdjTR(Cell* adjCell){
topR = adjCell;
}
void Cell::SetAdjL(Cell* adjCell){
left = adjCell;
}
void Cell::SetAdjR(Cell* adjCell){
right = adjCell;
}
void Cell::SetAdjBL(Cell* adjCell){
botL = adjCell;
}
void Cell::SetAdjB(Cell* adjCell){
bot = adjCell;
}
void Cell::SetAdjBR(Cell* adjCell){
botR = adjCell;
}
void Cell::SetType(char letter){
    type = letter;
}
void Cell::SetPoll(int poll){
    pollution = poll;
}
void Cell::SetPop(int pop){
    population = pop;
}


int Cell::NumTypeAdjCells(vector<vector<Cell>> adjCells, char type){
   int i=0; 
    if(GetAdjTL() != nullptr){
	if(GetAdjTL()->GetType() == type){
	    i++;
	}
    }
    if(GetAdjT() != nullptr){
	if(GetAdjT()->GetType() == type){
	    i++;
	}
    }
    if(GetAdjTR() != nullptr){
	if(GetAdjTR()->GetType() == type){
	    i++;
	}
    }
    if(GetAdjL() != nullptr){
	if(GetAdjL()->GetType() == type){
	    i++;
	}
    }   
    if(GetAdjR() != nullptr){
	if(GetAdjR()->GetType() == type){
	    i++;
	}
    }
    if(GetAdjBL() != nullptr){
	if(GetAdjBL()->GetType() == type){
	    i++;
	}
    }
    if(GetAdjB() != nullptr){
	if(GetAdjB()->GetType() == type){
	    i++;
	}
    }
    if(GetAdjBR() != nullptr){
	if(GetAdjBR()->GetType() == type){
	    i++;
	}
    }

    return i;

}



int Cell::NumPopAdjCells(vector<vector<Cell>> adjCells, char type, int targetPop){
   int i=0; 
    if(GetAdjTL() != nullptr){
	if(GetAdjTL()->GetType() == type && GetAdjTL()->GetPop() >= targetPop){
	i++;    
	}
    }
    if(GetAdjT() != nullptr){
	if(GetAdjT()->GetType() == type && GetAdjT()->GetPop() >= targetPop){
	    i++;
	}
    }
    if(GetAdjTR() != nullptr){
	if(GetAdjTR()->GetType() == type && GetAdjTR()->GetPop() >= targetPop){
	    i++;
	}
    }
    if(GetAdjL() != nullptr){
	if(GetAdjL()->GetType() == type && GetAdjL()->GetPop() >= targetPop){
	    i++;
	}
    }   
    if(GetAdjR() != nullptr){
	if(GetAdjR()->GetType() == type && GetAdjR()->GetPop() >= targetPop){
	    i++;
	}
    }
    if(GetAdjBL() != nullptr){
	if(GetAdjBL()->GetType() == type && GetAdjBL()->GetPop() >= targetPop){
	    i++;
	}
    }
    if(GetAdjB() != nullptr){
	if(GetAdjB()->GetType() == type && GetAdjB()->GetPop() >= targetPop){
	    i++;
	}
    }
    if(GetAdjBR() != nullptr){
	if(GetAdjBR()->GetType() == type && GetAdjBR()->GetPop() >= targetPop){
	    i++;
	}
    }

    return i;

}


int Cell::TotPopAdjCells(vector<vector<Cell>> adjCells, char type){
   int i=0; 
    if(GetAdjTL() != nullptr){
	if(GetAdjTL()->GetType() == type){
	i += GetAdjTL()->GetPop();    
	}
    }
    if(GetAdjT() != nullptr){
	if(GetAdjT()->GetType() == type){
	i += GetAdjT()->GetPop();
	}
    }
    if(GetAdjTR() != nullptr){
	if(GetAdjTR()->GetType() == type){
	i += GetAdjTR()->GetPop();
	}
    }
    if(GetAdjL() != nullptr){
	if(GetAdjL()->GetType() == type){
	i += GetAdjL()->GetPop();
	}
    }   
    if(GetAdjR() != nullptr){
	if(GetAdjR()->GetType() == type){
	i += GetAdjR()->GetPop();
	}
    }
    if(GetAdjBL() != nullptr){
	if(GetAdjBL()->GetType() == type){
	i += GetAdjBL()->GetPop();
	}
    }
    if(GetAdjB() != nullptr){
	if(GetAdjB()->GetType() == type){
	i += GetAdjB()->GetPop();
	}
    }
    if(GetAdjBR() != nullptr){
	if(GetAdjBR()->GetType() == type){
	i += GetAdjBR()->GetPop();
	}
    }

    return i;
}


