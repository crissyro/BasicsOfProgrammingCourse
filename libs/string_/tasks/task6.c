#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

typedef struct {
    char word[50];
} WordDescriptor;


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

int checkLexicographicalOrder(char *sentence) {
    char *currentWord, *previousWord = NULL;
    
    while ((currentWord = my_strtok(previousWord, " ")) != NULL) {
        if (previousWord != NULL && strcmp(previousWord, currentWord) > 0) {
            return 0;
        }
        
        previousWord = currentWord;
    }
    
    return 1;
}

int main() {
    char sentence[] = "apple banana cherry";
    if (checkLexicographicalOrder(sentence)) {
        printf("Words in the sentence are lexicographically ordered.\n");
    } else {
        printf("Words in the sentence are not lexicographically ordered.\n");
    }

    return 0;
}