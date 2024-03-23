#include <stdio.h>
#include <stdbool.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

bool isPalindrome(char *word) {
    int len = strlen_(word);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(word[i]) != tolower(word[len - i - 1])) {
            return false;
        }
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