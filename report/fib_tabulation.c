#include<stdio.h>
long long memo[100]={0};

long long fib(int n)
{
    long long f=0;
    for (int k = 1; k < n; k++)
    {
        if (k<=2)
            f=1;
        else
        {
            f=memo[k-1]+memo[k-2];
        }
        memo[k]=f;
    }
    return f;
}

int main()
{
    int n;
    printf("Enter number to find fib : ");
    scanf("%d",&n);
    fib(n);
    printf("\nThe fib series is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%lld ",memo[i]);
    }
}