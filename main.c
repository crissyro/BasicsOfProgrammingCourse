#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.c"
// #include "libs/data_structures/multidimensional_array/multidimensional_array.c"

void swapMinMaxRows(matrix m) {
    position min_position = getMinValuePos(m);
    position max_position = getMaxValuePos(m);

    swapRows(m, min_position.rowIndex, max_position.rowIndex);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    
    return max;
}

void sortRowsByMaxElement(matrix m) {
    for (int i = 0; i < m.nRows - 1; i++) {
        for (int j = 0; j < m.nRows - i - 1; j++) {
            if (getMax(m.values[j], m.nCols) > getMax(m.values[j + 1], m.nCols)) {
                swapRows(m, j, j + 1);
            }
        }
    }
}

void test_swapMinMaxRows() {
    matrix m1 = createMatrixFromArray(
        (int[]) {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9,
        },
        3, 3
    );

    swapMinMaxRows(m1);

    matrix m2 = createMatrixFromArray(
        (int[]) {
            7, 8, 9,
            4, 5, 6,
            1, 2, 3,
        },
        3, 3
    );

    assert(areTwoMatricesEqual(&m1, &m2) == true);

    freeMemMatrix(&m1);
}

void test_sortRowsByMaxElement() {
    matrix m1 = createMatrixFromArray(
        (int[]) {
            7, 1, 2,
            1, 8, 1,
            3, 2, 3,
        },
        3, 3
    );

    sortRowsByMaxElement(m1);

    matrix m2 = createMatrixFromArray(
        (int[]) {
            3, 2, 3,
            7, 1, 2,
            1, 8, 1,
        },
        3, 3
    );

    matrix m3 = createMatrixFromArray(
        (int[]) {
            7, 1, 2,
            1, 8, 1,
            3, 2, 3,
        },
        3, 3
    );

    assert(areTwoMatricesEqual(&m1, &m2) == true);
    assert(areTwoMatricesEqual(&m1, &m3) == false);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
}

void test() {
    test_swapMinMaxRows() ;
    test_sortRowsByMaxElement() ;
}

int main() {
    test();

    return 0;
}