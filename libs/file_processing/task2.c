#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15

void generateRandomFixedPointNumbers(FILE *file, int count) {
    for (int i = 0; i < count; i++) {
        double number = ((double)rand() / RAND_MAX) * 1000.0;
        fprintf(file, "%lf\n", number);
    }
}

void readFixedPointNumbers(FILE *file, double numbers[], int *count) {
    *count = 0;
    while (fscanf(file, "%lf", &numbers[*count]) == 1) {
        (*count)++;
    }
}

void writeFloatingPointNumbers(FILE *file, double numbers[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%.2f\n", numbers[i]);
    }
}

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }
    
    return file;
}

int main() {
    srand(time(NULL));

    FILE *file = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt", "w");

    int numberOfNumbersToGenerate = 5;
    generateRandomFixedPointNumbers(file, numberOfNumbersToGenerate);

    fclose(file);

    FILE *inputFile = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt", "r");
    FILE *outputFile = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt", "w");

    double numbers[MAX_SIZE];
    int count;

    readFixedPointNumbers(inputFile, numbers, &count);
    writeFloatingPointNumbers(outputFile, numbers, count);

    fclose(inputFile);
    fclose(outputFile);

    inputFile = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt", "r");
    outputFile = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt", "r");

    int numberOfNumbersToCheck = numberOfNumbersToGenerate;
    int testCount = 1;

    while (numberOfNumbersToCheck) {
        double originalNumber, convertedNumber;
        fscanf(inputFile, "%lf", &originalNumber);
        fscanf(outputFile, "%lf", &convertedNumber);

        if (abs(originalNumber - convertedNumber) <= 0.01) {
            printf("Test %d passed.\n", testCount);
        } else {
            printf("Test %d failed.\n", testCount);
        }

        testCount++;
        numberOfNumbersToCheck--;
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("The result is written to a file output.txt\n");

    return 0;
}