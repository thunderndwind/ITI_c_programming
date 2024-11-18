#include <stdio.h>

void printUntilHundred() {
    printf("You will enter numbers until the sum reaches 100 or more.\n");
    int accumulater = 0;
    int inputNumber = 0;

    do {
        printf("Enter your number: ");
        scanf("%d", &inputNumber);
        accumulater += inputNumber;
    } while (accumulater < 100);

    printf("The final result is %d.\n", accumulater);
}
