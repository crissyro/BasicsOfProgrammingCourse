#include <stdio.h>
#include <stdbool.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

bool isPalindrome(char *word) {
    char *start = word;
    char *end = word + strlen_(word) - 1;

    while (start < end) {
        if (tolower(*start) != tolower(*end)) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int getNumberOfPalindromes(char* s) {
    int count = 0;
    char *token = strtok_(s, ", ");

    while (token != NULL) {
        if (isPalindrome(token)) {
            count++;
        }

        token = strtok_(NULL, ", ");
    }

    return count;
}

void test_getNumberOfPalindromes() {
    char source[] = "level, radar, kayak, hello, civic, rotor";
    int number = getNumberOfPalindromes(source);
    char result[2];

    sprintf(result, "%d", number);
    ASSERT_STRING("5", result);
}

void test() {
    test_getNumberOfPalindromes() ;
}

int main() {
    test();

    return 0;
}