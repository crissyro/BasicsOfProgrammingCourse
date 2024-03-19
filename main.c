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
#include <string.h>
#include <ctype.h>

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    if (s == NULL || strlen(s) == 0) {
        return EMPTY_STRING;
    }

    char *token = strtok(s, " ");
    char *prevWordEnd = NULL;
    char *currentWordBegin = NULL;

    while (token != NULL) {
        prevWordEnd = currentWordBegin;
        currentWordBegin = token;

        char *currentWordEnd = token + strlen(token);

        for (char *c = token; *c != '\0'; c++) {
            *c = tolower(*c);
        }

        if (strchr(token, 'a') != NULL) {
            if (prevWordEnd == NULL) {
                return FIRST_WORD_WITH_A;
            } else {
                w->begin = prevWordEnd;
                w->end = currentWordBegin;
                return WORD_FOUND;
            }
        }

        token = strtok(NULL, " ");
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

int main() {
    char s[] = "Hello world, this is a test string";
    WordDescriptor w;

    WordBeforeFirstWordWithAReturnCode result = getWordBeforeFirstWordWithA(s, &w);

    printf("%d", result);

    switch (result) {
        case FIRST_WORD_WITH_A:
            printf("Первое слово с 'a' является первым в строке.\n");
            break;
        case NOT_FOUND_A_WORD_WITH_A:
            printf("В строке нет слов с 'a'.\n");
            break;
        case WORD_FOUND:
            printf("Слово перед первым словом с 'a': ");
            for (char *c = w.begin; c < w.end; c++) {
                printf("%c", *c);
            }
            printf("\n");
            break;
        case EMPTY_STRING:
            printf("В строке нет слов.\n");
            break;
    }

    return 0;
}