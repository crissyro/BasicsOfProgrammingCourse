#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
// #include "C:/Users/fatee/ClionProjects/course/libs/string_/tasks/string_processing.c"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)


void assertString(const char *expected, char *got,char const *fileName, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

void test_digitToStartTransform_oneWord() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    ASSERT_STRING("321Hi", s);
}