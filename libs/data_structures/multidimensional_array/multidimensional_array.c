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
    matrix a = getMemMatrix(m.nCols, m.nRows);

    for (int j = 0; j < m.nCols; j++) {
        for (int k = 0; k < m.nRows; k++) {
            a.values[j][k] = m.values[k][j];
        }
    }
        
    for(int i = 0; i < m.nCols-1; i++) {  
        int col1_min = getMin(a.values[i], m.nRows);
        int col2_min = getMin(a.values[i + 1], m.nRows);

        if ((col1_min >= col2_min) || (i == m.nCols-2 && col1_min < col2_min)) {
            swapColumns(m, i, i + 1);
        }
    }

    freeMemMatrix(&a);
}

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
        matrix square = mulMatrices(*m, *m);
        freeMemMatrix(m);
        *m = square;
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

    if (!isEMatrix(&result)) {
        freeMemMatrix(&result);
        return false;
    }

    freeMemMatrix(&result);

    return true;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int diagonal_count = m.nRows + m.nCols - 1;
    long long *max_values = (long long *)calloc(diagonal_count, sizeof(long long));
    
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int pseudodiagonal_index = i - j + (m.nCols - 1);
            max_values[pseudodiagonal_index] = max(max_values[pseudodiagonal_index], (long long)m.values[i][j]);
        }
    }
    
    long long sum = 0;
    for (int i = 0; i < diagonal_count; i++) {
        sum += max_values[i];
    }
    
    free(max_values);
    
    return sum;
}

int getMinInArea(matrix m) {
    int max_element = m.values[0][0];
    position max_pos;
    max_pos.rowIndex = 0;
    max_pos.colIndex = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > max_element) {
                max_element = m.values[i][j];
                max_pos.rowIndex = i;
                max_pos.colIndex = j;
            }
        }
    }

    int a[m.nRows * m.nCols];
    int a_index = 0;

    for (int i = max_pos.rowIndex; i >= 0; i--) {
        for (int j = max_pos.colIndex  - (max_pos.rowIndex - i); j <= max_pos.colIndex  + (max_pos.rowIndex - i); j++) {
            if (i >= 0 && j >= 0 && j < m.nCols) {
                a[a_index++] = m.values[i][j];
            }
        }
    }

    int min_element = a[0];

    for (int i = 1; i < a_index; i++) {
        if (a[i] < min_element) {
            min_element = a[i];
        }
    }

    return min_element;
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

    long long *row_sums = (long long *)calloc(m.nRows, sizeof(long long));

    for (int i = 0; i < m.nRows; i++) {
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
    pos.rowIndex = 0;
    pos.colIndex = 0;
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

    int a[n];

    for (int i = 0; i < n; i++) {
        a[i] = m.values[i][pos.colIndex];
    }

    for (int i = 0; i < n; i++) {
        m.values[n - 2][i] = a[i];
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
            outputMatrix(ms[i]);
            printf("\n");
        }
    }
}

int matrixNorm(matrix m) {
    int absolute_max = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int abs_value = abs(m.values[i][j]);
            if (abs_value > absolute_max) {
                absolute_max = abs_value;
            }
        }
    }

    return absolute_max;
}

void outputMatricesWithMinNorm(matrix *ms, int nMatrices) {
    int min_norm = matrixNorm(ms[0]);

    for (int i = 1; i < nMatrices; i++) {
        int norm = matrixNorm(ms[i]);
        if (norm < min_norm) {
            min_norm = norm;
        }
    }

    for (int i = 0; i < nMatrices; i++) {
        if (matrixNorm(ms[i]) == min_norm) {
            outputMatrix(ms[i]);
        }
    }
}

int min2(int a, int b) {
    return (a < b) ? a : b;
}

int getNSpecialElement2(matrix m) {
    int k = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int current_element = m.values[i][j];

            int left_check = 1;
            for (int k = 0; k < j; k++) {
                if (m.values[i][k] == current_element || min2(current_element, m.values[i][k]) == current_element) {
                    left_check = 0;
                    break;
                }
            }

            int right_check = 1;
            for (int k = j + 1; k < m.nCols; k++) {
                if (m.values[i][k] == current_element || min2(current_element, m.values[i][k]) == m.values[i][k]) {
                    right_check = 0;
                    break;
                }
            }

            if (left_check && right_check) {
                k++;
            }
        }
    }

    return k;
}

double getScalarProduct(int *a, int *b, int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }

    return result;
}

double getVectorLength(int *a, int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i] * a[i];
    }

    return sqrt(result);
}

double getCosine(int *a, int *b, int n) {
    double scalar_product = getScalarProduct(a, b, n);
    double length_a = getVectorLength(a, n);
    double length_b = getVectorLength(b, n);
    return scalar_product / (length_a * length_b);
}

int getVectorIndexWithMaxAngle(matrix m, int *b) {
    int max_angle_index = 0;
    double max_cosine = 1;

    for (int i = 0; i < m.nRows; i++) {
        double cosine = getCosine(m.values[i], b, m.nCols);
        if (cosine < max_cosine) {
            max_cosine = cosine;
            max_angle_index = i;
        }
    }

    return max_angle_index;
}

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    long long scalar_product = 0;

    for (int k = 0; k < m.nCols; k++) {
        scalar_product += m.values[i][k] * m.values[k][j];
    }

    return scalar_product;
}

long long getSpecialScalarProduct(matrix m, int n) {
    long long max_element = m.values[0][0];
    int max_row = 0;

    long long min_element = m.values[0][0];
    int min_col = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m.values[i][j] > max_element) {
                max_element = m.values[i][j];
                max_row = i;
            }

            if (m.values[i][j] < min_element) {
                min_element = m.values[i][j];
                min_col = j;
            }
        }
    }

    long long special_scalar_product = getScalarProductRowAndCol(m, max_row, min_col);

    return special_scalar_product;
}