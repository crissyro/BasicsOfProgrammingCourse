#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define BUFFER_SIZE 1024

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

void printFilePortions(FILE* file, int N) {
    char buffer[BUFFER_SIZE];
    int lines_read = 0;

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
        lines_read++;

        if (lines_read == N) {
            printf("\nPress Ctrl+C to continue...\n");
            lines_read = 0;
            getch();
        }
    }
}

int main() {
    const char* filename = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    int count = 10;
    
    int N;
    printf("N: ");
    scanf("%d", &N);
    
    generateNumbers(filename, count);

    FILE* file = openFile(filename, "r");
    printFilePortions(file, N);
    fclose(file);

    return 0;
}  