#include <stdio.h>
#include <stdbool.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

#define MAX_STRING_SIZE 100

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);
    
    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}


bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = rbegin;
    word->begin = findSpace(rbegin);

    if (word->begin == rend)
        return 0;

    word->begin = findNonSpace(word->begin);
    
    return 1;
}

int main() {
    char input[MAX_STRING_SIZE];
    WordDescriptor word;

    printf("Введите строку: ");
    fgets(input, MAX_STRING_SIZE, stdin);

    char *rbegin = input + strlen(input) - 1;
    char *rend = input - 1;

    while (getWordReverse(rbegin, rend, &word)) {
        digitToStart(word);
        rbegin = word.begin - 1;
    }

    return 0;
}