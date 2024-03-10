#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int isEven(int num) {
    return num % 2 == 0;
}

void test_copyIf() {
    char source1[] = {1, 2, 3, 4, 5};
    char destination1[5];
    char *result1 = copyIf(source1, source1 + 5, destination1, isEven);

    assert(result1 - destination1 == 2);
    assert(destination1[0] == 2);
    assert(destination1[1] == 4);
}

void test() {
    // test_strlen() ;
    // test_find() ;
    // test_findNonSpace() ;
    // test_findSpace() ;
    // test_findNonSpaceReverse() ;
    // test_findSpaceReverse() ; 
    // test_strcmp() ;
    // test_copy() ;
    test_copyIf() ;
}

int main() {
    test();

    return 0;
}