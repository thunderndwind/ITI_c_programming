#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#define TRUE 1
#define FALSE 0

// Functions prototype
int getStringLength(const char string[], int maxSize);
char compareStrings(const char string1[], const char string2[], int maxSize);
char concatenateStrings(char destination[], const char source[], int maxSize);
char copyString(char destination[], const char source[], int maxSize);
void convertToLowerCase(char string[], int maxSize);
void convertToUpperCase(char string[], int maxSize);

#endif // MYSTRING_H_INCLUDED
