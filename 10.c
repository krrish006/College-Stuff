#include <stdio.h>

union Data {
    int   i;
    float f;
    char  c;
};

int main() {
    union Data d;
    union Data *p = &d;   /* pointer to union */

    printf("Size of union Data = %zu bytes\n", sizeof(union Data));
    printf("Size of int = %zu, float = %zu, char = %zu\n\n",
           sizeof(int), sizeof(float), sizeof(char));

    /* ---------- Part 1: using the union variable ---------- */
    printf("===== Using union variable (d.member) =====\n");

    printf("Address of d   : %p\n", (void *)&d);
    printf("Address of d.i : %p\n", (void *)&d.i);
    printf("Address of d.f : %p\n", (void *)&d.f);
    printf("Address of d.c : %p\n\n", (void *)&d.c);

    /* Assign all three members one after another */
    d.i = 65;
    d.f = 3.14f;
    d.c = 'A';

    printf("After assigning all three (i = 65, f = 3.14, c = 'A'):\n");
    printf("d.i = %d\n", d.i);
    printf("d.f = %f\n", d.f);
    printf("d.c = %c\n\n", d.c);

    /* Show that only the last assigned member is reliable */
    d.i = 65;
    printf("After d.i = 65 :\n");
    printf("d.i = %d, d.f = %e, d.c = %c\n\n", d.i, d.f, d.c);

    d.f = 3.14f;
    printf("After d.f = 3.14 :\n");
    printf("d.i = %d, d.f = %f, d.c = %c\n\n", d.i, d.f, d.c);

    d.c = 'A';
    printf("After d.c = 'A' :\n");
    printf("d.i = %d, d.f = %e, d.c = %c\n\n", d.i, d.f, d.c);

    /* ---------- Part 2: using pointer to union ---------- */
    printf("===== Using pointer to union (p->member) =====\n");

    p->i = 100;
    printf("After p->i = 100 :\n");
    printf("p->i = %d, p->f = %e, p->c = %c\n\n", p->i, p->f, p->c);

    p->f = 2.5f;
    printf("After p->f = 2.5 :\n");
    printf("p->i = %d, p->f = %f, p->c = %c\n\n", p->i, p->f, p->c);

    p->c = 'Z';
    printf("After p->c = 'Z' :\n");
    printf("p->i = %d, p->f = %e, p->c = %c\n", p->i, p->f, p->c);

    return 0;
}
