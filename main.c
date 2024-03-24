// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>

// #define MAX_WORD_LEN 50

// typedef struct {
//     char *begin;
//     char *end;
// } WordDescriptor;

// char *findNonSpace(char *ptr) {
//     while (*ptr == ' ') {
//         ptr++;
//     }
//     return ptr;
// }

// char *findSpace(char *ptr) {
//     while (*ptr != ' ' && *ptr != '\0') {
//         ptr++;
//     }
//     return ptr;
// }

// int getWord(char *beginSearch, WordDescriptor *word) {
//     word->begin = findNonSpace(beginSearch);
//     if (*word->begin == '\0') {
//         return 0;
//     }

//     word->end = findSpace(word->begin);

//     return 1;
// }

// void alternateWords(char *s1, char *s2, char *result) {
//     WordDescriptor word1, word2;
//     bool isW1Found, isW2Found;
//     char *beginSearch1 = s1, *beginSearch2 = s2;
//     char *res = result;

//     while ((isW1Found = getWord(beginSearch1, &word1)),
//            (isW2Found = getWord(beginSearch2, &word2)),
//            isW1Found || isW2Found) {

//         if (isW1Found) {
//             while (word1.begin < word1.end) {
//                 *res++ = *word1.begin++;
//             }
//             *res++ = ' ';
//         }

//         if (isW2Found) {
//             while (word2.begin < word2.end) {
//                 *res++ = *word2.begin++;
//             }
//             *res++ = ' ';
//         }

//         beginSearch1 = word1.end;
//         beginSearch2 = word2.end;
//     }

//     *res = '\0';
// }

// int main() {
//     char s1[] = "Hello World How Are You";
//     char s2[] = "I Am Fine Thank You";
//     char result[MAX_WORD_LEN * 100]; // Assuming a maximum length for the result

//     alternateWords(s1, s2, result);

//     printf("Result: %s\n", result);

//     return 0;
// }

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