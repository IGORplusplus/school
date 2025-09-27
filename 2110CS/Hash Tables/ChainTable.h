#ifndef CHAIN_TABLE_H
#define CHAIN_TABLE_H

#include <vector>
#include <list>
#include <iostream>

using namespace std;

//c++ struct so just a class but its default is public
//more efficient to work with because I am prone to making 
//a ton of useless setters and getters
struct chainHash {

    vector<list<int>> hashTable;
    int capacity;

    //HASH FUNCTION VERY IMPORTANT
    int hashFunction(int key) {
	return key % capacity; 
    }
    
    chainHash(int size) : capacity(size) {
	hashTable.resize(capacity);
    }
    
    void insertChain(int key){
	int index = hashFunction(key);
	hashTable[index].push_back(key);
    }

    void searchChain(int key){
	int index = hashFunction(key);
	for(int element : hashTable[index]){
	    if(element == key) {
		cout << "Element found: " << key << endl;
	    return;
	    }
	cout << "Element not found:\n" << "Better luck next time ;)\n";
	}
    }


    void removeChain(int key){
	int index = hashFunction(key);
	
	for(auto it = hashTable[index].begin(); it != hashTable[index].end(); it++){
	    if(*it == key){ 
		hashTable[index].erase(it);
		cout << "Element deleted: " << key << endl;
		return;
	    }
	}
	cout << "Element not found:\n" << "Better luck next time ;)\n";
    }


   void printChain(){
	for(int i=0; i<capacity; i++){
		cout << "Bucket " << i << ": ";
	    for(int element : hashTable[i]){
			cout << element << " --> ";
	    }
		cout << "NULL" << endl; 
	}
    }
};


#endif
