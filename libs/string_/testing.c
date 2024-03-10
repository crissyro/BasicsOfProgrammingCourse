#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void test_strlen() {
    char *s1 = "Hi";
    char s2[10] = "\tHello\t";

    assert(strlen1(s1) == 2); 
    assert(strlen1(s2) == 7);

    assert(strlen2(s1) == 2); 
    assert(strlen2(s2) == 7);

    assert(strlen_(s1) == 2); 
    assert(strlen_(s2) == 7);
}

void test_find() {
    char str[] = "Hello, world!";
    char *begin = str;
    char *end = str + sizeof(str) - 1;

    char ch1 = 'o';
    char *result1 = find(begin, end, ch1);
    printf("%s\n", result1);

    char ch2 = 'y';
    char *result2 = find(begin, end, ch2);
    assert(result2 == end);
}

void test_findNonSpace() {
    char text[] = "   \t  Hello, World!";

    char *nonSpacePtr = findNonSpace(text);

    printf("%s\n", nonSpacePtr);
}

