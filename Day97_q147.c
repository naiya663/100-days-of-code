/*
   QUESTION:
   Store employee data in a binary file using fwrite()
   and read it back using fread().
*/

#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

int main() {
    struct Employee emp;

    printf("Enter employee name: ");
    scanf("%s", emp.name);

    printf("Enter employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter salary: ");
    scanf("%f", &emp.salary);

    FILE *fp = fopen("employee.dat", "wb");
    if (fp == NULL) {
        printf("Error: Could not create file.\n");
        return 1;
    }

    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nEmployee data saved to employee.dat\n");

  
    struct Employee empRead;
    fp = fopen("employee.dat", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fread(&empRead, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nEmployee Details from File:\n");
    printf("Name: %s\n", empRead.name);
    printf("ID: %d\n", empRead.id);
    printf("Salary: %.2f\n", empRead.salary);

    return 0;
}