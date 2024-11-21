#include "myString.h"
#define TRUE 1
#define FALSE 0

int getStringLength(const char string[], int maxSize) {
    int length = 0;
    while (length < maxSize && string[length] != '\0') {
        length++;
    }
    return length;
}

char compareStrings(const char string1[], const char string2[], int maxSize) {
    for (int i = 0; i < maxSize; i++) {
        if (string1[i] == '\0' && string2[i] == '\0') {
            return 0;
        }
        if (string1[i] != string2[i]) {
            return (unsigned char)string1[i] - (unsigned char)string2[i];
        }
    }
    return 0;
}

char concatenateStrings(char destination[], const char source[], int maxSize) {
    int destLength = getStringLength(destination, maxSize);
    int srcLength = getStringLength(source, maxSize);

    if (destLength + srcLength >= maxSize) {
        return FALSE;
    }

    for (int i = 0; i < srcLength && destLength + i < maxSize - 1; i++) {
        destination[destLength + i] = source[i];
    }
    destination[destLength + srcLength] = '\0';
    return TRUE;
}

char copyString(char destination[], const char source[], int maxSize) {
    int i = 0;
    while (i < maxSize - 1 && source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }

    if (i < maxSize) {
        destination[i] = '\0';
        return TRUE;
    }
    return FALSE;
}

void convertToLowerCase(char string[], int maxSize) {
    for (int i = 0; i < maxSize && string[i] != '\0'; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32;
        }
    }
}

void convertToUpperCase(char string[], int maxSize) {
    for (int i = 0; i < maxSize && string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32;
        }
    }
}
