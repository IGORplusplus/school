#ifndef LIN_TABLE_H
#define LIN_TABLE_H

#include <vector>
#include <iostream>

using namespace std;

struct linHash{

    vector<int> hashTable;
    int capacity;

    linHash(int size) : capacity(size), hashTable(size, -1) {}

    //HASH FUNCTION VERY IMPORTANT
    int hashFunction(int key) {
	return key % capacity; 
    }

    int linearProbing(int key, int index) {
        while (hashTable[index] != -1 && hashTable[index] != key) {
            index = (index + 1) % capacity;  
        }
        return index;
    }

    
    void insertLin(int key){
	int index = hashFunction(key);
	index = linearProbing(key, index);

	if (hashTable[index] == -1){
	    hashTable[index] = key;
	    cout << "Inserted correctly" << endl;
	}
	else {
	    cout << "Insertion failed because the table is full" << endl;
	}
    }

    void searchLin(int key){
	int index = hashFunction(key);
	index = linearProbing(key, index);

	if ( hashTable[index] != -1){
	    cout << "Element was found." << endl;
	}
	else { cout << "Element was not found." << endl;}
    }



    void removeLin(int key){
	int index = hashFunction(key);
	index = linearProbing(key, index);

	if ( hashTable[index] != -1) {
	    hashTable[index] = -1;
	    cout << "Element was deleted." << endl;
	}
	else {
	    cout << "Element not found." << endl;
	}

    }


    void printLin(){
	cout << endl;
	for (int i=0; i < capacity; i++){
	    cout << hashTable[i] << endl;
	}
    }


};


#endif
