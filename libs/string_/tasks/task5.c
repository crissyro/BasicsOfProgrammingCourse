#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

typedef struct {
    char *begin;
    char *end;
} WordDescriptor;

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char _stringBuffer[1000];

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, source + strlen_(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        if (strncmp(readPtr, word1.begin, w1Size) == 0) {
            copy(word2.begin, word2.end, recPtr);
            readPtr += w1Size;
            recPtr += w2Size;
        } else {
            *recPtr = *readPtr;
            readPtr++;
            recPtr++;
        }
    }
    *recPtr = '\0';
}

int main() {
    char source[] = "apple orange apple banana apple";
    char w1[] = "apple";
    char w2[] = "pear";

    printf("Before replacement: %s\n", source);
    replace(source, w1, w2);
    printf("After replacement: %s\n", source);

    return 0;
}