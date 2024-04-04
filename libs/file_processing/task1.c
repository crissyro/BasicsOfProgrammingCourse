#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MAX_ELEMENT 100

void generateRandomMatrix(FILE *file) {
    int orderMatrix = rand() % MAX_SIZE + 1;

    fprintf(file, "%d\n", orderMatrix);

    for (int i = 0; i < orderMatrix; i++) {
        for (int j = 0; j < orderMatrix; j++) {
            int matrixElement = rand() % (2 * MAX_ELEMENT + 1) - MAX_ELEMENT;
            fprintf(file, "%d ", matrixElement);
        }

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

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        // or use  printf("errno %d\n", errno), need include <errno.h>, print number of problem,
        // perror in <stdio.h> print name of problem
        perror("file");
        exit(1);
    }

    return file;
}

void generateMultipleMatrices(FILE* file, int numberOfMatrices) {
    for (int i = 0; i < numberOfMatrices; i++) {
        generateRandomMatrix(file);
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

int main() {
    srand(time(NULL));

    FILE *file = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt", "w");

    int numberOfMatricesToGenerate = 3;
    generateMultipleMatrices(file, numberOfMatricesToGenerate);

    fclose(file);

    FILE *inputFile = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt", "r");
    FILE *outputFile = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt", "w");

    int orderMatrix;
    int matrix[MAX_SIZE][MAX_SIZE];

    while (numberOfMatricesToGenerate) {
        readMatrix(inputFile, matrix, &orderMatrix);
        writeMatrix(outputFile, matrix, orderMatrix);
        numberOfMatricesToGenerate--;
    }

    fclose(inputFile);
    fclose(outputFile);

    inputFile = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt", "r");
    outputFile = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt", "r");

    int numberOfMatricesToGenerate2 = 3;
    int count = 1;

    while (numberOfMatricesToGenerate2) {
        int orderMatrix1;
        int matrix1[MAX_SIZE][MAX_SIZE]; 

        int orderMatrix2;
        int matrix2[MAX_SIZE][MAX_SIZE];

        readMatrix(outputFile, matrix1, &orderMatrix1);
        transposeMatrix(matrix1, orderMatrix1);

        readMatrix(inputFile, matrix2, &orderMatrix2);

        if (orderMatrix1 != orderMatrix2) {
            printf("The sizes of the matrices do not match.\n");
            return 1;
        }

        if (compareMatrices(matrix1, matrix2, orderMatrix1)) {
            printf("The matrix %d is transformed correctly.\n", count);
        } else {
            printf("The matrix %d was transformed incorrectly.\n", count);
        }

        count++;
        numberOfMatricesToGenerate2--;
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("The result is written to a file output.txt\n");

    return 0;
}
