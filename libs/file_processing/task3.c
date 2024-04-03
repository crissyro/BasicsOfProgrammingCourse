#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("File opening error.\n");
        exit(1);
    }
    
    return file;
}

int generateRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

char generateRandomOperator() {
    char operators[] = {'+', '-', '*', '/'};
    return operators[rand() % 4];
}

int priorityOfOperations(char operation) {
    if (operation == '*' || operation == '/') {
        return 2;
    }

    if (operation == '+' || operation == '-') { 
        return 1;
    }

    return 0;
}

int applyOperator(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero.\n");
                exit(1);
            }
            return operand1 / operand2;
        default:
            printf("Error: Unknown operator '%c'.\n", operator);
            exit(1);
    }
}


int calculateExpression(int operand1, char operator1, int operand2, char operator2, int operand3) {
    int result1, result2;

    if (priorityOfOperations(operator1) >= priorityOfOperations(operator2) && operator2 != '\0') {
        result1 = applyOperator(operator1, operand1, operand2);
        result2 = applyOperator(operator2, result1, operand3);
    } else if (priorityOfOperations(operator1) < priorityOfOperations(operator2) && operator2 != '\0') {
        result1 = applyOperator(operator2, operand2, operand3);
        result2 = applyOperator(operator1, operand1, result1);
    } else {
        result2 = applyOperator(operator1, operand1, operand2);
    }

    return result2;
}

int main() {
    srand(time(NULL));

    FILE *file = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt", "w");

    char operator2 = '\0';
    if (rand() % 2 == 0) {
        operator2 = generateRandomOperator();
    }

    int operand1 = generateRandomInt(0, 9);
    int operand2 = generateRandomInt(0, 9);
    int operand3 = generateRandomInt(0, 9);
    char operator1 = generateRandomOperator();

    if (operator2 != '\0') {
        fprintf(file, "%d %c %d %c %d", operand1, operator1, operand2, operator2, operand3);
    } else {
        fprintf(file, "%d %c %d", operand1, operator1, operand2);
    }

    fclose(file);

    file = openFile("C:/Users/fatee/ClionProjects/course/libs/file_processing/input.txt", "r+");

    fscanf(file, "%d %c %d %c %d", &operand1, &operator1, &operand2, &operator2, &operand3);

    int result = calculateExpression(operand1, operator1, operand2, operator2, operand3);

    fseek(file, 0, SEEK_END);
    fprintf(file, "\n%d", result);

    fclose(file);

    printf("The result is written to a file input.txt\n");

    return 0;
}