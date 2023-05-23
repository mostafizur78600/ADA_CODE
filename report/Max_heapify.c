/*
Date: 27/01/2023
NAME: Mostafizur Rahman

Program for find Max_Heapify
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#define num 10 // Define a constant `num` with a value of 10

void max_heapify(int a[], int i,int n) // Define the `max_heapify` function that takes an array of integers `a`, an integer `i`, and an integer `n`
{
    int largest,temp; // Define two integers `largest` and `temp`
    int l=(2*i); // Calculate the index of the left child of `i` and assign it to `l`
    int r=(2*i)+1; // Calculate the index of the right child of `i` and assign it to `r`
    
    // Check if the left child of `i` exists and is greater than `i`
    if ((l<=n) && (a[l]>a[i]))
    {
        largest=l; // Assign `l` to `largest` if it is greater than `i`
    }
    else
    {
        largest=i; // Otherwise, assign `i` to `largest`
    }
    
    // Check if the right child of `i` exists and is greater than the current value of `largest`
    if ((r<=n)&& (a[r]>a[largest]))
    {
        largest=r; // Assign `r` to `largest` if it is greater than the current value of `largest`
    }
    
    // If `largest` is not equal to `i`, swap the values of `a[i]` and `a[largest]` and call `max_heapify` recursively on the subtree rooted at `largest`
    if (largest !=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        max_heapify(a,largest,n);
    }
}

void main(void)
{
    printf("\nUnsorted list is as follows\n");
    int values[num+1]={4,1,3,2,16,9,10,14,8,7}; // Define an array `values` of size `num+1` and initialize it with 10 integers
    for (int i = 0; i < num; i++) // Loop over the elements of `values` and print them
    {
        printf("%d ", values[i]);
    }

    max_heapify(values,2,num); // Call the `max_heapify` function on `values` with parameters `2` and `num`

    printf("\n\n\nSorted max heapify\n\n\n");

    for (int i = 0; i < num; i++) // Loop over the elements of `values` and print them
    {
        printf("%d ", values[i]);
    }
}
