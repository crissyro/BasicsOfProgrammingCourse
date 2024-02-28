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

// Найти минимальный элемент матрицы в выделенной области
int getMinInArea(matrix m) ;

// Вычисляет расстояние до начала координат для одной точки в m-мерном пространстве
float getDistance(int *a, int n) ;

// Cортировка строк матрицы по заданному критерию
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) ;

// Сортировка точек в матрице по их расстояниям до начала координат
void sortByDistances(matrix m) ;

// Функция сравнения для быстрой сортировки
int cmp_long_long(const void *pa, const void *pb) ;

// Подсчитывает количество уникальных элементов в массиве
int countNUnique(long long *a, int n) ;

// Подсчитывает количество классов эквивалентных строк по их суммам
int countEqClassesByRowsSum(matrix m) ;

// Определяет k - количество "особых" элементов матрицы, считая элемент "особым", 
// если он больше суммы остальных элементов своего столбца
int getNSpecialElement(matrix m) ;

// Ищет позицию первого минимального значения
position getLeftMin(matrix m) ;

// Заменяет предпоследнюю строку матрицы первым из столбцов, 
// в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix m, int n) ;

// Проверяет, отсортирован ли каждый ряд в матрице по неубыванию
bool isNonDescendingSorted(int *a, int n) ;

// Проверяет, что все строки матрицы упорядочены по неубыванию
bool hasAllNonDescendingRows(matrix m) ;

// Считает количество матриц в массиве, в которых все строки упорядочены по неубыванию
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) ;

// Подсчитывает количество определенных значений в массиве
int countValues(const int *a, int n, int value) ;

// Подсчитывает количество строк с нулями в матрице
int countZeroRows(matrix m) ;

// Выводит матрицы с наибольшим количеством строк, содержащих нули
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) ;

#endif