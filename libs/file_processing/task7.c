#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100
#define MAX_NUMBERS 20

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }

    return file;
}

void generateNumbersFile(const char* filename, int nNumbers) {
    FILE *file = openFile(filename, "wb");

    srand(time(NULL));

    int positiveCount = 0;
    int negativeCount = 0;

    while (positiveCount < nNumbers / 2 || negativeCount < nNumbers / 2) {
        int number = rand() % (2 * MAX_ELEMENT + 1) - MAX_ELEMENT;
        if (number > 0 && positiveCount < nNumbers / 2) {
            fwrite(&number, sizeof(int), 1, file);
            positiveCount++;
        } else if (number < 0 && negativeCount < nNumbers / 2) {
            fwrite(&number, sizeof(int), 1, file);
            negativeCount++;
        }
    }

    fclose(file);
}

void printNumbersFile(const char* filename) {
    FILE *file = openFile(filename, "rb");

    int number;

    while (fread(&number, sizeof(int), 1, file) == 1) {
        printf("%d\n", number);
    }

    fclose(file);
}

void customSort(int *numbers, int length) {
    int a[length / 2];
    int b[length / 2];
    int index = 0;
    int positive_index = 0;
    int negative_index = 0;

    while (index < length) {
        if (numbers[index] > 0) {
            a[positive_index] = numbers[index];
            positive_index++;
        } else {
            b[negative_index] = numbers[index];
            negative_index++;
        }
        index++;
    }

    for(int i=0; i < length; i++) {
        numbers[i] = a[i];
        if (i >= 10) {
            numbers[i] = b[i % 10];
        }
    }
}

void getNewOrderOfNumbers(const char* filename, int nNumbers) {
    FILE *file = openFile(filename, "rb+");

    int *numbers = (int*)malloc(sizeof(int) * nNumbers);
    if (numbers == NULL) {
        printf("Memory allocation error.\n");
        fclose(file);
        exit(1);
    }

    fread(numbers, sizeof(int), nNumbers, file);
    customSort(numbers, nNumbers);

    fseek(file, 0, SEEK_SET);
    fwrite(numbers, sizeof(int), nNumbers, file);

    fclose(file);
    free(numbers);
}

int main() {
    const char* filename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    int nNumbers = MAX_NUMBERS;

    generateNumbersFile(filename, nNumbers);

    printf("Contents of the file before transformation:\n");
    printNumbersFile(filename);

    getNewOrderOfNumbers(filename, nNumbers);

    printf("Contents of the file after transformation:\n");
    printNumbersFile(filename);

    return 0;
}
