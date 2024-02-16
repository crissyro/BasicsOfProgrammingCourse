#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.c"

void test_getMemMatrix() {
    int nRows = 3;
    int nCols = 4;

    matrix test_matrix = getMemMatrix(nRows, nCols);

    assert(test_matrix.nRows == 3);
    assert(test_matrix.nCols == 4);

    freeMemMatrix(&test_matrix);
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


void test_inputOutputMatrix() {
    matrix test_matrix;

    printf("Enter matrix:\n");
    inputMatrix(&test_matrix);

    printf("Entered matrix:\n");
    outputMatrix(test_matrix);

    freeMemMatrix(&test_matrix);
}

void test_inputOutputMatrices() {
    int nMatrices = 2;
    matrix matrices[nMatrices];

    printf("Enter %d matrices:\n", nMatrices);
    inputMatrices(matrices, nMatrices);

    printf("Entered matrices:\n");
    outputMatrices(matrices, nMatrices);

    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&matrices[i]);
    }
}

void test_swapRowsColumns() {
    matrix test_matrix = {3, 3, (int *[]){{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};

    swapRows(test_matrix, 0, 2);
    assert(test_matrix.values[0][0] == 7 && test_matrix.values[2][0] == 1);

    swapColumns(test_matrix, 0, 2);
    assert(test_matrix.values[0][0] == 3 && test_matrix.values[0][2] == 1);
}

void test() {
    test_getMemMatrix() ;
    test_getMemArrayOfMatrices() ;
    test_inputOutputMatrix() ;
    test_inputOutputMatrices() ;
    test_swapRowsColumns() ;
}

int main() {
    test() ;

    return 0;
}