#include <stdio.h>
#include <ctype.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int isPalindrome(char *word) {
    int len = strlen_(word);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(word[i]) != tolower(word[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

void removePalindromes(char *str) {
    char *start = str;
    char *end = str;
    int inWord = 0;

    while (*end) {
        if (isalnum(*end) && !inWord) {
            start = end;
            inWord = 1;
        } else if (!isalnum(*end) && inWord) {
            if (isPalindrome(start)) {
                while (start < end) {
                    *start = ' ';
                    start++;
                }
            }
            inWord = 0;
        }
        end++;
    }

    if (inWord && isPalindrome(start)) {
        while (start < end) {
            *start = ' ';
            start++;
        }
    }
}

int main() {
    char str[] = "Madam I am Adam madam";
    printf("%s\n", str);

    removePalindromes(str);

    printf("%s\n", str);

    return 0;
}