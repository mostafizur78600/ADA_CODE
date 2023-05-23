#include<stdio.h>
void main()
{
    int n,t;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the %d element in sort : ",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the target element : ");
    scanf("%d",&t);
    int start=-1,end=-1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==t)
        {
            start=i;
            break;
        }
    }
    int temp=0;
    for (int i = start; i < n; i++)
    {
        if(arr[i]==t)
        {
            temp+=1;
        }
        break;
    }
    if (temp!=0)
    {
        end=start+temp;
    }
    printf("\nThe starting and ending position of a given target value : %d, %d",start,end);
    
}