#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

char* extractWordsDifferentFromLast(const char *s) {
    char *lastWord = NULL;
    char *currentWord = NULL;
    char *result = NULL;
    char *temp = NULL;

    char *start = findNonSpace(s);
    char *end = findSpace(start);

    while (*end != '\0') {
        start = findNonSpace(end);
        end = findSpace(start);
    }

    lastWord = (char*)malloc(end - start + 1);
    copy(start, end, lastWord);
    lastWord[end - start] = '\0';

    start = findNonSpace(s);
    end = findSpace(start);

    while (*end != '\0') {
        currentWord = (char*)malloc(end - start + 1);
        copy(start, end, currentWord);
        currentWord[end - start] = '\0';

        if (strcmp(currentWord, lastWord) != 0) {
            if (result == NULL) {
                result = strdup(currentWord);
            } else {
                int len = strlen(result) + strlen(currentWord) + 2;
                temp = (char*)malloc(len);
                snprintf(temp, len, "%s %s", result, currentWord);
                free(result);
                result = temp;
            }
        } else {
            free(currentWord);
        }

        start = findNonSpace(end);
        end = findSpace(start);
    }

    free(lastWord);

    return result;
}

void test_extractWordsDifferentFromLast() {
    char source[] = "apple banana cherry apple";
    char* result = extractWordsDifferentFromLast(source);
    ASSERT_STRING("banana cherry", result);
}

void test() {
    test_extractWordsDifferentFromLast() ;
}

int main() {
    test();

    return 0;
}