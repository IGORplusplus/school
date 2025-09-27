#include <iostream>
#include "ChainTable.h"
#include "LinTable.h"

//can't ecide between the two just yet

using namespace std;


//unnecessary to create a separate file for this function
void printMenu(){

    cout << "1. insert" << endl;
    cout << "2. remove" << endl;
    cout << "3. search" << endl;
    cout << "4. quit" << endl << endl;

}


int main(){

    cout << "1. Implement Chaining" << endl;
    cout << "2. Implement Probing" << endl;
    int option;
    cin >> option;
    if(option != 1 && option != 2){
	while(option != 1 && option != 2){
	cout << "1. Implement Chaining" << endl;
	cout << "2. Implement Probing" << endl;
	cin >> option;
	}
    }
    
    bool chaining = true;
    bool probing = true;
    int size = 13;
    linHash linMap(size);
    chainHash chainMap(size);

    if(option == 1){ cout << "Chaining" << endl; probing = false;}
    else if(option == 2){ cout << "Probing" << endl; chaining = false; }

    while(chaining){
    printMenu();
    cin >> option;
	switch(option){
	    case 1:
		int addKey;		
		cout << "Enter in the key to insert" << endl;
		cin >> addKey;
		chainMap.insertChain(addKey);	
		chainMap.printChain();
		break;
	    case 2:
		int deleteKey;		
		cout << "Enter in the key to remove" << endl;
		cin >> deleteKey;
		chainMap.removeChain(deleteKey);
		chainMap.printChain();
		break;
	    case 3:
		int find;
		cout << "Enter in the key to find" << endl;
		cin >> find;	
		chainMap.searchChain(find);
		chainMap.printChain();
		break;
	    case 4:
		chaining = false;
		chainMap.printChain();
		cout << "QUITTING" << endl;
		break;
	    default:
		cout << "Invalid option" << endl;
		chainMap.printChain();
	}
    }

    while(probing){
	printMenu();
	cin >> option;
	switch(option){
	    case 1:
		int addKey;		
		cout << "Enter in the key to insert" << endl;
		cin >> addKey;
		linMap.insertLin(addKey);	
		linMap.printLin();
		break;
	    case 2:
		int deleteKey;		
		cout << "Enter in the key to remove" << endl;
		cin >> deleteKey;
		linMap.removeLin(deleteKey);
		linMap.printLin();
		break;
	    case 3:
		int find;
		cout << "Enter in the key to find" << endl;
		cin >> find;	
		linMap.searchLin(find);
		linMap.printLin();
		break;
	    case 4:
		probing = false;
		linMap.printLin();
		cout << "QUITTING" << endl;
		break;
	    default:
		cout << "Invalid option" << endl;
		linMap.printLin();
	}

    }

    return 0;
}
