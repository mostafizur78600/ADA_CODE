#include<stdio.h>
int main()
{
    int a=0,b=1,x,c;
    printf("Enter number : ");
    scanf("%d",&x);
    if (x<2)
    {
        printf("%d",x);
    }
    else
    {
        printf("%d %d ",0,1);
        for (int i = 0; i < x-2; i++)
        {
            printf("%d ",a+b);
            c=b;
            b=a+b;
            a=c;
        }
    }
}