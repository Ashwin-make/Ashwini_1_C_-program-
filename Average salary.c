include <stdio.h>

int main() {
    int numEmployees, i;
    float salary, totalSalary = 0, averageSalary;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    if (numEmployees <= 0) {
        printf("Invalid number of employees.\n");
        return 1;
    }
    for (i = 0; i < numEmployees; i++) {
        printf("Enter the salary for employee %d: ", i + 1);
        scanf("%f", &salary);

        if (salary < 0) {
            printf("Salary cannot be negative. Try again.\n");
            i--;
            continue;
        }

        totalSalary += salary;
    }
    averageSalary = totalSalary / numEmployees;
    printf("The average salary of the employees is: %.2f\n", averageSalary);

    return 0;
}
