#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ELEMENT 100
#define MAX_SIZE 10

typedef struct {
    int nRows;
    int values[MAX_SIZE][MAX_SIZE];
} Matrix;

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

bool isSymmetricMatrix(Matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < i; j++) {
            if (m->values[i][j] != m->values[j][i]) {
                return false;
            }
        }
    }

    return true;
}

void transposeSquareMatrix(Matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = i + 1; j < m->nRows; j++) {
            int temp = m->values[i][j];
            m->values[i][j] = m->values[j][i];
            m->values[j][i] = temp;
        }
    }
}

void getTransformedMatrices(const char* inputFilename, const char* outputFilename) {
    FILE *inputFile = openFile(inputFilename, "rb");
    FILE *outputFile = openFile(outputFilename, "wb");

    int nMatrices;
    fread(&nMatrices, sizeof(int), 1, inputFile);
    fwrite(&nMatrices, sizeof(int), 1, outputFile);

    for (int i = 0; i < nMatrices; i++) {
        Matrix matrix;
        fread(&matrix.nRows, sizeof(int), 1, inputFile);

        for (int j = 0; j < matrix.nRows; j++) {
            fread(&matrix.values[j], sizeof(int), matrix.nRows, inputFile);
        }

        if (!isSymmetricMatrix(&matrix)) {
            transposeSquareMatrix(&matrix);
        }

        fwrite(&matrix.nRows, sizeof(int), 1, outputFile);

        for (int j = 0; j < matrix.nRows; j++) {
            fwrite(&matrix.values[j], sizeof(int), matrix.nRows, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

void printMatrix(const Matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nRows; j++) {
            printf("%d ", m->values[i][j]);
        }

        printf("\n");
    }
}

void printMatrixFile(const char* filename) {
    FILE *file = openFile(filename, "rb");

    int nMatrices;
    fread(&nMatrices, sizeof(int), 1, file);

    for (int i = 0; i < nMatrices; i++) {
        Matrix matrix;
        fread(&matrix.nRows, sizeof(int), 1, file);

        for (int j = 0; j < matrix.nRows; j++) {
            fread(&matrix.values[j], sizeof(int), matrix.nRows, file);
        }

        printf("Matrix %d:\n", i + 1);
        printMatrix(&matrix);
        printf("\n");
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