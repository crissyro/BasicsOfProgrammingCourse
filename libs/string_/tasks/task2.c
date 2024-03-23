#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void removeAdjacentEqualLetters(char *s) {
    char *destination = s;
    char *current = s + 1;

    while (*current != '\0') {
        if (*current != *destination) {
            destination++;
            *destination = *current;
        }

        current++;
    }

    destination++;
    *destination = '\0';
}

void test_removeAdjacentEqualLetters() {
    char source[] = "aaabbbcccdddeee";
    removeAdjacentEqualLetters(source);
    ASSERT_STRING("abcde", source);
}

void test() {
    test_removeAdjacentEqualLetters() ;
}

int main() {
    test();

    return 0;
}