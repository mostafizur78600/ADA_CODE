/*
Date: 31/03/2023
Name: Mostafizur Rahman

Given a limited range array of size n where array contains elements between 1 and
(n-1) with one element repeating, find the duplicate number in it.
*/

#include<stdio.h>

int partition(int a[], int p, int r)  // function to partition the array
{
    int x = a[r], i = p - 1, temp;
    for (int j = p; j <= r - 1; j++)   // loop from p to r - 1
    {
        // check if element a[j] is less than or equal to pivot x
        if ((a[j]) <= x)//check element
        {
            // increment i and swap a[i] and a[j]
            i = i + 1;
            temp = a[i];
            a[i] = a[j]; //swap value
            a[j] = temp;
        }
    }
    // swap a[i + 1] and a[r]
    temp = a[i + 1];
    a[i + 1] = a[r]; //swap value
    a[r] = temp;
    // return the index of pivot element
    return i + 1;// return 
}

void quick_sort(int a[], int p, int r)  // function to perform quicksort
{
    if (p < r)      // check if p < r
    {
        // partition the array around pivot
        int q = partition(a, p, r);//call partition with array,start index,last index
        // recursively quicksort the left subarray
        quick_sort(a, p, q - 1);//recursion call of quick_sort for left part
        // recursively quicksort the right subarray
        quick_sort(a, q + 1, r);//recursion call of quick_sort for right part
    }
}

// main function
void main()
{
    int n;
    printf("\nEnter the number of element : ");    // get the number of elements
    scanf("%d",&n);

    int arr[n];    // create an array of size n

    printf("\nEnter the %d element : \n",n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);      // get the n elements from user
    }

    quick_sort(arr,0,n);    // sort the array using quicksort
    int flag=0;
    // iterate over the sorted array and find the duplicate element
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i]==arr[i+1])
        {
            printf("\nThe duplicate element : %d",arr[i]);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("\nNo duplicate elment find.");
    }
}
