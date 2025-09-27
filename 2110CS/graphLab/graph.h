#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

using namespace std;

//public by default
struct Graph{

    //I could use lists but vectors are just better
    vector<vector<int>> adjList;
    vector<int> vertices;

    //there is no default constructor because there doesn't need to be one
    Graph(int size);

    //open/closed ends and begins on the same node
    //trail no vertex is repeated
    //path walk where no vertex is repeated
    //circuit closed trail
    //cycle closed path, no vertex is repeated besides the first and last

    void printAdjList();
    void initializeAdjList();

    //only need to check if it is open
    bool IsOpen( vector<int> nodeList );
    bool IsTrail( vector<int> nodeList );

};

#endif
