#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getSmallestStringofNumbers(char* pattern) {
    int patternLength = strlen(pattern);
    int* resultArray = (int*)malloc(sizeof(int) * (patternLength + 1));

    resultArray[0] = 1;
    int currentNumber = 2;
    int lastIIndex = 0;

    for (int i = 0; i < patternLength; i++) {
        if (pattern[i] == 'I') {
            resultArray[i + 1] = currentNumber++;
            lastIIndex = i + 1;
        } else {
            for (int j = i; j >= lastIIndex; j--) {
                resultArray[j + 1] = resultArray[j];
            }
            resultArray[lastIIndex] = currentNumber++;
        }
    }

    char* resultString = (char*)malloc(sizeof(char) * (patternLength + 2));
    
    int index = 0;
    for (int i = 0; i <= patternLength; i++) {
        resultString[index++] = resultArray[i] + '0';
    }

    resultString[index] = '\0';

    free(resultArray);

    return resultString;
}

int main() {
    char pattern1[] = "IIIDIDDD";
    char *result1 = getSmallestStringofNumbers(pattern1);
    printf("Pattern: %s, Result: %s\n", pattern1, result1);
    free(result1);

    char pattern2[] = "DDD";
    char *result2 = getSmallestStringofNumbers(pattern2);
    printf("Pattern: %s, Result: %s\n", pattern2, result2);
    free(result2);

    return 0;
}