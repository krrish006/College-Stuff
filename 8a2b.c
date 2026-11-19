#include <stdio.h>

int main() {
    int r, c, i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int arr[r][c];

    printf("Enter %d integers (row by row):\n", r * c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Index\tAddress\t\t\tValue\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("[%d][%d]\t%p\t%d\n", i, j,
                   (void *)(*(arr + i) + j),
                   *(*(arr + i) + j));
        }
    }



    return 0;
}
