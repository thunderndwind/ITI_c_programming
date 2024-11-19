#include <stdio.h>
#define ROW 3
#define COL 4

int main() {
    int arr[ROW][COL] = {0};
    int rowSum[ROW] = {0};
    int colSum[COL] = {0};
    int input=0;
    int flag = 1;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            while (flag) {
                printf("Please enter element number[%d][%d]: ", i, j);
                if (scanf("%d", &input) == 1) {
                    arr[i][j] = input;
                    flag = 0;
                } else {
                    printf("Invalid input! Please enter an integer.\n");
                    while (getchar() != '\n');
                }
            }
            flag = 1;
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
    }

    printf("\nThe entered 2D array is:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nThe sum of each row is:\n");
    for (int i = 0; i < ROW; i++) {
        printf("Row %d: %d\n", i + 1, rowSum[i]);
    }

    printf("\nThe average of each column is:\n");
    for (int j = 0; j < COL; j++) {
        printf("Column %d: %.2f\n", j + 1, (float)colSum[j] / ROW);
    }

    return 0;
}
