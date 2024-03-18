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