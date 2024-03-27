#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void getBagOfWords(BagOfWords *bag, char *s) {
    char *current = s;
    WordDescriptor word;
    int i = 0;
    while (getWord(current, &word)) {
        bag->words[i].begin = word.begin;
        bag->words[i].end = word.end;
        bag->size = i + 1;
        current = word.end + 1;
        i++;
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