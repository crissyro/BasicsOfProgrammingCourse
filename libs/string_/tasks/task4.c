#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void replaceDigitsWithSpaces(char *source) {
    char array_without_numbers[MAX_STRING_SIZE];
    char *current = source;
    char *destination = array_without_numbers;

    while (*current != '\0') {
        if (isdigit(*current)) {
            int num_spaces = *current - '0';
            for (int j = 0; j < num_spaces; j++) {
                *destination = ' ';
                destination++;
            }
        } else {
            *destination = *current;
            destination++;
        }
        current++;
    }

    *destination = '\0';
    copy2(array_without_numbers, destination, source);
}

void test_replaceDigitsWithSpaces() {
    char source[] = "a2b3c1d";
    replaceDigitsWithSpaces(source);
    ASSERT_STRING("a  b   c d", source);
}

void test() {
    test_replaceDigitsWithSpaces() ;
}

int main() {
    test();

    return 0;
}