#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

char* removePalinWords(char *str) {
    char final_str[MAX_STRING_SIZE];
    int final_str_len = 0;

    char space = ' ';

    char *token = strtok_(str, " ");
    while (token != NULL) {
        if (!isPalindrome(token)) {
            while (*token) {
                final_str[final_str_len++] = *token;
                token++;
            }
            final_str[final_str_len++] = space;
        }
        token = strtok_(NULL, " ");
    }

    char *result = (char*)malloc(final_str_len);
    copy(final_str, final_str + final_str_len-1, result);

    return result;
}

void test_removePalinWords() {
    char source[] = "Text contains malayalam and level words";
    char *result = removePalinWords(source);
    ASSERT_STRING("Text contains and words", result);
}

void test() {
    test_removePalinWords() ;
}

int main() {
    test();

    return 0;
}