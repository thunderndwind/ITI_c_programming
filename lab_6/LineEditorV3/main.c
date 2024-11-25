#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// Constants
#define MAX_LEN 100
#define EXTENDED 224
#define ESC_KEY 27
#define LEFT_ARROW 75 // Extended
#define RIGHT_ARROW 77 // Extended
#define BACKSPACE_KEY 8
#define DELETE_KEY 83 // Extended
#define SPACE_KEY ' '
#define INSERT_KEY 82 // Extended
#define TAB_KEY '\t'

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    char Line[MAX_LEN] = {0};
    int pos = 0;
    int len = 0;
    int insert_mode = 1;
    char running = 1;

    printf("\n");
    gotoxy(1, 2);

    while (running) {
        int ch = getch();

        if (ch == EXTENDED) {
            ch = getch();

            if (ch == LEFT_ARROW && pos > 0) {
                pos--;
                gotoxy(pos + 1, 2);
            } else if (ch == RIGHT_ARROW && pos < len) {
                pos++;
                gotoxy(pos + 1, 2);
            }

            else if (ch == INSERT_KEY) {
                insert_mode = !insert_mode;
            }

            else if (ch == DELETE_KEY && pos < len) {
                memmove(&Line[pos], &Line[pos + 1], len - pos - 1);
                len--;
                Line[len] = '\0';

                gotoxy(1, 2);
                printf("%-*s", MAX_LEN, Line);
                gotoxy(pos + 1, 2);
            }

        }else {

        if (ch == ESC_KEY) {
            running = 0;
        }

        if (ch == BACKSPACE_KEY && pos > 0) {
            memmove(&Line[pos - 1], &Line[pos], len - pos);
            pos--;
            len--;
            Line[len] = '\0';

            gotoxy(1, 2);
            printf("%-*s", MAX_LEN, Line);
            gotoxy(pos + 1, 2);
        } else{

            if (ch >= SPACE_KEY && ch <= '~') {
                if (insert_mode) {
                    if (len < MAX_LEN - 1) {
                        memmove(&Line[pos + 1], &Line[pos], len - pos);
                        Line[pos] = ch;
                        len++;
                        pos++;
                    }
                } else { // Overwrite mode
                    if (pos < MAX_LEN - 1) {
                        Line[pos] = ch;
                        pos++;
                        if (pos > len) len++;
                    }
                }

                gotoxy(1, 2);
                printf("%-*s", MAX_LEN, Line);
                gotoxy(pos + 1, 2);
            }
        }
        }
    }


    return 0;
}
