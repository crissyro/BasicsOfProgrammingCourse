#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/multidimensional_array/multidimensional_array.c"

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

    outputMatrix(m1);


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
    test_sortColsByMinElement() ;
}

int main() {
    test();

    return 0;
}