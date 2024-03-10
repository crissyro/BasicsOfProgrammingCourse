#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void test_copy() {
    const char source[] = "Hello";
    char destination[10];
    copy(source, source + 5, destination);

    destination[5] = '\0';
    printf("%s", destination);

    assert(strcmp(destination, "Hello") == 0);
}

void test() {
    // test_strlen() ;
    // test_find() ;
    // test_findNonSpace() ;
    // test_findSpace() ;
    // test_findNonSpaceReverse() ;
    // test_findSpaceReverse() ;
    // test_strcmp() ;
    test_copy() ;
}

int main() {
    test();

    return 0;
}