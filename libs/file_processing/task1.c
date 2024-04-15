#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/matrix/matrix.c"

#define MAX_SIZE 10
#define MAX_ELEMENT 100

FILE *openFile(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }
    
    return file;
}

void generateRandomMatrix(FILE *file) {
    int orderMatrix = rand() % MAX_SIZE + 1;

    fprintf(file, "%d\n", orderMatrix);
    srand(time(NULL));

    for (int i = 0; i < orderMatrix; i++) {
        for (int j = 0; j < orderMatrix; j++) {
            int matrixElement = rand() % (2 * MAX_ELEMENT + 1) - MAX_ELEMENT;
            fprintf(file, "%d ", matrixElement);
        }
        fprintf(file, "\n");
    }
}

void generateMultipleMatrices(FILE *file, int numberOfMatrices) {
    for (int i = 0; i < numberOfMatrices; i++) {
        generateRandomMatrix(file);
        fprintf(file, "\n");
    }
}

void readMatrix(FILE *file, matrix *m) {
    fscanf(file, "%d", &(m->nRows));
    m->nCols = m->nRows;

    m->values = (int **)malloc(sizeof(int *) * m->nRows);
    for (int i = 0; i < m->nRows; i++) {
        m->values[i] = (int *)malloc(sizeof(int) * m->nCols);
    }

    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            fscanf(file, "%d", &(m->values[i][j]));
        }
    }
}

void writeMatrix(FILE *file, matrix m) {
    fprintf(file, "%d\n", m.nRows);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            fprintf(file, "%d ", m.values[i][j]);
        }
        fprintf(file, "\n");
    }
}

void generateMultipleMatrices_(const char *inputFile, int numberOfMatricesToGenerate) {
    FILE *file = openFile(inputFile, "w");

    generateMultipleMatrices(file, numberOfMatricesToGenerate);

    fclose(file);
}

void getTransposedMatrix(const char *input, const char *output, int numberOfMatricesToGenerate) {
    FILE *inputFile = openFile(input, "r");
    FILE *outputFile = openFile(output, "w");

    while (numberOfMatricesToGenerate) {
        matrix m;
        readMatrix(inputFile, &m);
        transposeMatrix(&m);
        writeMatrix(outputFile, m);
        numberOfMatricesToGenerate--;
    }

    fclose(inputFile);
    fclose(outputFile);
}

void checkTransformationOfMatrices(const char *input, const char *output, int numberOfMatricesToCheck) {
    FILE *inputFile = openFile(input, "r");
    FILE *outputFile = openFile(output, "r");

    int count = 1;

    while (numberOfMatricesToCheck) {
        matrix m1;
        matrix m2;

        readMatrix(outputFile, &m1);
        readMatrix(inputFile, &m2);

        if (areTwoMatricesEqual(&m1, &m2)) {
            printf("The matrix %d is transformed correctly.\n", count);
        } else {
            printf("The matrix %d was transformed incorrectly.\n", count);
        }

        count++;
        numberOfMatricesToCheck--;
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    const char* inputFile = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    const char* outputFile = "C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt";

    int numberOfMatricesToGenerate = 3;

    generateMultipleMatrices_(inputFile, numberOfMatricesToGenerate);

    getTransposedMatrix(inputFile, outputFile, numberOfMatricesToGenerate);

    checkTransformationOfMatrices(inputFile, outputFile, numberOfMatricesToGenerate);

    printf("The result is written to a file output.txt\n");

    return 0;
}