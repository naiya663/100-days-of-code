//Q120: Write a program to take a string input. Change it to sentence case.

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[200];
    
    // Read full line including spaces
    fgets(str, sizeof(str), stdin);
    
    int i = 0;

    // Convert first character if needed
    if (str[0] != '\0')
        str[0] = toupper(str[0]);

    // Traverse the string
    while (str[i] != '\0') {
        // If previous char is space, convert next char to uppercase
        if (str[i] == ' ' && str[i + 1] != '\0') {
            str[i + 1] = toupper(str[i + 1]);
        }
        i++;
    }

    printf("%s", str);

    return 0;
}



/*
Sample Test Cases:
Input 1:
str = I am trying to build logic.
Output 1:
I Am Trying To Build Logic

Input 2:
str = The classes are supposed to start early.
Output 2:
The Classes Are Supposed To Start Early.

Input 3:
str = We are going to look at 26 different test cases.
Output 3:
We Are Going To Look At 26 Different Test Cases.

*/