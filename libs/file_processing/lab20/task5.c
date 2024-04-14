#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/matrix/matrix.c"

int countSubmatricesWithOnes(matrix *m) {
    matrix nums = getMemMatrix(m->nRows, m->nCols);
    int count = 0;

    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            if (m->values[i][j] == 1) {
                if (j == 0) {
                    nums.values[i][j] = 1;
                } else {
                    nums.values[i][j] = nums.values[i][j - 1] + 1;
                }
            } else {
                nums.values[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            int minWidth = nums.values[i][j];
            for (int k = i; k < m->nRows; k++) {
                if (minWidth == 0) {
                    minWidth = 0;
                } else if (minWidth >= nums.values[k][j]) {
                    minWidth = nums.values[k][j];
                }
                count += minWidth;
            }
        }
    }

    freeMemMatrix(&nums);

    return count;
}

void test_countSubmatricesWithOnes() {
    matrix matrix = createMatrixFromArray(
        (int[]){
            1, 0, 1,
            1, 1, 0,
            1, 1, 0,
        }, 
        3, 3
    );

    int result = countSubmatricesWithOnes(&matrix);

    assert(result == 13);

    freeMemMatrix(&matrix);
}

int main() {
    test_countSubmatricesWithOnes() ;
    
    return 0;
}