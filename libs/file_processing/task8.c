#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "C:/Users/fatee/ClionProjects/course/libs/data_structures/matrix/matrix.c"

#define MAX_ELEMENT 100

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }

    return file;
}

void generateRandomMatrix(FILE *file, int orderMatrix) {
    fwrite(&orderMatrix, sizeof(int), 1, file);

    for (int i = 0; i < orderMatrix; i++) {
        for (int j = 0; j < orderMatrix; j++) {
            int matrixElement = rand() % (2 * MAX_ELEMENT + 1) - MAX_ELEMENT;
            fwrite(&matrixElement, sizeof(int), 1, file);
        }
    }
}

void generateMatrixFile(const char* filename, int nMatrices, int orderMatrix) {
    FILE *file = openFile(filename, "wb");
    fwrite(&nMatrices, sizeof(int), 1, file);

    srand(time(NULL));

    for (int i = 0; i < nMatrices; i++) {
        generateRandomMatrix(file, orderMatrix);
    }

    fclose(file);
}

void getTransformedMatrices(const char* inputFilename, const char* outputFilename) {
    FILE *inputFile = openFile(inputFilename, "rb");
    FILE *outputFile = openFile(outputFilename, "wb");

    int nMatrices;
    fread(&nMatrices, sizeof(int), 1, inputFile);
    fwrite(&nMatrices, sizeof(int), 1, outputFile);

    for (int i = 0; i < nMatrices; i++) {
        int nRows;
        fread(&nRows, sizeof(int), 1, inputFile);
        matrix m = getMemMatrix(nRows, nRows);

        for (int j = 0; j < nRows; j++) {
            fread(m.values[j], sizeof(int), nRows, inputFile);
        }

        if (!isSymmetricMatrix(&m)) {
            transposeSquareMatrix(&m);
        }

        fwrite(&nRows, sizeof(int), 1, outputFile);

        for (int j = 0; j < nRows; j++) {
            fwrite(m.values[j], sizeof(int), nRows, outputFile);
        }

        freeMatrix(&m);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void printMatrixFile(const char* filename) {
    FILE *file = openFile(filename, "rb");

    int nMatrices;
    fread(&nMatrices, sizeof(int), 1, file);

    for (int i = 0; i < nMatrices; i++) {
        int nRows;
        fread(&nRows, sizeof(int), 1, file);
        matrix m = getMemMatrix(nRows, nRows);

        for (int j = 0; j < nRows; j++) {
            fread(m.values[j], sizeof(int), nRows, file);
        }

        printf("Matrix %d:\n", i + 1);
        outputMatrix(m);
        printf("\n");

        freeMatrix(&m);
    }

    fclose(file);
}

int main() {
    const char* inputFilename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    const char* outputFilename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt";

    int nMatrices = 3;
    int orderMatrix = 5;

    generateMatrixFile(inputFilename, nMatrices, orderMatrix);

    printf("Contents of the input file:\n");
    printMatrixFile(inputFilename);

    getTransformedMatrices(inputFilename, outputFilename);

    printf("Contents of the output file:\n");
    printMatrixFile(outputFilename);

    return 0;
}