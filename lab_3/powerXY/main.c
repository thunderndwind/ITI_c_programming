#include <stdio.h>
#include <stdlib.h>

float getPowerOfXY(int x, int y);

int main()
{
    int x = 2;
    int y = 3;

    float twoPowerOfThree = getPowerOfXY(x, y);
    printf("result of %d to the power of %d is %.2f\n", x, y, twoPowerOfThree);

    return 0;
}

float getPowerOfXY(int x, int y){
    if(y == 0){
        return 1;
    }
    if(y>0){
        return x * getPowerOfXY(x, y-1);
    }
    else{
        return 1.0/getPowerOfXY(x, -y);
    }
}
