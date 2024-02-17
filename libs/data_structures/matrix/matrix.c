#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
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
    int *criteriaValues = (int *) malloc(m.nCols * sizeof(int));
    if (criteriaValues == NULL) {
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

        criteriaValues[j] = criteria(temp_column, m.nRows);
    }

    free(temp_column);

    for (int i = 0; i < m.nCols - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m.nCols; j++) {
            if (criteriaValues[j] < criteriaValues[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swapColumns(m, i, minIndex);
            int temp = criteriaValues[i];
            criteriaValues[i] = criteriaValues[minIndex];
            criteriaValues[minIndex] = temp;
        }
    }

    free(criteriaValues);
}

bool isSquareMatrix(matrix *m) { 
    return m->nRows == m->nCols; 
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    return memcmp(m1->values, m2->values, m1->nRows * m1->nCols * sizeof(int)) == 0;
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