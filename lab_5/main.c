#include <stdio.h>
#include <stdlib.h>
#include "myString.h"

#define MAX_STRING_SIZE 100

int main()
{
    char string1[MAX_STRING_SIZE] = "hello";
    char string2[MAX_STRING_SIZE] = " world";
    char result[MAX_STRING_SIZE] = "";
    const char str1[] = "apple";
    const char str2[] = "applepie";

    printf("Length of string1 = %d\n", getStringLength(string1, MAX_STRING_SIZE));
    printf("Length of string2 = %d\n", getStringLength(string2, MAX_STRING_SIZE));

    int compareResult = compareStrings(str1, str2, 10);

    if (compareResult < 0) {
        printf("'%s' is lexicographically less than '%s'\n", str1, str2);
    } else if (compareResult > 0) {
        printf("'%s' is lexicographically greater than '%s'\n", str1, str2);
    } else {
        printf("'%s' is equal to '%s'\n", str1, str2);
    }

    if (concatenateStrings(result, string1, MAX_STRING_SIZE)) {
        printf("After concatenation: %s\n", result);
    } else {
        printf("Concatenation failed.\n");
    }

    if (concatenateStrings(result, string2, MAX_STRING_SIZE)) {
        printf("After concatenation: %s\n", result);
    } else {
        printf("Concatenation failed.\n");
    }

    if (copyString(result, string1, MAX_STRING_SIZE)) {
        printf("After copying: %s\n", result);
    } else {
        printf("Copying failed.\n");
    }

    printf("Original string1: %s\n", string1);
    convertToLowerCase(string1, MAX_STRING_SIZE);
    printf("After convertToLowerCase: %s\n", string1);

    printf("Original string1: %s\n", string1);
    convertToUpperCase(string1, MAX_STRING_SIZE);
    printf("After convertToUpperCase: %s\n", string1);

    return 0;
}
