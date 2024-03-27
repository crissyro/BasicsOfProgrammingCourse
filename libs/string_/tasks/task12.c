#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void wordDescriptorToString(WordDescriptor word, char *destination) {
    copy(word.begin, word.end, destination);
    destination[word.end - word.begin] = '\0';
}

WordDescriptor lastWordInFirstStringInSecondString(char *str1, char *str2) {
    char *start = str1;
    char *end = str1 + strlen_(str1);

    WordDescriptor lastMatchingWord = {NULL, NULL};

    while (start < end) {
        char *wordStart = findNonSpace(start);
        char *wordEnd = findSpace(wordStart);

        WordDescriptor currentWord = {wordStart, wordEnd};

        if (currentWord.begin != currentWord.end) {
            char currentWordStr[MAX_STRING_SIZE];
            wordDescriptorToString(currentWord, currentWordStr);

            if (strstr_(str2, currentWordStr) != NULL) {
                lastMatchingWord = currentWord;
            }
        }

        start = wordEnd;
    }

    return lastMatchingWord;
}

void test_lastWordInFirstStringInSecondString() {
    char str1[] = "This is a test string";
    char str2[] = "Test this string for words";
    WordDescriptor lastMatchingWord = lastWordInFirstStringInSecondString(str1, str2);
    
    char result[MAX_STRING_SIZE];
    wordDescriptorToString(lastMatchingWord, result);
    ASSERT_STRING("string", result);
}

void test() {
    test_lastWordInFirstStringInSecondString() ;
}

int main() {
    test();

    return 0;
}