#ifndef CELL_H
#define CELL_H
#include <string>
#include <vector>
#include "randomStructs.h"

using namespace std;
//if dynamically allocated make sure to make a destructor

class Cell{

private:
Cell* topL, *top, *topR, *left, *right, *botL, *bot, *botR;
int population;
int pollution;
int garbage = 0;

public:
//garbage specific things
int garbageTime = -1;

//experimenting with static int
//shared across all cells, I could have done this
//for more things
static int garbageCount;
static int garbageCollected;


//inline definitions because I am lazy
void AddGarbage(){garbage++;}
int GetGarbage(){return garbage;}
void CollectGarbage(){
	garbage -= 1;
}
void SetGarbage(int num){
	garbage = num;
}

char type;
int newPop = 0;

//Default in line constructor
Cell() : type(type), population(0), pollution(0), newPop(0), topL(nullptr), top(nullptr), topR(nullptr), left(nullptr), right(nullptr), botL(nullptr), bot(nullptr), botR(nullptr) {}

Cell(int type, int population, int pollution, Cell* topL,Cell* top, Cell* topR, Cell* left, Cell* right, Cell* botL, Cell* bot, Cell* botR ) : type(type), population(population), pollution(pollution), topL(topL), top(top), topR(topR), left(left), right(right), botL(botL), bot(bot), botR(botR) {}


//Get functions for every adjacent cell
Cell* GetAdjTL();
Cell* GetAdjT();
Cell* GetAdjTR();
Cell* GetAdjL();
Cell* GetAdjR();
Cell* GetAdjBL();
Cell* GetAdjB();
Cell* GetAdjBR();
char GetType();
int GetPoll();
int GetPop();


//these will ideally never be used
//Set functions for all adjacent cells
void SetAdjTL(Cell* adjCell);
void SetAdjT(Cell* adjCell);
void SetAdjTR(Cell* adjCell);
void SetAdjL(Cell* adjCell);
void SetAdjR(Cell* adjCell);
void SetAdjBL(Cell* adjCell);
void SetAdjB(Cell* adjCell);
void SetAdjBR(Cell* adjCell);
void SetType(char letter);
void SetPoll(int poll);
void SetPop(int pop);

int NumTypeAdjCells(vector<vector<Cell>> adjCells, char type);

int NumPopAdjCells(vector<vector<Cell>> adjCells, char type, int targetPop);

int TotPopAdjCells(vector<vector<Cell>> adjCells, char type);

Cell* firstCellofType(vector<vector<Cell>> adjCells, char type);

//these are defined in backwards order of how they will be called

};

#endif
