#include <stdio.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

void reverseWordsOrder(char *source) {
    char destination[MAX_STRING_SIZE];
    copy(source, source + strlen_(source), destination);

    char *rbegin = destination;
    char *current = source;

    while (*rbegin != '\0') {
        rbegin++;
    }

    int index = rbegin - destination - 1;
    int i = index;

    while (i >= 0) {
        while (i >= 0 && *(destination + i) != ' ') {
            i--;
        }

        int j = i + 1;
        while (j <= index) {
            *current = *(destination + j);
            current++;
            j++;
        }

        if (i >= 0) {
            *current = ' ';
            current++;
        }

        index = i - 1;
        i--;
    }

    *current = '\0';
}

void test_reverseWordsOrder() {
    char source[] = "apple orange banana";
    reverseWordsOrder(source);
    ASSERT_STRING("banana orange apple", source);
}

void test() {
    test_reverseWordsOrder() ;
}

int main() {
    test();

    return 0;
}