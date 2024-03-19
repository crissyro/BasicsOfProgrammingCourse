#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

#define MAX_LENGTH 128
#define DELIMITERS " ,.!?\t\n"

char** tokenizeString(char* inputString, int* wordCount) {
    char** words = NULL;
    int count = 0;

    char* token = strtok(inputString, DELIMITERS);
    while (token != NULL) {
        words = (char**)realloc(words, sizeof(char*) * (count + 1));
        words[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIMITERS);
    }

    *wordCount = count;
    return words;
}

void findWordBefore(char** words1, int count1, char* str2) {
    char* token = strtok(str2, DELIMITERS);
    while (token != NULL) {
        int i = 0;
        for (i = 0; i < count1 && strcmp(token, words1[i]); ++i);

        if (i == count1) {
            token = strtok(NULL, DELIMITERS);
            continue;
        } else if (i == 0) {
            printf("\"%s\" is the first word in String1.\n", token);
            break;
        } else {
            printf("Word before \"%s\" in String1 is \"%s\"\n", token, words1[i - 1]);
            break;
        }

        token = strtok(NULL, DELIMITERS);
    }

    if (token == NULL) {
        printf("No words from String2 found in String1.\n");
    }
}

int main() {
    char s1[] = "This is a test string";
    char s2[] = "Another test here";

    int count1 = 0;
    char** words1 = tokenizeString(s1, &count1);

    findWordBefore(words1, count1, s2);

    for (int i = 0; i < count1; ++i) {
        free(words1[i]);
    }
    free(words1);

    return 0;
}