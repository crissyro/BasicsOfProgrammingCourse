#include <stdio.h>

#define MAX_N_WORDS_IN_STRING 100

typedef struct {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

void getBagOfWords(BagOfWords *bag, char *s) {
    char *p = s;
    bag->size = 0;

    while (*p != '\0') {
        while (*p == ' ') {
            p++;
        }

        if (*p == '\0') {
            break;
        }

        bag->words[bag->size].begin = p;

        while (*p != ' ' && *p != '\0') {
            p++;
        }

        bag->words[bag->size].end = p;
        bag->size++;
    }
}

int main() {
    char input[] = "Hello world from C programming";
    BagOfWords bag;
    getBagOfWords(&bag, input);

    for (int i = bag.size - 1; i >= 0; i--) {
        for (char *p = bag.words[i].begin; p < bag.words[i].end; p++) {
            printf("%c", *p);
        }
        printf("\n");
    }

    return 0;
}