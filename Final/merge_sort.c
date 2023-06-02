/*
Name: Mostafizur Rahman
Date: 14-02-2023

Merge Sort]: Write a program to sort a given set of elements using 
the Merge Sort method. The elements can be read from a file or can 
be generated using the random number generator. 
Implement the Merge() and MergeSort() procedures.
*/
#include <stdio.h>  // Include standard input/output library
#include <stdlib.h> // Include standard library
#include <time.h>   // Include time library
#include <math.h>   // Include math library

#define n 100 // Define a constant integer n with a value of 100

// This function merges two sorted arrays into one sorted array
void merge(int A[], int p, int q, int r)
{
    int n1, n2;
    n1 = q - p + 1;           // Calculate the size of the left subarray
    n2 = r - q;               // Calculate the size of the right subarray
    int L[n1 + 1], R[n2 + 1]; // Create two subarrays, L and R
    // Copy elements from the original array A into the subarrays L and R
    for (int i = 0; i <= n1; i++)
    {
        L[i] = A[p + i - 1];
    }
    for (int j = 0; j <= n2; j++)
    {
        R[j] = A[q + j];
    }
    L[n1 + 1] = INT_MAX; // Add a sentinel value at the end of the left subarray
    R[n2 + 1] = INT_MAX; // Add a sentinel value at the end of the right subarray
    int i = 1;
    int j = 1;
    // Merge the two subarrays L and R into one sorted array
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

// This function implements the merge sort algorithm recursively
void merge_sort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) / 2); // Calculate the middle index
        merge_sort(A, p, q);        // Sort the left subarray
        merge_sort(A, q + 1, r);    // Sort the right subarray
        merge(A, p, q, r);          // Merge the two sorted subarrays
    }
}

// The main function of the program
void main()
{
    clock_t start, end; // Declare two clock variables to measure time
    int values[n];      // Declare an integer array of size n
    srand(time(0));     // Initialize the random seed based on the current time
    printf("\nUnsorted list is as follows\n");
    // Fill the array with random values between 0 and 999 and print the unsorted array
    for (int i = 0; i < n; i++)
    {
        values[i] = rand() % 1000;
        printf("%d ", values[i]);
    }
    start = clock();                                          // Start the clock
    merge_sort(values, 0, n - 1);                             // Sort the array using merge sort
    end = clock();                                            // End the clock
    double duration = ((double)end - start) / CLOCKS_PER_SEC; // Calculate the running time
    printf("\n\n\nSorted list is as follows\n\n\n");
    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", values[i]);
    }
    printf("\n\n\nTime taken to execute in seconds : %f", duration); // print running time in second
}