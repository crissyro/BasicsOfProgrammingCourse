#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

char* getEndOfString(char* s) {
    char* end = s;
    
    if (s && *s) {
        while(*end) {
            end++;
        }
        end--;
    }
    
    return end;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters() {
    char s[] = "Hi    123 ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test() {
    test_removeNonLetters() ;
}

int main() {
    test();

    return 0;
}