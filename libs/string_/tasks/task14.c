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