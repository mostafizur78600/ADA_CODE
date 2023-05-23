#include<stdio.h>

long long fib(int n)
{
    if (n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    printf("Enter number to find fib : ");
    scanf("%d",&n);
    printf("\nThe fib series is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%lld ",fib(i));
    }
}