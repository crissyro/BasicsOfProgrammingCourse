#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void removeAdjacentEqualLetters(char *s) {
    if (s == NULL || *s == '\0') {
        return;
    }

    int len = strlen_(s);
    int writeIndex = 0;

    for (int i = 1; i < len; i++) {
        if (s[i] != s[writeIndex]) {
            writeIndex++;
            s[writeIndex] = s[i];
        }
    }

    writeIndex++;
    s[writeIndex] = '\0';
}

void test_removeAdjacentEqualLetters() {
    char s[] = "aaabbbcccdddeee";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("abcde", s);
}

void test() {
    test_removeAdjacentEqualLetters() ;
}

int main() {
    test();

    return 0;
}