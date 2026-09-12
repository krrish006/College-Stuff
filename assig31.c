#include<stdio.h>

int main()
{
    char ch;
    scanf("%c",&ch);

    printf("%d\n",ch);

    if (ch>96 && ch<123)    //for lowercase
    {
        printf("%c\n",ch-32);
    }
    else if (ch>64 && ch<91)    //for uppercase
    {
        printf("%c\n",ch-32);
    }

    printf("%c\n",ch+5);


    return 0;
}
