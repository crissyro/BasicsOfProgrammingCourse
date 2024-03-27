#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

char* findWordBeforeFirstMatch(char* s1, char* s2) {
    char* wordBefore = NULL;
    char* token = strtok_(s1, " ");

    while (token != NULL) {
        if (strstr_(s2, token) != NULL) {
            return wordBefore;
        }
        wordBefore = token;
        token = strtok_(NULL, " ");
    }

    return NULL;
}

void test_findWordBeforeFirstMatch() {
    char s1[] = "orange apple banana cherry";
    char s2[] = "cherry banana";
    char* result = findWordBeforeFirstMatch(s1, s2);

    ASSERT_STRING("apple", result);
}

void test() {
    test_findWordBeforeFirstMatch();
}

int main() {
    test();

    return 0;
}