#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"
 
#define N 250
 
void getWord(char *str, int *index, char *word) {
    int j;
    while (str[*index] <= ' ' && str[*index] != '\0') {
        (*index)++;
    }
    
    j = 0;
    while (str[*index] > ' ' && str[*index] != '\0') {
        word[j] = str[*index];
        (*index)++;
        j++;
    }
    
    word[j] = '\0';
}
 
int compareStrings(char *str1, char *str2) {
    int i;
    for (i = 0; str1[i] == str2[i]; i++) {
        if (str1[i] == '\0') {
            return 0;
        }
    }
    
    return str1[i] - str2[i];
}
 
int checkForDuplicateWord(char *str) {
    int index = 0, flag = 0, j = 0;
    char word1[N], word2[N];
    
    while (str[index] != '\0' && flag == 0) {
        getWord(str, &index, word1);
        j = index;
        
        while (str[j] != '\0' && flag == 0) {
            getWord(str, &j, word2);
            if (compareStrings(word1, word2) == 0) {
                flag = 1;
            }
        }
    }
    
    return flag;
}
 
int main() {
    int flag;
    char input[N];
    gets(input);
 
    flag = checkForDuplicateWord(input);
 
    printf("flag = %d\n", flag);
    if (flag == 1) {
        printf("Duplicate word found\n");
    } else {
        printf("No duplicate words found\n");
    }
    
    return 0;
}