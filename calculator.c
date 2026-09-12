#include<stdio.h>

void result(char choice ,float a , float b)
{
    if (choice == '+')
    {
        printf("%.1f",a+b);
    }
    else if (choice == '-')
    {
        printf("%.1f",a-b);
    }
    else if (choice == '*')
    {
        printf("%.1f",a*b);
    }
    else if (choice == '/' && b != 0)
    {
        printf("%.1f",a/b);
    }
    else
    {
        printf("ERROR : kindly check input");
    }
    
}

int main()
{
    char choice;

    printf("Enter the operation needed : ");
    scanf("%c",&choice);

    float a,b;
    printf("Enter number 1 : ");
    scanf("%f",&a);

    printf("Enter number 2 : ");
    scanf("%f",&b);

    result(choice,a,b);


    return 0;
}
