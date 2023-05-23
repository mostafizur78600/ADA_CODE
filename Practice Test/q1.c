/*
Date: 31/03/2023
Name: Mostafizur Rahman

Given a limited range array of size n where array contains elements between 1 and
(n-1) with one element repeating, find the duplicate number in it.
*/

#include<stdio.h>
void main()
{
    int n;
    printf("\nEnter the number of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the %d element : \n",n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int j = 0; j < n; j++)
    {
        for (int k = j+1; k < n;k++)
        {
            if (arr[j]==arr[k])
            {
                printf("\nThe duplicate element : %d",arr[j]);
                break;
            }
        }
    }
}

//Time complexity is : n^2
//Space complexity is : n