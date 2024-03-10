#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
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

void test_findSpaceReverse() {
    const char text1[] = "   \t  Hello, World!";
    char *rbegin1 = (char*)(text1 + sizeof(text1) - 2); 
    const char *rend1 = text1 - 1;
    
    char *result1 = findSpaceReverse(rbegin1, rend1);
    printf("%s\n", result1);
    assert(*result1 == ' ');

    const char text2[] = "ThisHasNoSpace";
    char *rbegin2 = (char*)(text2 + sizeof(text2) - 2); 
    const char *rend2 = text2 - 1;

    char *result2 = findSpaceReverse(rbegin2, rend2);
    assert(result2 == rend2);
}

void test_strcmp() {
    assert(strcmp("hello", "hello") == 0);
    assert(strcmp("hello", "world") < 0);
    assert(strcmp("apple", "app") > 0);
    assert(strcmp("", "hello") < 0);
    assert(strcmp("world", "") > 0);
}