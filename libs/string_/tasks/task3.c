#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void digitToStart_(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void getDigitsAtBeginOfLetterAtEnd(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
       digitToStart_(word);
       beginSearch = word.end;
    }
}

void test_getDigitsAtBeginOfLetterAtEnd() {
    char source[] = "Hi123 Hello456";
    getDigitsAtBeginOfLetterAtEnd(source);
    ASSERT_STRING("123Hi 456Hello", source);
}

void test() {
    test_getDigitsAtBeginOfLetterAtEnd() ;
}

int main() {
    test();

    return 0;
}