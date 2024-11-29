include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    char gender[10];
    char department[50];
    char college[50];
};

int main() {
    struct Student student;

    printf("Enter Name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; 

    printf("Enter Age: ");
    scanf("%d", &student.age);
    getchar(); 

    printf("Enter Gender: ");
    fgets(student.gender, sizeof(student.gender), stdin);
    student.gender[strcspn(student.gender, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(student.department, sizeof(student.department), stdin);
    student.department[strcspn(student.department, "\n")] = '\0';

    printf("Enter College: ");
    fgets(student.college, sizeof(student.college), stdin);
    student.college[strcspn(student.college, "\n")] = '\0';

    printf("\n--- Student Details ---\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Gender: %s\n", student.gender);
    printf("Department: %s\n", student.department);
    printf("College: %s\n", student.college);

    return 0;
}
