#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void test_findNonSpaceReverse() {
    const char text1[] = "   \t  Hello, World!";
    char *rbegin1 = (char*)(text1 + sizeof(text1) - 2); 
    const char *rend1 = text1 - 1;

    char *result1 = findNonSpaceReverse(rbegin1, rend1);
    assert(*result1 == '!');

    const char text2[] = "   \t  ";
    char *rbegin2 = (char*)(text2 + sizeof(text2) - 2); 
    const char *rend2 = text2 - 1;

    char *result2 = findNonSpaceReverse(rbegin2, rend2);
    assert(result2 == rend2);
}

void test() {
    // test_strlen() ;
    // test_find() ;
    // test_findNonSpace() ;
    // test_findSpace() ;
    test_findNonSpaceReverse() ;
    // test_findSpaceReverse() ; 
    // test_strcmp() ;
    // test_copy() ;
    // test_copyIf() ;
    // test_copyIfReverse() ;
}

int main() {
    test();

    return 0;
}