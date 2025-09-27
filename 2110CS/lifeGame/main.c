#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
   bool is_alive;
} Cell;


void printCells(Cell* cells, int rows, int cols){
    for(int i=0; i<rows;i++){
	for(int j=0; j<cols;j++){
	    int idx = i * cols * j;
	    printf("%c", cells[idx].is_alive ? 'O' : '.');
	}
	printf("\n");
    }
}


int main(int argc, char* argv[]){

    printf("Welcome to the game of life\n");
    printf("How many rows and how many columns do you want?\n");

    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);

    Cell* cells = malloc(rows * cols * sizeof(Cell));

    if(!cells){
	printf("Allocation did not work");
	return 1;
    }

    if (rows > 1 && cols > 1)
	cells[1 * cols + 1].is_alive = true;

    printCells(cells, rows, cols);

    free(cells);

    return 0;
}
