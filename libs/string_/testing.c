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