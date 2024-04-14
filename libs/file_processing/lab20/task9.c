#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    return file;
}

void generateNumbers(const char* filename, int count) {
    FILE* file = openFile(filename, "w");
    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        int num = rand() % 100;
        fprintf(file, "%d\n", num);
    }

    fclose(file);
}

void filterNumbers(FILE *input, FILE *output, int N) {
    int num;
    
    while (fscanf(input, "%d", &num) != EOF) {
        if (num < N) {
            fprintf(output, "%d\n", num);
        }
    }
}

int main() {
    const char* inputFilename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    const char* outputFilename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt";
    int count = 10;
    
    int N;
    printf("N: ");
    scanf("%d", &N);
    
    generateNumbers(inputFilename, count);
    
    FILE *inputFile = openFile(inputFilename, "r");
    FILE *outputFile = openFile(outputFilename, "w");
    
    filterNumbers(inputFile, outputFile, N);
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}