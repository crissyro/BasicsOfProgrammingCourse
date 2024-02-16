#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.c"

void test_getMemMatrix() {
    int nRows = 3;
    int nCols = 4;

    matrix matrix = getMemMatrix(nRows, nCols);

    assert(matrix.nRows == 3);
    assert(matrix.nCols == 4);

    freeMemMatrix(&matrix);
}

void test_getMemArrayOfMatrices() {
    int nMatrices = 2;
    int nRows = 3;
    int nCols = 4;

    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].nRows == nRows && ms[i].nCols == nCols);
    }

    freeMemMatrices(ms, nMatrices);
}

void test() {
    test_getMemMatrix() ;
    test_getMemArrayOfMatrices() ;
}

int main() {
    test() ;

    return 0;
}