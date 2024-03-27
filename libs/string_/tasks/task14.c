#include <stdio.h>
#include <stdlib.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int checkSameLettersPair(const char *s) {
    char *buffer = (char *)malloc(strlen_(s) + 1);
    copy(s, s + strlen_(s), buffer);

    BagOfWords bag;
    bag.size = 0;

    char *word = strtok_(buffer, " ");
    while (word != NULL) {
        qsort(word, strlen_(word), sizeof(char), compare);

        for (size_t i = 0; i < bag.size; i++) {
            if (strcmp_(bag.words[i].begin, word) == 0) {
                free(buffer);
                return 1;
            }
        }

        bag.words[bag.size].begin = (char *)malloc(strlen_(word) + 1);
        copy(word, word + strlen_(word), bag.words[bag.size].begin);
        bag.size++;

        word = strtok_(NULL, " ");
    }

    free(buffer);
    for (size_t i = 0; i < bag.size; i++) {
        free(bag.words[i].begin);
    }

    return 0;
}

void test_checkSameLettersPair() {
    char source[] = "cat tac hello world";
    int number = checkSameLettersPair(source);
    char result[MAX_STRING_SIZE];

    sprintf(result, "%d", number);
    ASSERT_STRING("1", result);
}

void test() {
    test_checkSameLettersPair() ;
}

int main() {
    test();

    return 0;
}