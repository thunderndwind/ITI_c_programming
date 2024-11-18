#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


// Colors
#define RED     4
#define GREEN   2
#define BLUE    1
#define RESET   7

// Used keys
#define EXTENDED 224
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define EXIT 27
#define CHOOSE 13

#define MENU_ELEMENT_LENGTH 8

// Functions
void setColor(int color);
void gotoxy(int x, int y);
void printMenu(int selectedOption);
int getConsoleWidth();

int main()
{
    int flag=1;
    int selectedOption = 0;
    int key;

    while(flag){
        system("cls");
        printMenu(selectedOption);
        key = getch();
        if (key == EXTENDED) {
            key = getch();
            switch (key) {
                case UP:
                case LEFT:
                    selectedOption = (selectedOption - 1 + 3) % 3;
                    break;
                case DOWN:
                case RIGHT:
                    selectedOption = (selectedOption + 1) % 3;
                    break;
            }
        } else if (key == CHOOSE) {
            switch (selectedOption) {
                case 0:
                    system("cls");
                    gotoxy(55,13);
                    printf("New\n");
                    break;
                case 1:
                    system("cls");
                    gotoxy(55,13);
                    printf("Display\n");
                    break;
                case 2:
                    flag = 0;
                    break;
            }
            if (flag) {
                do {
                    key = getch();
                } while (key != EXIT);

            }
        }

    }

    return 0;
}
        /*
        key = getch();
        printf("%d", key);
        if (key==EXTENDED){
            key = getch();
            printf("%d", key);
        }
        scanf(" %d", &flag);
        */


void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return 80; // Default to 80 if retrieval fails
}


void printMenu(int selectedOption) {
    char menu[][MENU_ELEMENT_LENGTH] = {"New", "Display", "Exit"};
    int consoleWidth = getConsoleWidth();
    int centerPoint = (consoleWidth - MENU_ELEMENT_LENGTH) / 2;
    for (int i = 0; i < 3; i++) {
        if (i == selectedOption) {
            setColor(BLUE);
        } else {
            setColor(RESET);
        }
        gotoxy(centerPoint, i*3+10);
        printf("%s\n", menu[i]);
    }
    setColor(RESET);
}
