#ifndef INC_MULTIDIMENSIONAL_ARRAY_H
#define INC_MULTIDIMENSIONAL_ARRAY_H

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

// Дана квадратная матрица, все элементы которой различны.
// Функция менять местами строки, в которых находятся максимальный и минимальный элементы.
void swapMinMaxRows(matrix m) ;

// Ищет максимальный элемент в строке a размера n
int getMax(int *a, int n) ;

// Упорядочивает строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix m) ;

#endif