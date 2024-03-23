#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void replaceAllOccurrencesOfWord(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        if (strncmp_(readPtr, word1.begin, w1Size) == 0) {
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

void test_replaceAllOccurrencesOfWord() {
    char source[] = "apple orange apple banana apple";
    char word1[] = "apple";
    char word2[] = "pear";
    replaceAllOccurrencesOfWord(source, word1, word2);
    ASSERT_STRING("pear orange pear banana pear", source);
}

void test() {
    test_replaceAllOccurrencesOfWord() ;
}

int main() {
    test();

    return 0;
}