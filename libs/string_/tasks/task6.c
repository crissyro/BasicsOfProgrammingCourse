#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int is_delim(char c, char *delim) {
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }

        delim++;
    }

    return 0;
}

char *strtok_(char *inputString, char *delimiters) {
    static char *nextToken; 
    if (!inputString) {
        inputString = nextToken;
    }

    if (!inputString) {
        return NULL;
    }

    while (1) {
        if (is_delim(*inputString, delimiters)) {
            inputString++;
            continue;
        }

        if (*inputString == '\0') {
            return NULL; 
        }

        break;
    }

    char *tokenStart = inputString;
    while (1) {
        if (*inputString == '\0') {
            nextToken = inputString;
            return tokenStart;
        }

        if (is_delim(*inputString, delimiters)) {
            *inputString = '\0';
            nextToken = inputString + 1;
            return tokenStart;
        }

        inputString++;
    }
}

int checkLexicographicalOrder(char *sentence) {
    char *currentWord, *previousWord = NULL;
    
    while ((currentWord = strtok_(previousWord, " ")) != NULL) {
        if (previousWord != NULL && strcmp(previousWord, currentWord) > 0) {
            return 0;
        }
        
        previousWord = currentWord;
    }
    
    return 1;
}

void test_checkLexicographicalOrder() {
    char s[] = "apple banana cherry";
    checkLexicographicalOrder(s);
    ASSERT_STRING("apple banana cherry", s);
}

void test() {
    test_checkLexicographicalOrder() ;
}

int main() {
    test();

    return 0;
}