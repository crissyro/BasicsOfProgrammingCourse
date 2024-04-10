#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MAX_ELEMENT 100

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
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

void generateMultipleMatrices(FILE* file, int numberOfMatrices) {
    for (int i = 0; i < numberOfMatrices; i++) {
        generateRandomMatrix(file);
        fprintf(file, "\n");
    }
}

void readMatrix(FILE *file, int matrix[MAX_SIZE][MAX_SIZE], int *order) {
    fscanf(file, "%d", order);
    
    for (int i = 0; i < *order; i++) {
        for (int j = 0; j < *order; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
}

void writeMatrix(FILE *file, int matrix[MAX_SIZE][MAX_SIZE], int order) {
    fprintf(file, "%d\n", order);

    for (int j = 0; j < order; j++) {
        for (int i = 0; i < order; i++) {
            fprintf(file, "%d ", matrix[i][j]);
        }

        fprintf(file, "\n");
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int order) {
    int temp;
    for (int i = 0; i < order; i++) {
        for (int j = i + 1; j < order; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int compareMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int order) {
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return 0;
            }
        }
    }
    
    return 1;
}

void generateMultipleMatrices_(const char* inputFile, int numberOfMatricesToGenerate) {
    FILE *file = openFile(inputFile, "w");

    generateMultipleMatrices(file, numberOfMatricesToGenerate);

    fclose(file);
}

void getTransposedMatrix(const char* input, const char* output, int numberOfMatricesToGenerate) {
    FILE *inputFile = openFile(input, "r");
    FILE *outputFile = openFile(output, "w");

    int orderMatrix;
    int matrix[MAX_SIZE][MAX_SIZE];

    while (numberOfMatricesToGenerate) {
        readMatrix(inputFile, matrix, &orderMatrix);
        writeMatrix(outputFile, matrix, orderMatrix);
        numberOfMatricesToGenerate--;
    }

    fclose(inputFile);
    fclose(outputFile);
}

void checkTransformationOfMatrices(const char* input, const char* output, int numberOfMatricesToCheck) {
    FILE *inputFile = openFile(input, "r");
    FILE *outputFile = openFile(output, "r");

    int count = 1;

    while (numberOfMatricesToCheck) {
        int orderMatrix1;
        int matrix1[MAX_SIZE][MAX_SIZE]; 

        int orderMatrix2;
        int matrix2[MAX_SIZE][MAX_SIZE];

        readMatrix(outputFile, matrix1, &orderMatrix1);
        transposeMatrix(matrix1, orderMatrix1);

        readMatrix(inputFile, matrix2, &orderMatrix2);

        if (orderMatrix1 != orderMatrix2) {
            printf("The sizes of the matrices do not match.\n");
            return;
        }

        if (compareMatrices(matrix1, matrix2, orderMatrix1)) {
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