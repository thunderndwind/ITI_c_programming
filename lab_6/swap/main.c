#include <stdio.h>
#include <stdlib.h>

void swapArithmitic(int *numberOne, int *numberTwo);
void swapXOR(int *numberOne, int *numberTwo);
void swapMultiple(int *numberOne, int *numberTwo);
void swapOneLine(int *numberOne, int *numberTwo);
void swapBitWise(int *numberOne, int *numberTwo);

int main()
{
    int num1 = 5;
    int num2 = 7;
    printf("before arith swap %d %d \n", num1, num2);
    swapArithmitic(&num1, &num2);
    printf("after arith swap %d %d \n\n", num1, num2);

    printf("before XOR swap %d %d \n", num1, num2);
    swapXOR(&num1, &num2);
    printf("after XOR swap %d %d \n\n", num1, num2);

    printf("before multiple swap %d %d \n", num1, num2);
    swapMultiple(&num1, &num2);
    printf("after multiple swap %d %d \n\n", num1, num2);

    printf("before OneLine swap %d %d \n", num1, num2);
    swapOneLine(&num1, &num2);
    printf("after OneLine swap %d %d \n\n", num1, num2);

    printf("before BitWise swap %d %d \n", num1, num2);
    swapBitWise(&num1, &num2);
    printf("after BitWise swap %d %d \n", num1, num2);

    return 0;
}


void swapArithmitic(int *numberOne, int *numberTwo){
    *numberOne += *numberTwo;
    *numberTwo = *numberOne - *numberTwo;
    *numberOne = *numberOne - *numberTwo;
}

void swapXOR(int *numberOne, int *numberTwo){
    *numberOne ^= *numberTwo;
    *numberTwo ^= *numberOne;
    *numberOne ^= *numberTwo;

}

void swapMultiple(int *numberOne, int *numberTwo){
    if((*numberOne != 0) && (*numberTwo != 0)){
        *numberOne *= *numberTwo;
        *numberTwo = *numberOne / *numberTwo;
        *numberOne /= *numberTwo;
    }
    else if (*numberOne == 0){
        *numberOne = *numberTwo;
        *numberTwo = 0;
    }
    else if (*numberTwo == 0){
        *numberTwo = *numberOne;
        *numberOne = 0;
    }


}

void swapOneLine(int *numberOne, int *numberTwo){
    *numberOne = ((*numberOne) * (*numberTwo)) / (*numberTwo = *numberOne);
}

void swapBitWise(int *numberOne, int *numberTwo){

    *numberOne = (*numberOne & *numberTwo) + (*numberOne | *numberTwo);
    *numberTwo = *numberOne + (~*numberTwo) + 1;
    *numberOne = *numberOne + (~*numberTwo) + 1;

}
