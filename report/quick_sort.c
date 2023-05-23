/*
Name: Mostafizur Rahman
Date: 10-02-2023

Program for Quick Sort
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 1000
int partition(int a[], int p, int r)
{
    int x = a[r], i = p - 1, temp;
    for (int j = p; j <= r - 1; j++)
    {
        if ((a[j]) <= x)//check element
        {
            i = i + 1;
            temp = a[i];
            a[i] = a[j]; //swap value
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[r]; //swap value
    a[r] = temp;
    return i + 1;// return 
}

void quick_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);//call partition with array,start index,last index
        quick_sort(a, p, q - 1);//recursion call of quick_sort for left part
        quick_sort(a, q + 1, r);//recursion call of quick_sort for right part
    }
}

void main()
{
    clock_t start, end;
    int values[n];
    srand(time(0));//for generate different random number every time
    printf("\nUnsorted list is as follows\n");
    for (int i = 0; i < n; i++)
    {
        values[i] = rand() % 1000; // Random number generate
        printf("%d ", values[i]);  // Print input Random Number
    }
    start = clock(); // Start clock

    quick_sort(values, 0, n - 1); // call quick_sort with passing array,0,n-1

    end = clock(); // end clock
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    printf("\n\n\nSorted list is as follows\n\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", values[i]); // print sort array
    }

    printf("\n\n\nTime taken to execute in seconds : %f", duration); // print running time in second
}
