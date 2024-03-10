#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void test_findSpace() {
    char text1[] = "Hello, World!";
    char text2[] = "ThisHasNoSpace";
    char text3[] = "";

    char *result1 = findSpace(text1);
    char *result2 = findSpace(text2);
    char *result3 = findSpace(text3);

    assert(*result1 == ' ');
    assert(*result2 == '\0');
    assert(*result3 == '\0');
}

void test() {
    // test_strlen() ;
    // test_find() ;
    // test_findNonSpace() ;
    test_findSpace() ;
}

int main() {
    test();

    return 0;
}