#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.c"
// #include "libs/data_structures/multidimensional_array/multidimensional_array.c"


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

void test_sortColsByMinElement() {
    matrix m1 = createMatrixFromArray(
        (int[]) {
            3, 5, 2, 4, 3, 3,
            2, 5, 1, 8, 2, 7,
            6, 1, 4, 4, 8, 3,
        },
        3, 6
    );

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
        (int[]) {
            5, 2, 3, 3, 3, 4,
            5, 1, 2, 2, 7, 8,
            1, 4, 6, 8, 3, 4,
        },
        3, 6
    );

    matrix m3 = createMatrixFromArray(
        (int[]) {
            3, 5, 2, 4, 3, 3,
            2, 5, 1, 8, 2, 7,
            6, 1, 4, 4, 8, 3,
        },
        3, 6
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
    test_sortColsByMinElement() ;
}

int main() {
    test();

    return 0;
}