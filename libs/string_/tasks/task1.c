#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters() {
    char source[] = "Hi    123 ";
    removeNonLetters(source);
    ASSERT_STRING("Hi123", source);
}

void test() {
    test_removeNonLetters() ;
}

int main() {
    test();

    return 0;
}