#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50

int main() {
    char name[MAX_EMPLOYEES][50], position[MAX_EMPLOYEES][50];
    int salary[MAX_EMPLOYEES];
    int num_employees = 0;

    // Get input from user
    scanf("%d", &num_employees);

    // Get the name, position, and salary for each employee
    for (int i = 0; i < num_employees; i++) {
        scanf("%s %s %d", name[i], position[i], &salary[i]);
    }

    // Output the employee details in the required format
    for (int i = 0; i < num_employees; i++) {
        printf("Name: %s\n", name[i]);
        printf("Position: %s\n", position[i]);
        printf("Salary: %d\n", salary[i]);
    }

    return 0;
}
