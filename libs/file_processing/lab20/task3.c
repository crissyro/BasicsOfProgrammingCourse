#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/matrix/matrix.c"

#define WINDOW_SIZE 9

void medianFilter(matrix *image) {
    matrix filtered_image = copyMatrix(image);

    int window[WINDOW_SIZE];

    for (int i = 1; i < image->nRows - 1; i++) {
        for (int j = 1; j < image->nCols - 1; j++) {
            int k = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    window[k++] = image->values[i + x][j + y];
                }
            }

            for (int m = 0; m < WINDOW_SIZE; m++) {
                for (int n = m + 1; n < WINDOW_SIZE; n++) {
                    if (window[n] < window[m]) {
                        int temp = window[m];
                        window[m] = window[n];
                        window[n] = temp;
                    }
                }
            }

            filtered_image.values[i][j] = window[WINDOW_SIZE / 2];
        }
    }

    freeMemMatrix(image);

    *image = filtered_image;
}

void test_medianFilter() {
    matrix image = createMatrixFromArray(
        (int[]){
            10, 20, 30,
            25, 35, 45,
            15, 25, 35
        },
        3, 3
    );

    medianFilter(&image);

    matrix expected_result = createMatrixFromArray(
        (int[]) {
            10, 20, 30,
            25, 25, 45,
            15, 25, 35
        },
        3, 3
    );

    assert(areTwoMatricesEqual(&image, &expected_result) == true);

    freeMemMatrix(&image);
    freeMemMatrix(&expected_result);
}

int main() {
    test_medianFilter();
    
    return 0;
}