#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/matrix/matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }

    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++) {
        ms[i] = getMemMatrix(nRows, nCols);
    }

    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        free(m->values[i]);
    }

    free(m);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
    }

    free(ms);
}

void inputMatrix(matrix *m) {
    scanf("%d %d", &m->nRows, &m->nCols);

    m->values = (int **)malloc(m->nRows * sizeof(int *));

    for (int i = 0; i < m->nRows; i++) {
        m->values[i] = (int *)malloc(m->nCols * sizeof(int));
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &m->values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(&ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }

        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    assert(i1 >= 0 && i1 < m.nRows && i2 >= 0 && i2 < m.nRows);

    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void swapColumns(matrix m, int j1, int j2) {
    assert(j1 >= 0 && j1 < m.nCols && j2 >= 0 && j2 < m.nCols);

    for (int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = temp;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int*, int)) {
    int *criteria_values = malloc(m.nRows * sizeof(int));
    if (criteria_values == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < m.nRows; i++) {
        criteria_values[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 1; i < m.nRows; i++) {
        int key = criteria_values[i];
        int *key_row = m.values[i];
        int j = i - 1;

        while (j >= 0 && criteria_values[j] > key) {
            criteria_values[j + 1] = criteria_values[j];
            swapRows(m, j + 1, j);
            j = j - 1;
        }

        criteria_values[j + 1] = key;
        m.values[j + 1] = key_row;
    }

    free(criteria_values);
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int*, int)) {
    int *criteria_values = (int *) malloc(m.nCols * sizeof(int));
    if (criteria_values == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int *temp_column = (int *) malloc(m.nRows * sizeof(int));
    if (temp_column == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            temp_column[i] = m.values[i][j];
        }

        criteria_values[j] = criteria(temp_column, m.nRows);
    }

    free(temp_column);

    for (int i = 0; i < m.nCols - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < m.nCols; j++) {
            if (criteria_values[j] < criteria_values[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swapColumns(m, i, min_index);
            int temp = criteria_values[i];
            criteria_values[i] = criteria_values[min_index];
            criteria_values[min_index] = temp;
        }
    }

    free(criteria_values);
}

bool isSquareMatrix(matrix *m) { 
    return m->nRows == m->nCols; 
}

// bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
//     return memcmp(m1->values, m2->values, m1->nRows * m1->nCols * sizeof(int)) == 0;
// }

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    if (m1->nRows != m2->nRows || m1->nCols != m2->nCols) {
        return false;
    }

    for (int i = 0; i < m1->nRows; i++) {
        for (int j = 0; j < m1->nCols; j++) {
            if (m1->values[i][j] != m2->values[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

bool isEMatrix(matrix *m) {
    if (!isSquareMatrix(m)) {
        return false;
    }

    for (int i = 0; i < m->nRows; i++) {
        if (m->values[i][i] != 1) {
            return false;
        }

        for (int j = 0; j < m->nCols; j++) {
            if (i != j && m->values[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool isSymmetricMatrix(matrix *m) {
    if (!isSquareMatrix(m)) {
        return false;
    }

    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < i; j++) {
            if (m->values[i][j] != m->values[j][i]) {
                return false;
            }
        }
    }

    return true;
}

void transposeSquareMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = i + 1; j < m->nCols; j++) {
            int temp = m->values[i][j];
            m->values[i][j] = m->values[j][i];
            m->values[j][i] = temp;
        }
    }
}

void transposeMatrix(matrix *m) {
    int temp = m->nRows;
    m->nRows = m->nCols;
    m->nCols = temp;

    for (int i = 0; i < m->nRows; i++) {
        for (int j = i + 1; j < m->nCols; j++) {
            int temp = m->values[i][j];
            m->values[i][j] = m->values[j][i];
            m->values[j][i] = temp;
        }
    }
}

position getMinValuePos(matrix m) {
    int min = m.values[0][0];
    position min_position = {0, 0};

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                min_position.rowIndex = i;
                min_position.colIndex = j;
            }
        }
    }

    return min_position;
}

position getMaxValuePos(matrix m) {
    int max = m.values[0][0];
    position max_position = {0, 0};

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > max) {
                max = m.values[i][j];
                max_position.rowIndex = i;
                max_position.colIndex = j;
            }
        }
    }

    return max_position;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
                
    return ms;
}