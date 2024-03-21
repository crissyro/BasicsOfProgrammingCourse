#include <stdio.h>
#include <ctype.h>
#include "C:/Users/fatee/ClionProjects/course/libs/string_/string_.c"

#define MAX_STRING_SIZE 100

void replace_digits_with_spaces(char *input) {
    char buffer[MAX_STRING_SIZE];
    int buffer_index = 0;

    for (int i = 0; i < strlen_(input); i++) {
        if (isdigit(input[i])) {
            int num_spaces = input[i] - '0';
            for (int j = 0; j < num_spaces; j++) {
                buffer[buffer_index++] = ' ';
            }
        } else {
            buffer[buffer_index++] = input[i];
        }
    }

    buffer[buffer_index] = '\0';

    printf("%s\n", buffer);
}

int main() {
    char input[MAX_STRING_SIZE];

    printf("Введите строку: ");
    scanf("%s", input);

    replace_digits_with_spaces(input);

    return 0;
}