#include <stdio.h>
#include <stdbool.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

typedef struct {
    char *begin;
    char *end;
} WordDescriptor;

bool getWord(char **beginSearch, WordDescriptor *word) {
    char *p = *beginSearch;
    while (*p == ' ') {
        p++;
    }
    if (*p == '\0') {
        return false;
    }
    word->begin = p;
    while (*p != ' ' && *p != '\0') {
        p++;
    }
    word->end = p;
    *beginSearch = p;
    return true;
}

int main() {
    char s1[] = "Hello world from first string";
    char s2[] = "This is the second string cat dog";

    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;

    while ((isW1Found = getWord(&beginSearch1, &word1)), (isW2Found = getWord(&beginSearch2, &word2)), isW1Found || isW2Found) {
        if (isW1Found) {
            for (char *p = word1.begin; p < word1.end; p++) {
                printf("%c", *p);
            }
            printf(" ");
        }
        if (isW2Found) {
            for (char *p = word2.begin; p < word2.end; p++) {
                printf("%c", *p);
            }
            printf(" ");
        }
    }

    while (getWord(&beginSearch1, &word1)) {
        for (char *p = word1.begin; p < word1.end; p++) {
            printf("%c", *p);
        }
        printf(" ");
    }

    while (getWord(&beginSearch2, &word2)) {
        for (char *p = word2.begin; p < word2.end; p++) {
            printf("%c", *p);
        }
        printf(" ");
    }

    return 0;
}