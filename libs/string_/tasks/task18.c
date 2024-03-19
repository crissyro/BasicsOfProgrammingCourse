#include <stdio.h>
#include <stdlib.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void processStrings(char *s1, char *s2, int n1, int n2) {
    char *wordArray[100];
    int wordArrayIndex = 0;

    for (char *token = s2; *token; token = findNonSpace(findSpace(token))) {
        wordArray[wordArrayIndex] = malloc(strlen_(token) + 1);
        copy(token, findSpace(token), wordArray[wordArrayIndex]);
        wordArrayIndex++;
    }

    for (int j = n2 - n1; j > 0; j--) {
        char *space = " ";
        char *endS1 = s1 + strlen_(s1);
        if (endS1 != s1) {
            copy(space, space + 1, endS1);
            endS1++;
        }
        endS1 = copy(wordArray[wordArrayIndex - j], findSpace(wordArray[wordArrayIndex - j]), endS1);
    }

    printf("Result: %s\n", s1);

    for (int j = 0; j < wordArrayIndex; j++) {
        free(wordArray[j]);
    }
}

int main() {
    char s1[100] = "aaa bbb ccc";
    char s2[100] = "ddd eee fff ggg hhh";
    int n1 = 3, n2 = 5;

    processStrings(s1, s2, n1, n2);

    return 0;
}