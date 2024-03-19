#include <stdio.h>
#include <stdlib.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"
 
char *functionConvert(const char *s) {
    int size = strlen_(s);
    char *temp = malloc(size);
    int t_size = size-1;

    for (int i = 0; i < size; i++) {
        temp[i] = s[t_size-i];
    }
    
    return temp;
}
 
int main() {
    const char *s = "hello girls";
    char *newStr = functionConvert(s);
    printf("%s\n", newStr);
}