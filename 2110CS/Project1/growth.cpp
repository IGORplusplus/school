#include "growth.h"

bool GrowthFunction(vector<vector<Cell>>& cells, position& pos, int& pop, int& goods){

    //this is correct as far as I know, but I need to test it
    //with my own region and config file
int i=0;
if(!ComGrowthFunction(cells, pop, goods, pos)){
	i++; 
	if(!IndGrowthFunction(cells, pop, goods, pos)){
	    i++;
		if(!ResGrowthFunction(cells, pos, pop)){i++;}
	}
}
    if(i==3){return false;}
    return true;
}
