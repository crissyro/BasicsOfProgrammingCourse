#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void getAlternatingWords(char *s1, char *s2, char *destination) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    char *endDestination = destination;

    while ((isW1Found = getWord(beginSearch1, &word1)),
           (isW2Found = getWord(beginSearch2, &word2)),
           isW1Found || isW2Found) {

        if (isW1Found) {
            char *word1Ptr = word1.begin;
            while (word1Ptr < word1.end) {
                *endDestination = *word1Ptr;
                endDestination++;
                word1Ptr++;
            }
            *endDestination = ' ';
            endDestination++;
        }

        if (isW2Found) {
            char *word2Ptr = word2.begin;
            while (word2Ptr < word2.end) {
                *endDestination = *word2Ptr;
                endDestination++;
                word2Ptr++;
            }
            *endDestination = ' ';
            endDestination++;
        }

        beginSearch1 = word1.end;
        beginSearch2 = word2.end;
    }

    endDestination--;
    *endDestination = '\0';
}

void test_getAlternatingWords() {
    char s1[] = "Hello World How Are You";
    char s2[] = "I Am Fine Thank You";
    char result[MAX_STRING_SIZE];

    getAlternatingWords(s1, s2, result);
    ASSERT_STRING("Hello I World Am How Fine Are Thank You You", result);
}

void test() {
    test_getAlternatingWords() ;
}

int main() {
    test();

    return 0;
}