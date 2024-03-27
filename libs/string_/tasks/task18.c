#include <stdio.h>
#include <stdlib.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void addLastWordsToLine(char *s1, char *s2, int n1, int n2) {
    char *wordArray[MAX_STRING_SIZE];
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

    for (int j = 0; j < wordArrayIndex; j++) {
        free(wordArray[j]);
    }
}

void test_addLastWordsToLine() {
    char source1[] = "aaa bbb ccc";
    char source2[] = "ddd eee fff ggg hhh";
    int n1 = 3, n2 = 5;
    addLastWordsToLine(source1, source2, n1, n2);

    ASSERT_STRING("aaa bbb ccc ggg hhh", source1);
}

void test() {
    test_addLastWordsToLine() ;
}

int main() {
    test();

    return 0;
}