#include <stdio.h>
#include <stdlib.h>

#define SIZE 12
int main()
{
    int array[SIZE]={0};
    int flag=1;
    int rowsNumber=0;
    int colsNumber=0;
    do{
    printf("Enter number of rows for the 2d array of 12 elements: ");
    scanf(" %d", &rowsNumber);
    if(SIZE % rowsNumber == 0 && rowsNumber > 1){
        flag=0;
        system("cls");
    }else{
        printf("number of rows should be 12 factor and greater than 1\n");
    }

    }while(flag);
    colsNumber = SIZE/rowsNumber;

    for(int num=0; num<SIZE; num++){
        printf("Enter the number %d: ", num+1);
        scanf(" %d", &array[num]);
    }

    /*
    int counter=0;
    for(int i=0; i<rowsNumber; i++){
        for(int j=0; j<colsNumber; j++){
            printf("%d",array[counter]);
            counter++;

        }
        printf("\n");
    }
    */

    for(int i=0; i<rowsNumber; i++){
        for(int j=0; j<colsNumber; j++){
            printf("%d \t",array[i*colsNumber+j]);

        }
        printf("\n");
    }

    return 0;
}
