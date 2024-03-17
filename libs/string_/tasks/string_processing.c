#include <stdio.h>
#include <ctype.h>
#include "string_processing.h"
#include "string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0') {
        return 0;
    }

    word->end = findSpace(word->begin);

    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);

    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}