#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "libs/data_structures/multidimensional_array/multidimensional_array.c"

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

    assert(areTwoMatricesEqual(&m1, &m2) == 0);
}

void test() {
    test_swapMinMaxRows() ;
}

int main() {
    test();

    return 0;
}