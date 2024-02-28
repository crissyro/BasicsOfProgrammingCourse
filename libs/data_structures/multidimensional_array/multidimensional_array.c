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

int getMinInArea(matrix m) {
    int start_row = 0;
    int start_col = 0;
    int end_row = 5;
    int end_col = 6;
    
    int min_value = m.values[start_row][start_col];
    
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_col; j <= end_col; j++) {
            if (m.values[i][j] < min_value) {
                min_value = m.values[i][j];
            }
        }
    }
    
    return min_value;
}

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++) {
        distance += a[i] * a[i];
    }

    return sqrt(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    for (int i = 1; i < m.nRows; i++) {
        int j = i;
        while (j > 0 && criteria(m.values[j - 1], m.nCols) > criteria(m.values[j], m.nCols)) {
            float *temp = m.values[j];
            m.values[j] = m.values[j - 1];
            m.values[j - 1] = temp;
            j--;
        }
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long a = *(long long *)pa;
    long long b = *(long long *)pb;
    return (a > b) - (a < b);
}

int countNUnique(long long *a, int n) {
    if (n <= 0) {
        return 0; 
    }

    int count = 1;

    qsort(a, n, sizeof(long long), cmp_long_long);

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            count++;
        }
    }

    return count;
}

int countEqClassesByRowsSum(matrix m) {
    if (m.nRows <= 0 || m.nCols <= 0) {
        return 0;
    }

    long long *row_sums = (long long *)malloc(m.nRows * sizeof(long long));

    for (int i = 0; i < m.nRows; i++) {
        row_sums[i] = 0;
        for (int j = 0; j < m.nCols; j++) {
            row_sums[i] += m.values[i][j];
        }
    }

    int unique_sums = countNUnique(row_sums, m.nRows);

    free(row_sums);

    return unique_sums;
}

int getNSpecialElement(matrix m) {
    int k = 0;

    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            int column_sum = 0;
            for (int q = 0; q < m.nRows; q++) {
                if (q != i) {
                    column_sum += m.values[q][j];
                }
            }

            if (m.values[i][j] > column_sum) {
                k++;
            }
        }
    }

    return k;
}

position getLeftMin(matrix m) {
    position pos;
    pos.rowIndex = -1;
    pos.colIndex = -1;
    int min_value = m.values[0][0];

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < min_value) {
                min_value = m.values[i][j];
                pos.rowIndex = i;
                pos.colIndex = j;
            }
        }
    }

    return pos;
}

void swapPenultimateRow(matrix m, int n) {
    position pos = getLeftMin(m);

    for (int i = 0; i < n; i++) {
        int temp = m.values[n - 2][i];
        m.values[n - 2][i] = m.values[i][pos.colIndex];
        m.values[i][pos.colIndex] = temp;
    }
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols)) {
            return false;
        }
    }

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; i++) {
        if (hasAllNonDescendingRows(ms[i])) {
            count++;
        }
    }

    return count;
}

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            count++;
        }
    }

    return count;
}

int countZeroRows(matrix m) {
    int count = 0;

    for (int i = 0; i < m.nRows; i++) {
        int count_zero = countValues(m.values[i], m.nCols, 0);
        if (count_zero == m.nCols) {
            count++;
        }
    }

    return count;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int max_zero_rows = 0;

    for (int i = 0; i < nMatrix; i++) {
        int zero_rows = countZeroRows(ms[i]);
        if (zero_rows > max_zero_rows) {
            max_zero_rows = zero_rows;
        }
    }

    for (int i = 0; i < nMatrix; i++) {
        if (countZeroRows(ms[i]) == max_zero_rows) {
            for (int row = 0; row < ms[i].nRows; row++) {
                for (int col = 0; col < ms[i].nCols; col++) {
                    printf("%d ", ms[i].values[row][col]);
                }

                printf("\n");
            }
            
            printf("\n");
        }
    }
}