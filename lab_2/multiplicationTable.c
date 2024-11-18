#include <stdio.h>
void printMultiTableAsc() {
    printf("The multiplication table in ascending order\n");
    for (int i = 1; i <= 10; i++) {
        printf("\nMultiplication Table for %d:\n", i);
        for (int j = 1; j <= 10; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("**************************************\n");
    }
}
void printMultiTableDes(){
    for (int i = 10; i >= 1; i--) {
        printf("\nMultiplication Table for %d:\n", i);
        for (int j = 1; j <= 10; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("**************************************\n");
    }
}
