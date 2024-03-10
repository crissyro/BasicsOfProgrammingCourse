#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

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

void test() {
    // test_strlen() ;
    // test_find() ;
    test_findNonSpace() ;
}

int main() {
    test();

    return 0;
}