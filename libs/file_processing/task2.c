#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }
    
    return file;
}

void generateRandomFixedPointNumbers(FILE *file, int count) {
    srand(time(NULL));
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

void generateRandomFixedPointNumbers_(const char* inputFile, int numberOfNumbersToGenerate) {
    FILE *file = openFile(inputFile, "w");

    generateRandomFixedPointNumbers(file, numberOfNumbersToGenerate);

    fclose(file);
}

void getFloatingPointNumbers(const char* input, const char* output) {
    FILE *inputFile = openFile(input, "r");
    FILE *outputFile = openFile(output, "w");

    double numbers[MAX_SIZE];
    int count;

    readFixedPointNumbers(inputFile, numbers, &count);
    writeFloatingPointNumbers(outputFile, numbers, count);

    fclose(inputFile);
    fclose(outputFile);
}

void checkFloatingPointNumbers(const char* input, const char* output, int numberOfNumbersToGenerate){
    FILE *inputFile = openFile(input, "r");
    FILE *outputFile = openFile(output, "r");

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
}

int main() {
    const char* inputFile = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    const char* outputFile = "C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt";

    int numberOfNumbersToGenerate = 5;

    generateRandomFixedPointNumbers_(inputFile, numberOfNumbersToGenerate);

    getFloatingPointNumbers(inputFile, outputFile);

    checkFloatingPointNumbers(inputFile, outputFile, numberOfNumbersToGenerate);

    printf("The result is written to a file output.txt\n");

    return 0;
}