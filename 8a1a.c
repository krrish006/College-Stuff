#include <stdio.h>

int main() {
    int n, i;

    printf("===== CHAR ARRAY =====\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    char carr[n];
    printf("Enter %d characters (separated by spaces):\n", n);
    for (i = 0; i < n; i++) {
        scanf(" %c", &carr[i]);   /* leading space skips whitespace/newline */
    }

    printf("Index\tAddress\t\t\tValue\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%p\t%c\n", i, &carr[i], carr[i]);
    }


    printf("\n\n===== DOUBLE ARRAY =====\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double darr[n];
    printf("Enter %d double values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &darr[i]);   
    }

    printf("Index\tAddress\t\t\tValue\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%p\t%.2f\n", i, &darr[i], darr[i]);
    }


    return 0;
}
