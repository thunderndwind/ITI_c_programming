#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_LEN 100
#define EXTENDED 224
#define ESC_KEY 27
#define LEFT_ARROW 75 // extended
#define RIGHT_ARROW 77 // extended
#define BACKSPACE_KEY 8
#define DELETE_KEY 83 // extended
#define SPACE_KEY ' '
#define INSERT_KEY 82 // extended
#define TAB_KEY '\t'

void printLine(const char *Line, const char *current, const char *tail, int mode);

int main() {
    char Line[MAX_LEN] = {0};
    char *head = Line;
    char *tail = Line;
    char *current = Line;
    int mode = 1;
    unsigned char ch;
    int running = 1;

    while (running) {
        printLine(Line, current, tail, mode);

        ch = getch();

        if (ch == ESC_KEY) {
            running = 0;
        } else if (ch == EXTENDED) {
            ch = getch();
            if (ch == LEFT_ARROW && current > head) {
                current--;
            } else if (ch == RIGHT_ARROW && current < tail) {
                current++;
            } else if (ch == INSERT_KEY){
                mode = (mode == 0) ? 1 : 0;
            } else if (ch == DELETE_KEY) {
            if (current < tail) {
                char *temp = current;
                while (temp < tail) {
                    *temp = *(temp + 1);
                    temp++;
                }
                tail--;
            }
        }
        } else if (ch == BACKSPACE_KEY) {
            if (current > head) {
                char *temp = current - 1;
                while (temp < tail) {
                    *temp = *(temp + 1);
                    temp++;
                }
                current--;
                tail--;
            }
        } else if (ch == SPACE_KEY) {
            if (mode == 1 && tail < Line + MAX_LEN) {
                char *temp = tail;
                while (temp > current) {
                    *temp = *(temp - 1);
                    temp--;
                }
                *current = ' ';
                current++;
                tail++;
            } else if (mode == 0 && current < Line + MAX_LEN) {
                *current = ' ';
                if (current == tail) {
                    tail++;
                }
                current++;
            }
        } else if (ch >= 32 && ch <= 126) {
            if (mode == 1 && tail < Line + MAX_LEN) {
                char *temp = tail;
                while (temp > current) {
                    *temp = *(temp - 1);
                    temp--;
                }
                *current = ch;
                current++;
                tail++;
            } else if (mode == 0 && current < Line + MAX_LEN) {
                *current = ch;
                if (current == tail) {
                    tail++;
                }
                current++;
            }
        }
    }

    printf("\nFinal Line: %s\n", Line);
    return 0;
}

void printLine(const char *Line, const char *current, const char *tail, int mode) {
    system("cls");
    printf("Line Editor (100 characters max)\n");
    printf("Use arrow keys, Backspace, Delete, Space, and Normal/Insert modes.\n");
    printf("Press 'ESC' to exit.\n");
    printf("\n");
    printf("Mode: %s | current: %ld | length: %ld\n\n\n\n", (mode == 1) ? "Normal" : "Insert", current - Line, tail - Line);

    for (const char *p = Line; p < tail; p++) {
        if (mode && p == current && p != tail){
            printf("|");
        }
        printf("%c", *p);
    }
    if (mode && tail == current){
            printf("|");
    }

    printf("\n");


    for (const char *p = Line; p < current; p++) {
        printf(" ");
    }
}
