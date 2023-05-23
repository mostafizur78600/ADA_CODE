#include<stdio.h>
void main()
{
    int n,t;
    printf("Enter the number of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the %d element : ",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the target element : ");
    scanf("%d",&t);
    int flag=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((arr[i]+arr[j])==t)
            {
                printf("\nIndex of the two numbers such that they add up to target : %d, %d",i,j);
                flag=1;
                break;
            }
        }
        
    }
    if (flag==0)
    {
        printf("\nNot found");
    }
    
}