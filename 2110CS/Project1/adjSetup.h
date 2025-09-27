#ifndef ADJ_SETUP
#define ADJ_SETUP
#include "cell.h"


//this may not be the most important function because I believe I already implemented this

void SetAdjacencies(vector<vector<Cell>> cells, int mxr, int mxc){
    int rows = mxr;
    int cols = mxc;

    for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
        if (i > 0 && j > 0){
            cells[i][j].SetAdjTL(&cells[i - 1][j - 1]);
	    }
        else{
            cells[i][j].SetAdjTL(nullptr);
	}

        if (i >0){
            cells[i][j].SetAdjT(&cells[i - 1][j]);}
        else{
            cells[i][j].SetAdjT(nullptr);
	}
        if (i> 0 &&j < cols - 1){
            cells[i][j].SetAdjTR(&cells[i - 1][j + 1]);
	    }
        else{
            cells[i][j].SetAdjTR(nullptr);
	    }

        if (j> 0){
            cells[i][j].SetAdjL(&cells[i][j - 1]);}
        else{
            cells[i][j].SetAdjL(nullptr);}

        if (j< cols - 1){
            cells[i][j].SetAdjR(&cells[i][j + 1]);}
        else{
            cells[i][j].SetAdjR(nullptr);}

        if (i< rows - 1 && j > 0){
            cells[i][j].SetAdjBL(&cells[i + 1][j - 1]);}
        else{
            cells[i][j].SetAdjBL(nullptr);}

        if (i< rows - 1){
            cells[i][j].SetAdjB(&cells[i + 1][j]);}
        else{
            cells[i][j].SetAdjB(nullptr);}

        if (i <rows - 1 && j < cols - 1){
            cells[i][j].SetAdjBR(&cells[i + 1][j + 1]);}
        else{
            cells[i][j].SetAdjBR(nullptr);}
    }
}
}

#endif
