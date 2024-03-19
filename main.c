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


// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main() {
//     char inputString[1000], currentWord[100], lastWord[100];
//     int i, j, wordEndPos, stringLength, wordLength;
//     char delimiters[] = {'.', ',', ':', ';', '!', '?', '-', ' ', '\t', '\n', '\r'};
//     int numDelimiters = sizeof(delimiters) / sizeof(delimiters[0]);

//     printf("Введите строку:\n");
//     gets(inputString);

//     stringLength = strlen(inputString);
//     wordEndPos = 0;
//     int isFirstWord = 1;

//     for (i = stringLength - 1; i >= 0; i--) {
//         if (strchr(delimiters, inputString[i]) != NULL) continue;

//         if (i == stringLength - 1 || strchr(delimiters, inputString[i + 1]) != NULL) wordEndPos = i;

//         if (i == 0 || strchr(delimiters, inputString[i - 1]) != NULL) {
//             wordLength = wordEndPos - i + 1;
//             strncpy(currentWord, inputString + i, wordLength);
//             currentWord[wordLength] = '\0';

//             if (isFirstWord) {
//                 isFirstWord = 0;
//                 strncpy(lastWord, currentWord, sizeof(lastWord));
//             } else if (strcmp(currentWord, lastWord) != 0) {
//                 for (j = wordLength - 2; j >= 0; j--) {
//                     if (currentWord[j] == currentWord[wordLength - 1]) {
//                         memmove(currentWord + j, currentWord + j + 1, wordLength - j);
//                     }
//                 }

//                 printf("%s\n", currentWord);
//             }
//         }
//     }

//     gets(inputString);

//     return 0;
// }


// #include <stdio.h>
// #include <string.h>

// int isAnagram(char *X, char *Y) {
//     int freqX[256] = {0};
//     int freqY[256] = {0};

//     int lenX = strlen(X);
//     int lenY = strlen(Y);

//     // Если длины строк не совпадают, то они не могут быть анаграммами
//     if (lenX != lenY) {
//         return 0;
//     }

//     for (int i = 0; i < lenX; i++) {
//         freqX[X[i]]++;
//         freqY[Y[i]]++;
//     }

//     for (int i = 0; i < 256; i++) {
//         if (freqX[i] != freqY[i]) {
//             return 0;
//         }
//     }

//     return 1;
// }

// int main() {
//     char X[] = "tommarvoloriddle";    // Том Марволо Риддл
//     char Y[] = "iamlordvoldemort";    // Я Лорд Волдеморт

//     if (isAnagram(X, Y)) {
//         printf("Anagram\n");
//     } else {
//         printf("Not an Anagram\n");
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int checkSameLettersPair(const char *s) {
    char *buffer = strdup(s);
    char *begin = buffer;
    char *end = buffer + strlen_(buffer);
    char *wordBegin = findNonSpace(buffer);
    char *wordEnd = findSpace(wordBegin);

    char **words = NULL;
    int count = 0;

    while (wordBegin < end) {
        size_t wordLen = wordEnd - wordBegin;
        char *word = (char *)malloc(wordLen + 1);
        copy(wordBegin, wordEnd, word);
        word[wordLen] = '\0';

        qsort(word, wordLen, sizeof(char), compare);

        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], word) == 0) {
                free(buffer);
                free(word);
                return 1;
            }
        }

        words = (char **)realloc(words, (count + 1) * sizeof(char *));
        words[count] = word;
        count++;

        wordBegin = findNonSpace(wordEnd);
        wordEnd = findSpace(wordBegin);
    }

    free(buffer);
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    
    free(words);

    return 0;
}

int main() {
    const char s[] = "cat tac silent hello world";
    if (checkSameLettersPair(s)) {
        printf("YES\n");
    } else {
        printf("Пара слов с одинаковым набором букв не найдена.\n");
    }

    return 0;
}