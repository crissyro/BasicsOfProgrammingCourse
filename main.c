#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int isEven(int num) {
    return num % 2 == 0;
}

void test_copyIfReverse() {
    char source1[] = {1, 2, 3, 4, 5};
    char destination1[5];
    copyIfReverse(source1 + 4, source1 - 1, destination1, isEven);

    assert(destination1[0] == 4);
    assert(destination1[1] == 2);
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
    // test_copyIf() ;
    test_copyIfReverse() ;
}

int main() {
    test();

    return 0;
}