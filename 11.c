#include <stdio.h>

int search(int arr[], int target, int ll, int ul)
{
    int mid;
    mid = (ll + ul) / 2;

    if (ll <= ul)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            return search(arr, target, mid + 1, ul);
        }
        else if (arr[mid] > target)
        {
            return search(arr, target, ll, mid - 1);
        }
    }
    else
    {
        printf("search failed !");
        return -1;
    }
}

int main()
{
    int arr[10];
    printf("array created \n");

    for (int i = 0; i != 10; i++)
    {
        arr[i] = i;   // populate
    }

    for (int i = 0; i != 10; i++)
    {
        printf("%d \n", arr[i]);   // print
    }
    printf("array populated \n");

    int target;
    scanf("%d", &target);
    printf("%d", search(arr, target, 0, 9));

    return 0;
}
