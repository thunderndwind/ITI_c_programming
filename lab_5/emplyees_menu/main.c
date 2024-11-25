#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "validations.h"

// Colors
#define RED 4
#define GREEN 2
#define BLUE 1
#define RESET 7

// Used keys
#define EXTENDED 224
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define EXIT 27
#define CHOOSE 13
#define HOME 71
#define END 79

// Constant values
#define MENU_ELEMENT_LENGTH 12
#define MAX_NAME_SIZE 40
#define MAX_EMPLOYEES_SIZE 100

typedef struct Employee {
    unsigned int code;
    char name[MAX_NAME_SIZE];
    unsigned int netSalary;
} Employee;

// Functions
void setColor(int color);
void gotoxy(int x, int y);
void printMenu(int selectedOption);
void addEmployees(Employee employees[], int *count);
void displayEmployees(Employee employees[], int count);
void modifyEmployee(Employee employees[], int *count);
void deleteEmployee(Employee employees[], int *count);
int getConsoleWidth();
int getConsoleHeight();
void clearConsole();

int main() {
    int flag = 1;
    int selectedOption = 0;
    int key;
    Employee employees[MAX_EMPLOYEES_SIZE] = {0};
    int employeesCounter = 0;

    while (flag) {
        clearConsole();
        printMenu(selectedOption);
        key = getch();
        if (key == EXTENDED) {
            key = getch();
            switch (key) {
                case UP:
                case LEFT:
                    selectedOption = (selectedOption - 1 + 5) % 5;
                    break;
                case DOWN:
                case RIGHT:
                    selectedOption = (selectedOption + 1) % 5;
                    break;
                case HOME:
                    selectedOption = 0;
                    break;
                case END:
                    selectedOption = 4;
                    break;
            }
        } else if (key == CHOOSE) {
            switch (selectedOption) {
                case 0:
                    addEmployees(employees, &employeesCounter);
                    break;
                case 1:
                    displayEmployees(employees, employeesCounter);
                    break;
                case 2:
                    modifyEmployee(employees, &employeesCounter);
                    break;
                case 3:
                    deleteEmployee(employees, &employeesCounter);
                    break;
                case 4:
                    flag = 0;
                    break;
            }
        }
    }
    return 0;
}

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

void clearConsole() {
    system("cls");
}

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return 80;
}

int getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    return 25;
}

void printMenu(int selectedOption) {
    const char menu[][MENU_ELEMENT_LENGTH] = {"Add", "Display", "Modify", "Delete", "Exit"};
    int consoleWidth = getConsoleWidth();
    int consoleHeight = getConsoleHeight();
    int centerX = (consoleWidth - MENU_ELEMENT_LENGTH) / 2;
    int startY = (consoleHeight - 5 * 3) / 2;

    for (int i = 0; i < 5; i++) {
        if (i == selectedOption) {
            setColor(BLUE);
        } else {
            setColor(RESET);
        }
        gotoxy(centerX, startY + i * 3);
        printf("%s\n", menu[i]);
    }
    setColor(RESET);
}

void addEmployees(Employee employees[], int *count) {
    int freeSpace = MAX_EMPLOYEES_SIZE - *count;
    if (freeSpace <= 0) {
        printf("There is no space to add new employees.\n");
        getch();
        return;
    }

    int numToAdd;
    printf("Enter ESC to return to main menu\n");
    printf("Enter the number of employees to add (max %d): ", freeSpace);
    if (getch() == EXIT){
        return;
    }
    fflush(stdin);
    numToAdd=validateNumber(1);

    if (numToAdd <= 0 || numToAdd > freeSpace) {
        printf("Invalid number of employees.\n");
        getch();
        return;
    }
    for (int i = 0; i < numToAdd; i++) {
        clearConsole();
        printf("Adding employee %d of %d\n", i + 1, numToAdd);
        Employee newEmployee;

        int isUnique = 1;
        do {
            printf("Enter unique employee code: ");
            fflush(stdin);
            newEmployee.code = validateNumber(1);
            for (int j = 0; j < *count; j++) {
                if (employees[j].code == newEmployee.code) {
                    printf("Code already exists. Try again.\n");
                    isUnique=0;                }else{
                    isUnique=1;
                    j = *count;
                }
            }
        } while (!isUnique);

        printf("Enter employee name: ");
        fflush(stdin);
        validateName(newEmployee.name, MAX_NAME_SIZE);

        printf("Enter employee net salary: ");
        fflush(stdin);
        newEmployee.netSalary = validateNumber(1);

        employees[*count] = newEmployee;
        (*count)++;
        printf("Employee added successfully.\n");
        if (i != numToAdd - 1){
        printf("Press any key to continue or ESC to return to menu.\n");
        if (getch() == EXIT) i = numToAdd;
        }
    }
        printf("Press any key to continue to menu.\n");
        getch();
}

void displayEmployees(Employee employees[], int count) {
    int consoleWidth = getConsoleWidth();
    int consoleHeight = getConsoleHeight();
    int centerX = (consoleWidth - 12) / 2;
    int startY = (consoleHeight - 5 * 3) / 2;
    int key;
    if (count == 0) {
        printf("No employees to modify.\n");
        printf("Press ESC or Continue to go to main menu");

        while(1){
            key = getch();
            if(key == EXIT || key == CHOOSE){
                return;
            }
        }
    }

    int flag = 1;
    clearConsole();
    if (employees[0].code!=0){
        printf("Employee List:\n");
    }
    for (int i = 0; i < count; i++) {
       // gotoxy(centerX, startY + i + i);
        printf("Code: %u, Name: %s, Net Salary: %u\n", employees[i].code, employees[i].name, employees[i].netSalary);
    }

    printf("\nPress ESC to return to menu.\n");
    while (flag) {
        int key = getch();
        if (key == EXIT) {
            flag = 0;
        }
    }
}

void modifyEmployee(Employee employees[], int *count) {
    int key;

    if (*count == 0) {
        printf("No employees to modify.\n");
        printf("Press ESC or Continue to go to main menu");

        while(1){
            key = getch();
            if(key == EXIT || key == CHOOSE){
                return;
            }
        }
    }

    int selected = 0;
    int flag = 1;
    while (flag) {
        clearConsole();
        for (int i = 0; i < *count; i++) {
            if (i == selected) {
                setColor(BLUE);
            } else {
                setColor(RESET);
            }
            printf("Code: %u, Name: %s, Net Salary: %u\n", employees[i].code, employees[i].name, employees[i].netSalary);
        }
        setColor(RESET);

        key = getch();
        if (key == EXTENDED) {
            key = getch();
            if (key == UP) selected = (selected - 1 + *count) % *count;
            if (key == DOWN) selected = (selected + 1) % *count;
        } else if (key == EXIT) {
            flag = 0;
        } else if (key == CHOOSE) {
            printf("Modify employee name (y/n)? \n");
            char choice = validateChoice();
            if (choice == 'y' || choice == 'Y') {
                printf("\nEnter new name: ");
                fflush(stdin);
                validateName(employees[selected].name, MAX_NAME_SIZE);
            }

            printf("Modify employee salary (y/n)? \n");
            choice = validateChoice();
            if (choice == 'y' || choice == 'Y') {
                printf("\nEnter new salary: ");
                employees[selected].netSalary = validateNumber(1);
            }
            flag = 0;
        }
    }
}

void deleteEmployee(Employee employees[], int *count) {
    int key;

    if (*count == 0) {
        printf("No employees to delete.\n");
        printf("Press ESC or Continue to go to main menu");

        while(1){
            key = getch();
            if(key == EXIT || key == CHOOSE){
                return;
            }
        }
    }

    int flag= 1;
    int selected = 0;
    while (flag) {
        clearConsole();
        for (int i = 0; i < *count; i++) {
            if (i == selected) {
                setColor(RED);
            } else {
                setColor(RESET);
            }
            printf("Code: %u, Name: %s, Net Salary: %u\n", employees[i].code, employees[i].name, employees[i].netSalary);
        }
        setColor(RESET);

        key = getch();
        if (key == EXTENDED) {
            key = getch();
            if (key == UP) selected = (selected - 1 + *count) % *count;
            if (key == DOWN) selected = (selected + 1) % *count;
        } else if (key == EXIT) {
            flag = 0;
        }else if (key == CHOOSE) {
            printf("Delete employee (y/n)? ");
            char choice = validateChoice();
            if (choice == 'y' || choice == 'Y') {
                for (int i = selected; i < *count - 1; i++) {
                    employees[i] = employees[i + 1];
                }
                (*count)--;
                printf("Employee deleted successfully.\n");
                printf("Press any key to continue.\n");
                getch();
                flag = 0;
            } else {
                flag = 0;
            }
        }
    }
}
