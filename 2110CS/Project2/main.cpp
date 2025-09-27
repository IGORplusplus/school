//First open up file and verify
//Next read through all of the file and input into vectors
//Lastly use a while loop to go through and run check for update and update

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "cell.h"
#include "config.h"
#include "region.h"
#include "growth.h"
#include "adjSetup.h"
#include "garbageCollection.h"

using namespace std;

//used to instantly access element that has been marked for growth
void printStart(){
    cout << R"(

 _     _ _  ___   ___  _ ____
(_) __| | |/ _ \ / _ \/ | ___|
| |/ _` | | | | | | | |___ \
| | (_| | | |_| | |_| | |___) |
|_|\__,_|_|\___/ \___/|_|____/
/ ___|(_)_ __ ___    / ___(_) |_ _   _
\___ \| | '_ ` _ \  | |   | | __| | | |
 ___) | | | | | | | | |___| | |_| |_| |
|____/|_|_| |_| |_|  \____|_|\__|\__, |
                                 |___/

)";

    cout << "Cells will print according to the standard rules, however, " << endl;
    cout << "if they have garbage it will print after pollution inside parentheses." << endl << endl;
    cout << "Garbage will be picked up in the industrial zone on Monday and Thursday," << endl;
    cout << "in the commercial zone on Tuesday and Friday, and in the residential" << endl;
    cout << "zone on Wednesday." << endl;
}


void printSimMenu(){
	cout << "1. Simulate next step" << endl;
	cout << "2. Skip ahead # of steps" << endl;
	cout << "3. Stop simulation and analyze" << endl;
	cout << "4. Quit simulation" << endl;
}


void printCity(vector<vector<Cell>> cells, int mxr, int mxc, int totPop, int nTime, int totPoll, int totGoods, Day days){
    int totalPollution = 0;
	for(int i=0;i<cells.size();i++){
	    for(int j=0;j<cells[i].size();j++){

		if(cells[i][j].GetPoll() >= 1){
		    totalPollution += cells[i][j].GetPoll();
		}
	}
    }

    const int width = 8;
    cout << setw(width) << left << "";
    for(int i=0;i<mxr;i++){
	cout << setw(width) << left << i;
    }
    cout << endl;

	for(int i=0; i<mxr; i++){
	//I would componentize this if I was smart sorry
		cout << setw(width) << left << i;
		for(int j=0; j<mxc; j++) {
		    stringstream ss;
		    if(cells[i][j].GetPop() > 0){
			ss << cells[i][j].GetPop();
		    }
		    else{ ss << cells[i][j].GetType();}
		    if(cells[i][j].GetPoll() != 0){
			ss << "(" << cells[i][j].GetPoll() << ")";
			if(cells[i][j].GetGarbage() != 0){
			ss << "(" << cells[i][j].GetGarbage() << ")";
			}
			else{
			ss << "()";
			}
		    }
		    else if(cells[i][j].GetGarbage() != 0){
			ss << "()";
			ss << "(" << cells[i][j].GetGarbage() << ")";
		    }
		    else if(cells[i][j].GetGarbage() == 0){
		    }
		    else{}

		    string out = ss.str();
		    cout << setw(width) << left << out;
		}
	cout << endl;
	}

	string day;
	switch(days){
	    case 0: day = "Sunday"; break;
	    case 1: day = "Monday"; break;
	    case 2: day = "Tuesday"; break;
	    case 3: day = "Wednesday"; break;
	    case 4: day = "Thursday"; break;
	    case 5: day = "Friday"; break;
	    case 6: day = "Saturday"; break;
	}

	cout << endl << "Available Population: " << totPop << endl;
	cout << "Goods Produced: " << totGoods << endl;
	cout << "Total Pollution: " << totalPollution << endl;
	cout << "Time Step: " << nTime << endl;
	cout << "Total Garbage: " << cells[0][0].garbageCount << endl;
	cout << "Day of the Week: " << day << endl;

	if(days == 1 || days == 4)
	  cout << "Industrial Cell's garbage was picked up" << endl;
	else if(days == 2 || days == 5)
	  cout << "Commercial Cell's garbage was picked up" << endl;
	else if(days == 3)
	  cout << "Residential Cell's garbage was picked up" << endl;
	else
	  cout << "The garbage man wanted to take a break" << endl;
	cout << endl;

}


    //make pos a vector of positions so that it can also update pollution and other values
    void grow(vector<vector<Cell>>& cells, position& pos){
	if(cells[pos.x][pos.y].newPop > 0){
	    cells[pos.x][pos.y].SetPop(cells[pos.x][pos.y].GetPop() + 1);
	    pos.x =0;
	    pos.y =0;
	}
	else{
	    cerr << "The position that was input was not set to grow." << endl;
	}

    }

    void AddToTotalPopulation(vector<vector<Cell>>& cells,position pos,int& totPop, int& totGoods)
    {
     if(cells[pos.x][pos.y].newPop > 0){
		    cells[pos.x][pos.y].SetPop(cells[pos.x][pos.y].GetPop() + 1);
		    if(cells[pos.x][pos.y].GetType() == 'R'){totPop++;}
		    else if(cells[pos.x][pos.y].GetType() == 'I'){totPop -= 2;}
		    else if(cells[pos.x][pos.y].GetType() == 'C'){totPop -= 1;}
		}
    }



    void AnalyzeCity(vector<vector<Cell>> cells){
    bool valid = true;

    //have to declare these guys before the switch statement
		int x;
		int y;
		bool validPosition = true;
    while(valid){
	cout << "Analyze region(r) or cell(c) or Quit(q)" << endl;
	char option;
	char option2;
	int pop = 0;
	int poll = 0;
	cin >> option;
	switch(option){
	    case 'r':
		cout << "Enter in what region you would like to analyze" << endl;
		cout << "Residential(r) Commercial(c) Industrial (i)" << endl;
		cin >> option2;
		if(option == 'r'){
		for(int i=0;i<cells.size();i++){
		    for(int j=0;j<cells[i].size();j++){
			if(cells[i][j].GetType() == 'R')
				pop += cells[i][j].GetPop();
		    }
		}
		cout << "Total Residential Population: " << pop << endl;
		}
		else if(option == 'c'){
		for(int i=0;i<cells.size();i++){
		    for(int j=0;j<cells[i].size();j++){
				if(cells[i][j].GetType() == 'C')
				pop += cells[i][j].GetPop();
		    }
		}
		cout << "Total Commercial Population: " << pop << endl;
		pop = 0;
		}
		else if(option == 'i'){
		for(int i=0;i<cells.size();i++){
		    for(int j=0;j<cells[i].size();j++){
			if(cells[i][j].GetType() == 'I')
				pop += cells[i][j].GetPop();
				poll += cells[i][j].GetPoll();

		    }
		}
		    cout << "Total Industrial Population: " << pop << endl;
		    cout << "Total Industrial Pollution: " << poll << endl;
		    pop = 0;
		    poll = 0;
		}
		else{cout << "Invalid option" << endl;}
	    break;

	    //cell analysis
	    case 'c':
		cout << endl << "Enter in the x,y coordinates of the cell you would like" << endl;
		cout << "to know the information of." << endl;
		cout << "Enter in x" << endl;
		cin >> x;
		cout << "Enter in y" << endl;
		cin >> y;

		if(x<cells.size() && x>=0 && y<cells[1].size() && y>= 0){
		    validPosition = true;
		}
		else{validPosition = false;}
		if(validPosition){
		    Cell cell = cells[y][x];
		    cout << "Cell's type " << cell.GetType() << endl;
		    cout << "Cell population " << cell.GetPop() << endl;
		    cout << "Cell's adjacent population " << cell.TotPopAdjCells(cells, cells[y][x].GetType());
		    cout << endl;
		}
		validPosition = false;
	    break;

	    case 'q':
		cout << "Quitting anaylsis function" << endl;
		valid = false;
	    break;

	    default:
		cout << "Invalid option" << endl;
    }
    }
    }

    //not called by reference because I do not want to change the cells value
    //final state
    void AnalysisFinal(vector<vector<Cell>> cells){

    int totalPop = 0;
    int totalResidential = 0;
    int totalIndustrial = 0;
    int totalCommercial = 0;
    int totalPollution = 0;
	for(int i=0;i<cells.size();i++){
	    for(int j=0;j<cells[i].size();j++){
		if(cells[i][j].GetPop() >= 1){
		   totalPop += cells[i][j].GetPop();
		}

		if(cells[i][j].GetPop() >= 1 && cells[i][j].GetType() == 'R'){
		   totalResidential = totalResidential + cells[i][j].GetPop();
		}

		if(cells[i][j].GetPop() >= 1 && cells[i][j].GetType() == 'I'){
		   totalIndustrial += cells[i][j].GetPop();
		}

	    	if(cells[i][j].GetPop() >= 1 && cells[i][j].GetType() == 'C'){
		   totalCommercial += cells[i][j].GetPop();
		}

		if(cells[i][j].GetPoll() >= 1){
		    totalPollution += cells[i][j].GetPoll();
		}

	}
    }
    PrintPollutionMap(cells);

		cout << "Total Population: " << totalPop << endl;
		cout << "Residential Population: " << totalResidential << endl;
		cout << "Industrial Population: " << totalIndustrial << endl;
		cout << "Commercial Population: " << totalCommercial << endl << endl;
		cout << "Total Pollution: " << totalPollution << endl;

    }



int main(){

    printStart();
        int mxr, mxc;
	int totPop = 0;
	int totGoods = 0;
	int totPoll = 0;
	//Make it so that there is a while loop until the correct input is inputted for the config file
	cout << "Enter configuration filename: " ;
	string cf;
	getline(cin, cf);
	string rf;
	int tl = 0, rr =0;

    	if(!readConfigFile(cf, rf, tl, rr));
	//because of refresh rate look into how I will iterate according to the amount of times of
	//time steps
     	else {}

	vector<vector<Cell>> cells;

	//initializing these to initialize the route
	GarbageCollection garbage;
	vector<position> route;
	vector<position> travelRoute;

	Day days = Sunday;

	initializeRegion(rf, cells, mxr, mxc);
	//only needs one initialization
	garbage.printRoad(cells);

	SetAdjacencies(cells, mxr, mxc);
	//this is for the analysis function so I can start from the beginning of the simulation
	//more easily

	int option = 0;
	bool loopValid = true;
	int timeStep = 0;

	//this marked for growth position will always need to be verified when setting cell of position to its new population
	position pos;
	pos.x = 0;
	pos.y = 0;

	while(loopValid){

	printCity(cells, mxr, mxc, totPop, timeStep, totPoll, totGoods, days);
	printSimMenu();
	days = static_cast<Day>(timeStep % 7);
	cin >> option;
	switch (option){
	    case 1:

		for(int i=0; i < rr; i++){
		    if(!GrowthFunction(cells, pos, totPop, totGoods, days)){
			cout << "The city did not grow, therefore it stopped the loop." << endl;
			break;}

			garbageGrowth(cells);
			DumpGrowth(cells);
			if(cells[pos.x][pos.y].newPop > 0){
			    if(cells[pos.x][pos.y].GetType() == 'I'){
				pollutionSpread(cells, pos);
			    }
			cells[pos.x][pos.y].newPop = 0;
			cells[pos.x][pos.y].SetPop(cells[pos.x][pos.y].GetPop() + 1);
			}
		    AddToTotalPopulation(cells, pos, totPop, totGoods);
		}
		timeStep++;
	    break;

	    case 2:
		int numSkips;
		cout << "Please enter the number of time you want to time skip" << endl;
		cin >> numSkips;

		//check if invalid
		if(numSkips + timeStep > tl || numSkips < 1) { cout << "Invalid number of skips" << endl << endl;
		}
		//if valid
		else{
		    for(int i=0; i<numSkips;i++){
			for(int j=0;j<rr;j++){


			//replace with actual grow function
		    if(!GrowthFunction(cells, pos, totPop, totGoods, days)){break;}
			garbageGrowth(cells);
			if(cells[pos.x][pos.y].newPop > 0){
			cells[pos.x][pos.y].newPop = 0;
			cells[pos.x][pos.y].SetPop(cells[pos.x][pos.y].GetPop() + 1);
			}
			    //I will add in garbage eventually
			AddToTotalPopulation(cells, pos, totPop, totGoods);
			timeStep++;
			}
			//pollution function
		    }
		}
	    break;

	    case 3:
		AnalyzeCity(cells);
	    break;

	    case 4:
		cout << "Quitting simulation" << endl;
		loopValid = false;
	    break;

	    default:
	    cout << "Invalid option, try again." << endl;
	}
	if(timeStep > tl){break;}
	}


	//enter into analysis mode
	if(timeStep < tl){}
	else{
	cout << "Simulation is complete" << endl << endl << endl;
	}




	cout << endl << endl << "Final State Analysis" << endl;

	//add analysis function
	AnalysisFinal(cells);

	cout << "Analysis Complete" << endl;
	cout << "Program ended" << endl;


	//begin analysis phase if I have time

return 0;
}
