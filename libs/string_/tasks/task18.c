#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void appendWords(char *str1, char *str2) {
    char *smallerStr;
    char *largerStr;

    int n1 = 1;
    for (int i = 0; i < strlen_(str1); i++) {
        if (str1[i] == ' ') {
            n1++;
        }
    }

    int n2 = 1;
    for (int i = 0; i < strlen_(str2); i++) {
        if (str2[i] == ' ') {
            n2++;
        }
    }

    if (n1 <= n2) {
        smallerStr = str1;
        largerStr = str2;
    } else {
        smallerStr = str2;
        largerStr = str1;
    }

    char *lastWordsStart = largerStr;
    for (int i = 0; i < n2 - n1; i++) {
        lastWordsStart = findSpace(lastWordsStart);
        if (lastWordsStart == NULL) {
            break;
        }
        lastWordsStart++;
    }

    copy(lastWordsStart, findNonSpaceReverse(largerStr + strlen_(largerStr), largerStr), smallerStr);
}

int main() {
    char str1[] = "The quick brown fox";
    char str2[] = "jumps over the lazy dog";

    printf("Before:\nString 1: %s\nString 2: %s\n", str1, str2);
    appendWords(str1, str2);
    printf("\nAfter:\nString 1: %s\nString 2: %s\n", str1, str2);

    return 0;
}