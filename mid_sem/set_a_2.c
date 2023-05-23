#include<stdio.h>
void main()
{
    int n;
    printf("Enter the number of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the %d element : ",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int flag=0;
    for (int i = 1; i < n-1; i++)
    {
        if ((arr[i-1]<arr[i]) && (arr[i]>arr[i+1]))
        {
            printf("\nThe peak element index is : %d",i);
            flag=1;
            break;
        }
        
    }
    if (flag==0)
    {
        printf("\nNot found");
    }
    
}