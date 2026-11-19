#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    int n, i;
    float sum = 0.0f, average;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student s[n];   /* array of structure variables */

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter name: ");
        scanf(" %49[^\n]", s[i].name);

        printf("Enter age: ");
        scanf("%d", &s[i].age);

        printf("Enter marks: ");
        scanf("%f", &s[i].marks);

        sum += s[i].marks;
    }

    average = sum / n;

    printf("\n--- Student Details ---\n");
    printf("%-5s %-20s %-5s %-8s\n", "No.", "Name", "Age", "Marks");
    for (i = 0; i < n; i++) {
        printf("%-5d %-20s %-5d %-8.2f\n", i + 1, s[i].name, s[i].age, s[i].marks);
    }

    printf("\nTotal marks   : %.2f\n", sum);
    printf("Average marks : %.2f\n", average);

    return 0;
}
