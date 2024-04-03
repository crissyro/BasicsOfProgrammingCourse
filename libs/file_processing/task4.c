#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 50
#define NUM_WORDS_TO_GENERATE 500

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
    int alphabet_length = strlen(alphabet);

    srand(time(NULL));

    for (int i = 0; i < NUM_WORDS_TO_GENERATE; i++) {
        char word[MAX_WORD_LENGTH];
        int word_length = rand() % (MAX_WORD_LENGTH - 1) + 1;

        for (int j = 0; j < word_length; j++) {
            word[j] = alphabet[rand() % alphabet_length];
        }

        word[word_length] = '\0';
        fprintf(file, "%s\n", word);
    }

    fclose(file);
}

void filterWords(const char* inputFilename, const char* outputFilename, const char* sequence) {
    FILE* inputFile = openFile(inputFilename, "r");
    FILE* outputFile = openFile(outputFilename, "w");

    char word[MAX_WORD_LENGTH];

    while (fscanf(inputFile, "%s", word) == 1) {
        if (strstr(word, sequence) != NULL) {
            fprintf(outputFile, "%s\n", word);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

bool checkSequence(const char* filename, const char* sequence) {
    FILE* file = openFile(filename, "r");

    char word[MAX_WORD_LENGTH];
    bool allContainSequence = true;

    while (fscanf(file, "%s", word) == 1) {
        if (strstr(word, sequence) == NULL) {
            allContainSequence = false;
            break;
        }
    }

    fclose(file);
    return allContainSequence;
}

int main() {
    const char* inputFile = "C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt";
    const char* outputFile = "C:/Users/fatee/ClionProjects/course/libs/file_processing/output.txt";
    const char* sequence = "ab";

    generateRandomWords(inputFile);
    filterWords(inputFile, outputFile, sequence);

    if (checkSequence(outputFile, sequence)) {
        printf("In the file output.txt all words contain this sequence of characters.\n");
    } else {
        printf("To a file output.txt the wrong words are written down.\n");
    }

    return 0;
}