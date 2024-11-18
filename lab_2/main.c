#include <stdio.h>
#include <stdlib.h>
#include "magicBox.h"
#include "tilHundred.h"
#include "simpleMinue.h"
#include "multipicationTable.h"

int main()
{
    // Task 1
    /* */
    int size=0;
    printf("please enter size of magic box:");
    scanf("%d",&size);
    createMagicCode(size);
    /* */

    // Task 2
    //printUntilHundred();

    // Task 3
    //showSimpleMinue();

    // Task 4
    //printMultiTableAsc();

    // Task 5
    //printMultiTableDes();

    return 0;
}
