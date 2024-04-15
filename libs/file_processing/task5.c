#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

#define MAX_WORD_LENGTH 20
#define NUM_WORDS_TO_GENERATE 10
#define MAX_NUM_OF_STRINGS 10

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }

    return file;
}

void generateRandomWords(const char* filename) {
    FILE* file = openFile(filename, "w");

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int alphabet_length = strlen_(alphabet);

    srand(time(NULL));

    for (int i = 0; i < MAX_NUM_OF_STRINGS; i++) {
        for (int i = 0; i < NUM_WORDS_TO_GENERATE; i++) {
            char word[MAX_WORD_LENGTH];
            int word_length = rand() % (MAX_WORD_LENGTH - 1) + 1;

            for (int j = 0; j < word_length; j++) {
                word[j] = alphabet[rand() % alphabet_length];
            }

            word[word_length] = '\0';
            fprintf(file, "%s ", word);
        }

        fprintf(file, "\n");
    }

    fclose(file);
}

void maxWords(const char* inputFilename, const char* outputFilename) {
    FILE* inputFile = openFile(inputFilename, "r");
    FILE* outputFile = openFile(outputFilename, "w");

    char line[MAX_WORD_LENGTH * NUM_WORDS_TO_GENERATE];
    char max_word[MAX_WORD_LENGTH] = "";

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        char* token = strtok_(line, " \n");
        int max_length = 0;

        while (token != NULL) {
            int length = strlen_(token);
            if (length > max_length) {
                max_length = length;
                copy2(token, token + strlen_(token), max_word);
            }

            token = strtok_(NULL, " \n");
        }

        fprintf(outputFile, "%s\n", max_word);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void checkReceivedWords(const char* inputFilename, const char* outputFilename) {
    FILE* inputFile = openFile(inputFilename, "r");
    FILE* outputFile = openFile(outputFilename, "r");

    char input_line[MAX_WORD_LENGTH * NUM_WORDS_TO_GENERATE];
    char output_word[MAX_WORD_LENGTH];

    int line_number = 1;
    bool all_lengths_matched = true;

    while (fgets(input_line, sizeof(input_line), inputFile) != NULL && fscanf(outputFile, "%s", output_word) == 1) {
        char* token = strtok_(input_line, " \n");

        while (token != NULL) {
            int input_length = strlen_(token);
            int output_length = strlen_(output_word);

            if (input_length > output_length) {
                all_lengths_matched = false;
            }

            token = strtok_(NULL, " \n");
            fscanf(outputFile, "%s", output_word);
        }

        line_number++;
    }

    fclose(inputFile);
    fclose(outputFile);  

    if (all_lengths_matched) {
        printf("The program completed the task correctly.\n");
    }
}

int main() {
    const char* inputFile = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    const char* outputFile = "C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt";

    generateRandomWords(inputFile);
    
    maxWords(inputFile, outputFile);

    checkReceivedWords(inputFile, outputFile);

    return 0;
}