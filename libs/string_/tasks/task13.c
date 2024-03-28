#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

int checkForDuplicateWord(char *str) {
    int flag = 0;
    WordDescriptor word1, word2;
    
    while (getWord(str, &word1)) {
        char *index = word1.begin;
        
        while (getWord(index, &word2)) {
            if (strcmp_(word1.begin, word2.begin) == 0) {
                flag = 1;
                break;
            }
            index = word2.end;
        }
        
        if (flag == 1) {
            break;
        }
    }
    
    return flag;
}

void test_checkForDuplicateWord() {
    char source[] = "apple banana cherry apple";
    int number = checkForDuplicateWord(source);
    char result[MAX_STRING_SIZE];

    sprintf(result, "%d", number);
    ASSERT_STRING("1", result);
}

void test() {
    test_checkForDuplicateWord() ;
}

int main() {
    test();

    return 0;
}