#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "multidimensional_array.h"

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

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);

    matrix result = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            result.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                result.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }

    return result;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(m)) {
        matrix squared = mulMatrices(*m, *m);
        freeMemMatrix(m);
        *m = squared;
    }
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                return false; 
            }
        }
    }

    return true;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sum[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        sum[i] = getSum(m.values[i], m.nCols);
    }

    if (isUnique(sum, m.nRows)) {
        transposeMatrix(&m);
    }
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if ((m1.nCols != m2.nCols) || (m1.nRows != m2.nRows)){
        return false;
    }

    matrix result = mulMatrices(m1, m2);

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            if ((i == j && result.values[i][j] != 1) || (i != j && result.values[i][j] != 0)) {
                freeMemMatrix(&result);
                return false;
            }
        }
    }

    freeMemMatrix(&result);

    return true;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int diagonal_count = m.nRows + m.nCols - 1;
    long long *max_values = (long long *)malloc(diagonal_count * sizeof(long long));
    
    for (int i = 0; i < diagonal_count; ++i) {
        max_values[i] = 0;
    }
    
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            int pseudoDiagonalIndex = i - j + (m.nCols - 1);
            max_values[pseudoDiagonalIndex] = max(max_values[pseudoDiagonalIndex], (long long)m.values[i][j]);
        }
    }
    
    long long sum = 0;
    for (int i = 0; i < diagonal_count; ++i) {
        sum += max_values[i];
    }
    
    free(max_values);
    
    return sum;
}