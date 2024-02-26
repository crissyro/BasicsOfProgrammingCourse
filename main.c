#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/multidimensional_array/multidimensional_array.c"

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

void test_mulMatrices() {
    matrix m1 = createMatrixFromArray(
        (int[]) {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
        },
        3, 3
    );

    matrix m2 = createMatrixFromArray(
        (int[]) {
            9, 8, 7,
            6, 5, 4,
            3, 2, 1
        },
        3, 3
    );

    matrix expected_result = createMatrixFromArray(
        (int[]) {
            30, 24, 18,
            84, 69, 54,
            138, 114, 90
        },
        3, 3
    );

    matrix result = mulMatrices(m1, m2);

    assert(areTwoMatricesEqual(&result, &expected_result) == true);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&expected_result);
}

void test_getSquareOfMatrixIfSymmetric() {
    matrix symmetric_matrix = createMatrixFromArray(
        (int[]) {
            1, 2, 3,
            2, 4, 5,
            3, 5, 6
        },
        3, 3
    );

    matrix expected_result = createMatrixFromArray(
        (int[]) {
            14, 25, 31,
            25, 45, 56,
            31, 56, 70
        },
        3, 3
    );

    getSquareOfMatrixIfSymmetric(&symmetric_matrix);

    assert(areTwoMatricesEqual(&symmetric_matrix, &expected_result) == true);

    freeMemMatrix(&symmetric_matrix);
    freeMemMatrix(&expected_result);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    matrix input_matrix = createMatrixFromArray(
        (int[]) {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
        },
        3, 3
    );

    matrix expected_result = createMatrixFromArray(
        (int[]) {
            1, 4, 7,
            2, 5, 8,
            3, 6, 9
        },
        3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(input_matrix);

    assert(areTwoMatricesEqual(&input_matrix, &expected_result) == true);

    freeMemMatrix(&input_matrix);
    freeMemMatrix(&expected_result);
}

void test_isMutuallyInverseMatrices() {
    matrix m1 = createMatrixFromArray(
        (int[]) {
            1, 2,
            3, 4
        },
        2, 2
    );

    matrix m2 = createMatrixFromArray(
        (int[]) {
            1, 2,
            3, 5
        },
        2, 2
    );

    assert(isMutuallyInverseMatrices(m1, m2) == false);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m = createMatrixFromArray(
        (int[]) {
            3, 2, 5, 4,
            1, 3, 6, 3,
            3, 2, 1, 2
        },
        3, 4
    );

    long long result = findSumOfMaxesOfPseudoDiagonal(m);

    assert(result == 23);

    freeMemMatrix(&m);
}

void test_getMinInArea() {
    matrix m = createMatrixFromArray(
        (int[]) {
            3, 2, 5, 4, 9, 9,
            1, 3, 6, 3, 9, 9,
            3, 2, 1, 2, 9, 9,
            3, 2, 5, 4, 9, 9,
            1, 3, 6, 0, 9, 9,
            3, 2, 1, 2, 9, 9,
        },
        3, 4
    );
    
    int expected_result = 0; 
    
    int result = getMinInArea(m);

    assert(result == expected_result);

    freeMemMatrix(&m);
}

void test() {
    test_swapMinMaxRows() ;
    test_sortRowsByMaxElement() ;
    test_sortColsByMinElement() ;
    test_mulMatrices() ;
    test_getSquareOfMatrixIfSymmetric() ;
    test_transposeIfMatrixHasNotEqualSumOfRows() ;
    test_isMutuallyInverseMatrices() ;
    test_findSumOfMaxesOfPseudoDiagonal() ;
    test_getMinInArea() ;
}

int main() {
    test();

    return 0;
}