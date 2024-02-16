#ifndef INC_MATRIX_H
#define INC_MATRIX_H

#include <stdio.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

//размещает в динамической памяти матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols) ;

//размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) ;

//освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix *m) ;

//освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices) ;

#endif