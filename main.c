#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/multidimensional_array/multidimensional_array.c"

void test_getMinInArea() {
    matrix m = createMatrixFromArray(
        (int[]) {
            3, 2, 5, 4, 9, 9,
            7, 3, 6, 6, 9, 9,
            3, 7, 5, 7, 9, 9,
            3, 2, 5, 6, 9, 9,
            1, 3, 6, 12, 9, 9,
        },
        5, 6
    );
    
    int expected_result = 2; 
    
    int result = getMinInArea(m);

    assert(result == expected_result);

    freeMemMatrix(&m);
}

void test() {
    test_getMinInArea() ;
}

int main() {
    test();

    return 0;
}