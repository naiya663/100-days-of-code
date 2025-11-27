// Q144: Write a function that accepts a structure as parameter and prints its members.

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

// Function that receives structure as parameter
void printStudent(struct Student s) {
    printf("Name: %s | Roll: %d | Marks: %.0f\n", s.name, s.roll, s.marks);
}

int main() {
    struct Student st;

    // Input
    printf("Enter Name: ");
    scanf("%s", st.name);

    printf("Enter Roll: ");
    scanf("%d", &st.roll);

    printf("Enter Marks: ");
    scanf("%f", &st.marks);

    // Function call
    printStudent(st);

    return 0;
}


/*
Sample Test Cases:
Input 1:
Student: Neha 104 92
Output 1:
Name: Neha | Roll: 104 | Marks: 92

*/