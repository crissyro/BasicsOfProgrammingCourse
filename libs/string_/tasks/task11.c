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