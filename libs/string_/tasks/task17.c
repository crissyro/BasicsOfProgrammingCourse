#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

// bool isPalindrome(char *str) {
//     int i = 0, j = 0;
//     while (str[j] != '\0') {
//         j++;
//     }
//     j--;

//     while (i < j) {
//         if (str[i++] != str[j--])
//             return false;
//     }

//     return true;
// }

bool isPalindrome(char *word) {
    int len = strlen_(word);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(word[i]) != tolower(word[len - i - 1])) {
            return false;
        }
    }

    return true;
}

void appendChar(char *str, char c) {
    while (*str) {
        str++;
    }
    *str = c;
    str++;
    *str = '\0';
}

void clearString(char *str, int size) {
    for (int i = 0; i < size; i++) {
        str[i] = '\0';
    }
}

char* removePalinWords(char *str) {
    char final_str[1000] = "";
    char word[100] = "";

    char space = ' ';
    char end_of_string = '\0';

    int n = 0;
    while (str[n] != '\0') {
        n++;
    }

    str[n] = space;

    int final_str_len = 0;

    for (int i = 0; i <= n; i++) {
        if (str[i] != ' ') {
            appendChar(word, str[i]);
        } else {
            if (!isPalindrome(word)) {
                int j = 0;
                while (word[j] != '\0') {
                    final_str[final_str_len++] = word[j++];
                }
                final_str[final_str_len++] = space;
            }

            clearString(word, sizeof(word));
        }
    }

    char *result = (char*)malloc(final_str_len + 1);
    for (int i = 0; i < final_str_len; i++) {
        result[i] = final_str[i];
    }
    result[final_str_len] = '\0';

    return result;
}

int main() {
    char str[] = "Text contains malayalam and level words";
    char *result = removePalinWords(str);
    printf("%s\n", result);
    free(result);

    return 0;
}

// void test_removePalinWords() {
//     char source[] = "Text contains malayalam and level words";
//     char *result = removePalinWords(source);
//     ASSERT_STRING("Text contains and words", result);
//     free(result);
// }

// void test() {
//     test_removePalinWords() ;
// }

// int main() {
//     test();

//     return 0;
// }