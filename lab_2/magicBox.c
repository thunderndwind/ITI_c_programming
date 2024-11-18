#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void createMagicCode(int sideSize) {
    if(sideSize % 2 != 0){
        int boxSize=sideSize*sideSize;
        int currentRow = 0, currentCol = sideSize / 2;
        int counter = 1;

        for (int counter = 1; counter <= boxSize; counter++) {
            gotoxy(currentCol * 5 + 20, currentRow * 2 + 2);
            printf("%d", counter);
            Sleep(400);

            int nextRow = currentRow - 1;
            int nextCol = currentCol + 1;

            if (nextRow < 0) nextRow = sideSize - 1;
            if (nextCol >= sideSize) nextCol = 0;

            if (counter % sideSize == 0) {
                nextRow = currentRow + 1;
                nextCol = currentCol;
            }

            currentRow = nextRow;
            currentCol = nextCol;
        }
        printf("\n\n");

    }
    else{
        printf("The box side should be odd number");
    }

}
