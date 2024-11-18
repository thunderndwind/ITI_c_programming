#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int getMinNumber(int setOfNumbers[], int size);
int getMaxNumber(int setOfNumbers[], int size);
int main()
{
    int numbers[ARRAY_SIZE] = {0, 1, 2, 8, 5, 9, 6, 7, 10, 3};

    int minNumber = getMinNumber(numbers, ARRAY_SIZE);
    int maxNumber = getMaxNumber(numbers, ARRAY_SIZE);

    printf("Minimum number: %d\n", minNumber);
    printf("Maximum number: %d\n", maxNumber);

    return 0;
}


int getMinNumber(int setOfNumbers[], int size){
    int min = setOfNumbers[0];
    for (int i=1; i<size; i++){
        if (setOfNumbers[i]<min){
            min = setOfNumbers[i];
        }
    }
    return min;
}
int getMaxNumber(int setOfNumbers[], int size){
    int max = setOfNumbers[0];

    for (int i=1; i<size; i++){
        if (setOfNumbers[i]>max){
            max = setOfNumbers[i];
        }
    }
    return max;
}
