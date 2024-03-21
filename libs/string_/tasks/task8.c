#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int is_delim(char c, char *delim) {
    while(*delim != '\0') {
        if(c == *delim) {
            return 1;
        }

        delim++;
    }

    return 0;
}

char *my_strtok(char *inputString, char *delimiters) {
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

bool isPalindrome(char *word) {
    int len = strlen_(word);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(word[i]) != tolower(word[len - i - 1])) {
            return false;
        }
    }

    return true;
}

int main() {
    char input[] = "level, radar, kayak, hello, civic, rotor";
    int count = 0;

    char *token = my_strtok(input, ", ");
    while (token != NULL) {
        if (isPalindrome(token)) {
            count++;
        }

        token = my_strtok(NULL, ", ");
    }

    printf("%d\n", count);

    return 0;
}