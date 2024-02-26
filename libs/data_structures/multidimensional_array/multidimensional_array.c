#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "multidimensional_array.h"
#include "libs/data_structures/matrix/matrix.c"

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

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    return min;
}

void sortColsByMinElement(matrix m) {
    for (int i = 0; i < m.nCols - 1; i++) {
        for (int j = 0; j < m.nCols - i - 1; j++) {
            int col1_min = getMin(m.values[j], m.nRows);
            int col2_min = getMin(m.values[j + 1], m.nRows);
            if (col1_min > col2_min) {
                swapColumns(m, j, j + 1);
            }
        }
    }
}

// void sortColsByMinElement(matrix m) {
//     int min_values[m.nCols];
    
//     for (int j = 0; j < m.nCols; j++) {
//         min_values[j] = getMin(m.values[j], m.nRows);
//     }

//     for (int i = 0; i < m.nCols - 1; i++) {
//         for (int j = 0; j < m.nCols - i - 1; j++) {
//             if (min_values[j] > min_values[j + 1]) {
//                 int tempMin = min_values[j];
//                 min_values[j] = min_values[j + 1];
//                 min_values[j + 1] = tempMin;
//                 swapCols(m, j, j + 1);
//             }
//         }
//     }
// }