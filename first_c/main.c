#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Used variables
    int intNum1 = 12;
    float floatNum2 = 2.5;
    char char1 = 's';
    char inputChar;


    // Task 1
    printf("Number one is %d\n", intNum1);
    printf("Number two is %.2f\n", floatNum2);
    printf("First character is %c\n", char1);

    // Task 2
    printf("Enter a character:\n");
    scanf("%c", &inputChar);
    printf("The character you entered is %c and it's ASCII code is %d\n", inputChar, inputChar);

    // Task 3
    printf("The number %d in octal format is %o and in hexa format is %x\n", intNum1, intNum1, intNum1);

    return 0;
}
