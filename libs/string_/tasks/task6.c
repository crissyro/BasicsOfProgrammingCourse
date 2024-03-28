#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    int len1 = w1.end - w1.begin;
    int len2 = w2.end - w2.begin;
    
    if (len1 != len2) {
        return 0;
    }
    
    return strncmp_(w1.begin, w2.begin, len1) == 0;
}

int checkLexicographicalOrder(char *source) {
    WordDescriptor currentWord, previousWord = {NULL, NULL};
    char *token = strtok_(source, " ");

    while (token != NULL) {
        currentWord.begin = token;
        currentWord.end = token + strlen_(token);

        if (previousWord.begin != NULL && (!areWordsEqual(previousWord, currentWord) && strcmp_(previousWord.begin, currentWord.begin) > 0)) {
            return 0;
        }
        
        previousWord = currentWord;
        token = strtok_(NULL, " ");
    }
 
    return 1;
}

void test_checkLexicographicalOrder() {
    char source[] = "apple banana cherry";
    int number = checkLexicographicalOrder(source);
    char result[MAX_STRING_SIZE];

    sprintf(result, "%d", number);
    ASSERT_STRING("1", result);
}

void test() {
    test_checkLexicographicalOrder();
}

int main() {
    test();

    return 0;
}