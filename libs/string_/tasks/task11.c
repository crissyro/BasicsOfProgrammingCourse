#include <stdio.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    if (s == NULL || strlen_(s) == 0) {
        return EMPTY_STRING;
    }

    char *token = strtok_(s, " ");
    char *prevWordEnd = NULL;
    char *currentWordBegin = NULL;

    while (token != NULL) {
        prevWordEnd = currentWordBegin;
        currentWordBegin = token;

        char *currentWordEnd = token + strlen_(token);

        for (char *c = token; *c != '\0'; c++) {
            *c = tolower(*c);
        }

        if (find(token, currentWordEnd, 'a') != currentWordEnd) {
            if (prevWordEnd == NULL) {
                return FIRST_WORD_WITH_A;
            } else {
                w->begin = prevWordEnd;
                w->end = currentWordBegin;
                return WORD_FOUND;
            }
        }

        token = strtok_(NULL, " ");
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor w;

    WordBeforeFirstWordWithAReturnCode result = getWordBeforeFirstWordWithA(s, &w);

    switch (result) {
        case FIRST_WORD_WITH_A:
            printf("The first word with 'a' is the first in the string.\n");
            break;
        case NOT_FOUND_A_WORD_WITH_A:
            printf("There are no words with 'a' in the string.\n");
            break;
        case WORD_FOUND:
            printf("The word before the first word with 'a':");
            for (char *c = w.begin; c < w.end; c++) {
                printf("%c", *c);
            }
            printf("\n");
            break;
        case EMPTY_STRING:
            printf("There are no words in the line.\n");
            break;
    }
}

void testAll_getWordBeforeFirstWordWithA() {
    WordDescriptor word;
    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word) == EMPTY_STRING);
    char s2[] = "ABC";
    assert(getWordBeforeFirstWordWithA(s2, &word) == FIRST_WORD_WITH_A);
    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &word) == WORD_FOUND);
    char s4[] = "B Q WE YR OW IUWR";
    assert(getWordBeforeFirstWordWithA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
}

int main() {
    char s[] = "Hello world, this is a test string";
    printWordBeforeFirstWordWithA(s);

    testAll_getWordBeforeFirstWordWithA() ;

    return 0;
}