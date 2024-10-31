#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *changeString(char *s, int *indices) {
    int len = strlen(s);
    char *result = (char *)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        result[indices[i]] = s[i];
    }

    result[len] = '\0';

    return result;
}

void test_changeString() {
    char s1[] = "abc";
    int indices1[] = {0, 1, 2};

    char s2[] = "abap";
    int indices2[] = {0, 3, 2, 1};

    char *result1 = changeString(s1, indices1);
    char *result2 = changeString(s2, indices2);

    printf("s = \"%s\" and indices = [0, 1, 2]\nResult: \"%s\"\n", s1, result1);
    printf("\ns = \"%s\" and indices = [0, 3, 2, 1]\nResult: \"%s\"\n", s2, result2);

    free(result1);
    free(result2);
}

int main() {
    test_changeString() ;

    return 0;
}