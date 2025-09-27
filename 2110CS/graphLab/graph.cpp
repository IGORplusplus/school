#include "graph.h"


    Graph::Graph(int size){
	for(int i=0;i<size;i++){
	    vertices.push_back(i);
	    adjList.push_back(vector<int>());
	}

    }

    void Graph::printAdjList(){
    for(int i=0; i<vertices.size(); i++){
	cout << i << ": ";

	for(int j=0; j<adjList[i].size(); j++){
	    cout << adjList[i][j] << " ";
	}
	cout << endl;
    }
    }


    void Graph::initializeAdjList(){

	int adjInput = 0;
	for(int i=0; i<vertices.size();i++){
	    cout << "Enter in the adjacency list for the " << i << "th vertex" << endl;
	    cout << "Enter -1 to stop inputting in values" << endl;
	    while(true){
		cin >> adjInput;
		if(adjInput == -1) break;
		adjList[i].push_back(adjInput);
	    }

	}
    }
    //these are extra credit functions
    //and are unimplemented

    /*
    bool Graph::IsOpen( vector<int> nodeList );
    bool Graph::IsTrail( vector<int> nodeList );
    */

