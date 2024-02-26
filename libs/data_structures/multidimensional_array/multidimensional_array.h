#ifndef INC_MULTIDIMENSIONAL_ARRAY_H
#define INC_MULTIDIMENSIONAL_ARRAY_H

#include <stdio.h>
// #include "/../../../libs/data_structures/matrix/matrix.c"
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/matrix/matrix.c"

// Дана квадратная матрица, все элементы которой различны.
// Функция менять местами строки, в которых находятся максимальный и минимальный элементы.
void swapMinMaxRows(matrix m) ;

// Ищет максимальный элемент в строке a размера n
int getMax(int *a, int n) ;

// Упорядочивает строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix m) ;

// Ищет минимальный элемент в строке a размера n
int getMin(int *a, int n) ;

// Упорядочивает столбцы матрицы по неубыванию наименьших элементов столбцов
void sortColsByMinElement(matrix m) ;

// Умножает матрицы m1 и m2
matrix mulMatrices(matrix m1, matrix m2) ;

// Проверяет, является ли матрица симметричной, и в случае положительного результата заменять ее квадратом
void getSquareOfMatrixIfSymmetric(matrix *m) ;

// Проверяет, все ли элементы в массиве уникальны
bool isUnique(long long *a, int n) ;

// Возвращает сумму элементов в массиве
long long getSum(int *a, int n) ;

// Выполняет проверки сумм строк и вызывает транспонирование, если все суммы строк различны
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) ;

// Проверяет, являются ли две квадратные матрицы взаимно обратными
bool isMutuallyInverseMatrices(matrix m1, matrix m2) ;

// Находит максимальное значение из a и b
int max(int a, int b) ;

// Находит сумму максимальных элементов всех псевдодиагоналей данной матрицы
long long findSumOfMaxesOfPseudoDiagonal(matrix m) ;

#endif