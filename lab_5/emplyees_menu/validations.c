#include "validations.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 40
#define TRUE 1
#define FALSE 0

static char isValidNumber(const char input[], char isPositive) {
    int i = 0;

    if (input[0] == '\0') {
        return FALSE;
    }

    if (input[0] == '-' && isPositive) {
        return FALSE;
    }
    if (input[0] == '-' || input[0] == '+') {
        i++;
    }

    for (; input[i] != '\0'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return FALSE;
        }
    }

    if (isPositive) {
        long int number = strtol(input, NULL, 10);
        if (number <= 0) {
            return FALSE;
        }
    }

    return TRUE;
}

long int validateNumber(char isPositive) {
    char input[MAX_INPUT_SIZE];
    long int validNumber = 0;
    char flag=TRUE;
    while (flag) {
        fgets(input, MAX_INPUT_SIZE, stdin);
        //printf("the input is %s\n", input);

        unsigned int len = strlen(input);
        if (len > 1 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (isValidNumber(input, isPositive)) {
            validNumber = strtol(input, NULL, 10);
            flag=FALSE;
        } else {
            printf("Invalid input\n");
            printf("Enter a %snumber: ", isPositive ? "positive " : "");

        }
    }

    return validNumber;
}

static char isValidName(const char input[]) {
    int i = 0;

    if (input[0] == '\0') {
        return FALSE;
    }

    for (i = 0; input[i] != '\0'; i++) {
        if (!(isalpha(input[i]) || input[i] == ' ' || input[i] == '-')) {
            return FALSE;
        }
    }

    return TRUE;
}

void validateName(char output[], unsigned int maxSize) {
    char input[MAX_INPUT_SIZE];
    char isInputValid = FALSE;

    while (isInputValid == FALSE) {
        fgets(input, MAX_INPUT_SIZE, stdin);

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (isValidName(input) && strlen(input) < maxSize) {
            isInputValid = TRUE;

            strncpy(output, input, maxSize - 1);
            output[maxSize - 1] = '\0';
        } else {
            printf("Invalid input\n");
            printf("Enter a valid name (letters, spaces, hyphens): ");
        }
    }
}

