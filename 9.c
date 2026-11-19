#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    struct Student s;

    printf("Enter name: ");
    scanf(" %49[^\n]", s.name);   /* reads a full name including spaces */

    printf("Enter age: ");
    scanf("%d", &s.age);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    printf("\n--- Student Details ---\n");
    printf("Name  : %s\n", s.name);
    printf("Age   : %d\n", s.age);
    printf("Marks : %.2f\n", s.marks);

    return 0;
}
