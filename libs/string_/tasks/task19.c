#include <stdio.h>
#include <ctype.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

#define CHAR_SET_SIZE 26

int allLettersPresent(char *str, char *word) {
    int wordLen = strlen_(word);

    int charSet[CHAR_SET_SIZE] = {0};

    for (int i = 0; i < wordLen; i++) {
        char c = tolower(word[i]);
        if (isalpha(c)) {
            charSet[c - 'a'] = 1;
        }
    }

    int missingLetters = wordLen;

    for (int i = 0; i < strlen_(str); i++) {
        char c = tolower(str[i]);
        if (isalpha(c) && charSet[c - 'a'] == 1) {
            charSet[c - 'a'] = 0;
            missingLetters--;
            if (missingLetters == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog";
    char word[] = "fox";

    printf("Word \"%s\" in string \"%s\": %s\n", word, str, allLettersPresent(str, word) ? "Present" : "Not present");

    return 0;
}