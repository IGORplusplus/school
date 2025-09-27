#include "graph.h"
#include <iostream>

using namespace std;


void printMenu(){
    cout << "1. test adjacencies" << endl;
    cout << "2. print adjacency list" << endl;
    cout << "-1. Quit" << endl << endl;
}



//this program will only create one graph and not resize it or anything
//it will just analyze the input graph
int main(){

    int size;
    cout << "How many nodes are in the graph?" << endl;
    cin >> size;
    if(size <= 0){
	cerr << "The value can't be 0 or negative" << endl;
	bool valid = false;
	while(!valid){
	    cout << "Try again" << endl;
	    cin >> size;
	    if(size > 0){valid = true;}
	    else{}
	}
    }

    //this is to initialize the vectors
    Graph graph(size);

    int input = 0;
    graph.initializeAdjList();

    cout << endl << "The graph is now initialized with it's adjacency lists" << endl << endl;

    graph.printAdjList();
    printMenu();
    cout << "The path testing has not yet been implemented" << endl;
    cout << "I was going to but did not have enough time" << endl << endl;

    bool valid = true;
    int option = -1;

    cin >> option;
    if(option == -1){valid = false;}


    //user specified connections
    while(valid){

	printMenu();
	graph.printAdjList();
	cin >> option;

	switch(option){

	case 1:
	    cout << "Enter in the list of nodes you want to test for." << endl;
	    cout << "This hasn't been implemented yet." << endl;

	    /*
	    vector<int> userVector;
	    input = 0;
	    while(input != -1){
		cin >> input;
		    if(input == -1){
			cout << "Invalid" << endl;
			break;
		    }
		userVector.push_back(input);
	    }
	    //unimplemented

	    for(int i=0; i<userVector.size();i++){
		bool open = true;
		bool trail = true;
		    if(IsOpen( userVector ){}
		    else{open = false;}

		    if(IsTrail( userVector ){}
		    else{trail = false;}

	    }
	    */

	break;

	case 2:
	    graph.printAdjList();
	break;

	case -1:
	    cout << "Quitting, hope to see you again soon." << endl;
	    valid = false;
	break;

	default:
	    cout << "Invalid input" << endl;
	break;
	}
    }


    return 0;
}
