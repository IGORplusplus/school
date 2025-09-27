#ifndef WORKER_H
#define WORKER_H

#include "cell.h"
#include <iostream>


//will need to change print function in main
class Worker{
public:

   struct adjacencies{
       Cell* TL;
       Cell* T;
       Cell* TR;
       Cell* L;
       Cell* R;
       Cell* BL;
       Cell* B;
       Cell* BR;
   };

   position pos;
   vector<position> travelRoute;
  
    //this will initialize the route on which the garbage man will travel, his initial position, and
    //the dump represented by D
    //this will also print out the route in the beginning of main
   virtual void printRoad(vector<vector<Cell>>& cells);  
   void FindStartPosition(vector<vector<Cell>> cells, char type, char station);
   void GrowStation(vector<vector<Cell>>& cells, char station);

   void FindRouteBack(vector<vector<Cell>> cells, position pos, position target, vector<position>& travelRoute);

    //still need to implement this one
   void MoveWorker(vector<vector<Cell>> cells, position& pos, position target);
};


#endif
