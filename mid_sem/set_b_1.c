#include<stdio.h>
#include<limits.h>
void main()
{
    int n,k;
    printf("Enter number of element: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d element : ",n);
    for (int i = 0; i < n; i++)
    {
        
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the value of k : ");
    scanf("%d",&k);

    int max=INT_MIN,max_index;
    for (int j = 0; j < n; j++)
    {
        if (arr[j]>max)
        {
            max=arr[j];
            max_index=j;
        }
    }

    int h_arr[max+1];
    
    for (int i = 0; i < max+1; i++)
    {
        h_arr[i]=0;
    }

    for (int j = 0; j < n; j++)
    {
        h_arr[arr[j]]+=1;
    }

    int temp=INT_MIN,index;
    printf("\nThe %d most frequent element : ",k);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < max+1; j++)
        {
            if(h_arr[j]>temp)
            {
                temp=h_arr[j];
                index=j;
            }
        }
        printf("%d ",index);
        h_arr[index]=INT_MIN;
        temp=INT_MIN;
    }
}