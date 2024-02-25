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

int getSum(int *row, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += row[i];
    }
    return sum;
}

int compareMatrices(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols) {
        return 0;
    }

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            if (m1.values[i][j] != m2.values[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

void test_sortRowsColumns() {
    matrix test_matrix = {3, 3, (int *[]){{30, 2, 3}, {4, 5, 6}, {7, 8, 9}}};

    insertionSortRowsMatrixByRowCriteria(test_matrix, &getSum);
    assert(compareMatrices(test_matrix, (matrix){3, 3, (int *[]){{4, 5, 6}, {7, 8, 9}, {30, 2, 3}}}));

    selectionSortColsMatrixByColCriteria(test_matrix, &getSum);
    assert(compareMatrices(test_matrix, (matrix){3, 3, (int *[]){{5, 6, 4}, {8, 9, 7}, {2, 3, 30}}}));

    freeMemMatrix(&test_matrix);
}

void test_areTwoMatricesEqual() {
    matrix m1 = {2, 2, (int *[]){{1, 2}, {3, 4}}};
    matrix m2 = {2, 2, (int *[]){{1, 2}, {3, 4}}};
    matrix m3 = {2, 2, (int *[]){{1, 2}, {3, 5}}};

    assert(areTwoMatricesEqual(&m1, &m2) == 1);
    assert(areTwoMatricesEqual(&m1, &m3) == 0);
}

void test_isEMatrix() {
    matrix m1 = {3, 3, (int *[]){{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
    matrix m2 = {3, 3, (int *[]){{1, 0, 0}, {0, 2, 0}, {0, 0, 1}}};

    assert(isEMatrix(&m1) == 1);
    assert(isEMatrix(&m2) == 0);
}

void test_isSymmetricMatrix() {
    matrix m1 = {3, 3, (int *[]){{1, 2, 3}, {2, 4, 5}, {3, 5, 6}}};
    matrix m2 = {3, 3, (int *[]){{1, 2, 3}, {2, 4, 2}, {3, 2, 1}}};

    assert(isSymmetricMatrix(&m1) == 1);
    assert(isSymmetricMatrix(&m2) == 0);
}

void test_transposeMatrix() {
    matrix m = {3, 2, (int *[]){{1, 2}, {3, 4}, {5, 6}}};
    transposeMatrix(&m);

    assert(m.nRows == 2);
    assert(m.nCols == 3);
    assert(m.values[0][0] == 1 && m.values[0][1] == 3 && m.values[0][2] == 5);
    assert(m.values[1][0] == 2 && m.values[1][1] == 4 && m.values[1][2] == 6);
}

void test_transposeSquareMatrix() {
    matrix m = {3, 3, (int *[]){{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    transposeSquareMatrix(&m);

    assert(m.nRows == 3);
    assert(m.nCols == 3);
    assert(m.values[0][0] == 1 && m.values[0][1] == 4 && m.values[0][2] == 7);
    assert(m.values[1][0] == 2 && m.values[1][1] == 5 && m.values[1][2] == 8);
    assert(m.values[2][0] == 3 && m.values[2][1] == 6 && m.values[2][2] == 9);
}

void test_MinMaxValuesPosition() {
    matrix m = {3, 3, (int *[]){{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};

    position min_position = getMinValuePos(m);
    assert(min_position.rowIndex == 0 && min_position.colIndex == 0);

    position max_position = getMaxValuePos(m);
    assert(max_position.rowIndex == 2 && max_position.colIndex == 2);
}

// пример использования функции createMatrixFromArray
// void test_countZeroRows() {
//     matrix m = createMatrixFromArray(
//         (int[]) {
//             1, 1, 0,
//             0, 0, 0,
//             0, 0, 1,
//             0, 0, 0,
//             0, 1, 1,
//         },
//         5, 3
//     );

//     assert(countZeroRows(m, 5, 3) == 2);

//     freeMemMatrix(&m);
// }

void test() {
    test_getMemMatrix() ;
    test_getMemArrayOfMatrices() ;
    // test_inputOutputMatrix() ;
    // test_inputOutputMatrices() ;
    test_swapRowsColumns() ;
    test_sortRowsColumns() ;
    test_areTwoMatricesEqual() ;
    test_isEMatrix() ;
    test_isSymmetricMatrix() ;
    test_transposeMatrix() ;
    test_transposeSquareMatrix() ;
    test_MinMaxValuesPosition() ;
}

int main() {
    test() ;

    return 0;
}