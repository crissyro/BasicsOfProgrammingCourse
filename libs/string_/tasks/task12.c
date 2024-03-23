#include <stdio.h>
#include <stdlib.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

void wordDescriptorToString(WordDescriptor word, char *destination) {
    copy(word.begin, word.end, destination);
    destination[word.end - word.begin] = '\0';
}

char * mystrstr(const char * mainStr, const char * subStr) {
    char *s1, *s2;
 
    while( *mainStr != NULL) {
        if(*mainStr == *subStr) {
            s1 = mainStr;
            s2 = subStr;
 
            while (*s1 && *s2 ) {
                if(*s1 != *s2)
                    break;
 
                s1++;
                s2++;
            }
            
            if (*s2 == NULL) {
                return mainStr;
            }
        }
 
        mainStr++;
    }
 
    return NULL;
}

WordDescriptor findLastMatchingWord(char *str1, char *str2) {
    char *start = str1;
    char *end = str1 + strlen_(str1);

    WordDescriptor lastMatchingWord = {NULL, NULL};

    while (start < end) {
        char *wordStart = findNonSpace(start);
        char *wordEnd = findSpace(wordStart);

        WordDescriptor currentWord = {wordStart, wordEnd};

        if (currentWord.begin != currentWord.end) {
            char currentWordStr[50];
            wordDescriptorToString(currentWord, currentWordStr);

            if (mystrstr(str2, currentWordStr) != NULL) {
                lastMatchingWord = currentWord;
            }
        }

        start = wordEnd;
    }

    return lastMatchingWord;
}

int main() {
    char str1[] = "This is a test string";
    char str2[] = "Test this string for words";

    WordDescriptor lastMatchingWord = findLastMatchingWord(str1, str2);

    if (lastMatchingWord.begin != NULL) {
        char lastWord[50];
        wordDescriptorToString(lastMatchingWord, lastWord);
        printf("Last matching word: %s\n", lastWord);
    } else {
        printf("No matching words found.\n");
    }

    return 0;
}

// void test_removeNonLetters() {
//     char str1[] = "This is a test string";
//     char str2[] = "Test this string for words";
//     wordDescriptorToString(word, string);
//     findLastMatchingWord(s);
//     ASSERT_STRING("Hi123", s);
// }

// void test() {
//     test_removeNonLetters() ;
// }

// int main() {
//     test();

//     return 0;
// }