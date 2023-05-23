
#include<stdio.h>

long long memo[100]={0};

long long fib(int n)
{
    if(memo[n]!=0)
        return memo[n];
    if (n==1 || n==2)
    {   
        memo[n]=1;
        return 1;
    }
    memo[n]=fib(n-1)+fib(n-2);
    return memo[n];
}

int main()
{
    int n;
    printf("Enter number to find fib : ");
    scanf("%d",&n);
    fib(n);
    printf("\nThe fib series is : \n");
    // memo[1]=1;
    // memo[2]=1;
    for (int i = 0; i < n; i++)
    {
        printf("%d = %lld\n",(i+1),memo[i]);
    }
    
}