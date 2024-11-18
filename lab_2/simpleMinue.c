#include <stdio.h>

void showSimpleMinue() {
    int choiceNumber;

    printf("Here is the menue:\n");
    printf("a.Option one\n");
    printf("b.Option two\n");
    printf("c.Option three\n");
    printf("Enter your choice number: ");
    scanf("%d", &choiceNumber);

    switch (choiceNumber) {
        case 1:
            printf("You selected: Option One\n");
            break;
        case 2:
            printf("You selected: Option Two\n");
            break;
        case 3:
            printf("You selected: Option Three\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

}
