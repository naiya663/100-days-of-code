// Q123: Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        characters++;   // count character

        if (ch == '\n')
            lines++;    // count new line

        // word detection logic
        if (!isspace(ch) && inWord == 0) {
            inWord = 1;
            words++;
        }
        else if (isspace(ch)) {
            inWord = 0;
        }
    }

    fclose(fp);

    // If file is not empty but does not end with '\n', count last line
    if (characters > 0)
        lines++;

    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}


/*
Sample Test Cases:
Input 1:
File: sample.txt (Content: Hello world\nThis is C programming)
Output 1:
Characters: 31
Words: 5
Lines: 2

*/