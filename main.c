#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void test_strcmp() {
    assert(strcmp("hello", "hello") == 0);
    assert(strcmp("hello", "world") < 0);
    assert(strcmp("apple", "app") > 0);
    assert(strcmp("", "hello") < 0);
    assert(strcmp("world", "") > 0);
}

void test() {
    // test_strlen() ;
    // test_find() ;
    // test_findNonSpace() ;
    // test_findSpace() ;
    // test_findNonSpaceReverse() ;
    // test_findSpaceReverse() ;
    test_strcmp() ;
}

int main() {
    test();

    return 0;
}