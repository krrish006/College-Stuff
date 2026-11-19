#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
  
    printf("Index\tAddress\t\t\tValue\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%p\t%d\n", i, &arr[i], arr[i]);
    }

    return 0;
}
