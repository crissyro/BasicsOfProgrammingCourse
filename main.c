// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// #include <ctype.h>
// #include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"
// // #include "C:/Users/fatee/ClionProjects/course/libs/string_/tasks/string_processing.c"

// #define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
// #define MAX_STRING_SIZE

// char _stringBuffer[MAX_STRING_SIZE + 1];

// typedef struct WordDescriptor {
//     char *begin; // позиция начала слова
//     char *end; // позиция первого символа, после последнего символа слова
// } WordDescriptor;

// void digitToStart(WordDescriptor word) {
//     char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);

//     char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);

//     copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
// }

// void assertString(const char *expected, char *got,char const *fileName, char const *funcName, int line) {
//     if (strcmp(expected, got)) {
//         fprintf(stderr, "File %s\n", fileName);
//         fprintf(stderr, "%s - failed on line %d\n", funcName, line);
//         fprintf(stderr, "Expected: \"%s\"\n", expected);
//         fprintf(stderr, "Got: \"%s\"\n\n", got);
//     } else {
//         fprintf(stderr, "%s - OK\n", funcName);
//     }
// }

// void test_digitToStartTransform_oneWord() {
//     char s[] = "Hi123 ";
//     digitToStart(s);
//     ASSERT_STRING("321Hi", s);
// }

// void test() {
//     test_digitToStartTransform_oneWord() ;
// }

// int main() {
//     test();

//     return 0;
// }

#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void appendWords(char *str1, char *str2) {
    char *smallerStr;
    char *largerStr;

    int n1 = 1;
    for (int i = 0; i < strlen_(str1); i++) {
        if (str1[i] == ' ') {
            n1++;
        }
    }

    int n2 = 1;
    for (int i = 0; i < strlen_(str2); i++) {
        if (str2[i] == ' ') {
            n2++;
        }
    }

    if (n1 <= n2) {
        smallerStr = str1;
        largerStr = str2;
    } else {
        smallerStr = str2;
        largerStr = str1;
    }

    char *lastWordsStart = largerStr;
    for (int i = 0; i < n2 - n1; i++) {
        lastWordsStart = findSpace(lastWordsStart);
        if (lastWordsStart == NULL) {
            break;
        }
        lastWordsStart++;
    }

    copy(lastWordsStart, findNonSpaceReverse(largerStr + strlen_(largerStr), largerStr), smallerStr);
}

int main() {
    char str1[] = "The quick brown fox";
    char str2[] = "jumps over the lazy dog";

    printf("Before:\nString 1: %s\nString 2: %s\n", str1, str2);
    appendWords(str1, str2);
    printf("\nAfter:\nString 1: %s\nString 2: %s\n", str1, str2);

    return 0;
}