#ifndef LIN_HASH_H
#define LIN_HASH_H

#include <vector>
#include <iostream>

using namespace std;

struct linHash{

    vector<ints> hashTable;
    int capacity;

    linHash(int size){
	capacity = size;
	hashTable(size, -1);
    }

    int hashFunction(int key){
    return key % capacity;
    }

    linearProbing(int key, int index){
	while(hashTable[index] != -1 && hashTable[index] != key){
	    index = (index + 1) % capacity;
	    return index;
	}
    }

    void insertLin(int key){

    int index = hashFunction(key);
    index = linearProbing(key, index);

    if(hashTable[index] == -1){
	hashTable[index] = key;
	cout << "Inserted correctly" << endl;
    }
    else{
    cout << "Insertion failed"
    }
    }


    void searchLin(int key) {
	int index = hashFunction(key);
	index = linearProbing(key, index);

	if(hashTable[index] != -1){
	    cout << "Element was found" << endl << endl;
	}

	else{ cout << "Element was not found" << endl << endl;
	}
    }

    void removeLin(int key){
	int index = hashFunction(key);
	index = linearProbing(key, index);
	if(hashTable[index] != -1){
	    hashTable[index] = -1;
	    cout << "Element was deleted" << endl;
	}
	else{
	    cout << "Element was not found" << endl;
	}
    }

    void printLin(){
	cout << endl;
	for(int i=0; i< capacity; i++){
	    cout << hashTable[i];
	}
    }

};

#endif
