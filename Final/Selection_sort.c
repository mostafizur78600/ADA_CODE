/*
Date: 17/01/2023
Name: Mostafizur Rahman

Selection Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 1000   // Define a constant n as 100

// Function to perform selection sort on an array of integers
void selection_sort(int array[], int size)
{
    int smallest, a;
    for (int i = 0; i < size - 1; i++) // Loop through the array from 0 to n-2
    {
        smallest = i;   // Assume the current index has the smallest element
        for (int j = i + 1; j < size; j++) // Loop through the unsorted part of the array
        {
            if (array[j] < array[smallest]) // If a smaller element is found
            {
                smallest = j;   // Update the index of the smallest element
            }
        }
        // Swap the smallest element with the first element in the unsorted part of the array
        a = array[i];
        array[i] = array[smallest];
        array[smallest] = a;
    }
}

// Main function
void main(void)
{
    clock_t start, end; // Declare variables to measure execution time
    int values[n], i;   // Declare an array of integers and a loop variable

    printf("\n Unsorted list is as follows\n");
    for (i = 0; i < n; i++) // Loop through the array
    {
        values[i] = rand() % n; // Generate a random integer between 0 and n-1 and store it in the array
        printf("%d ", values[i]); // Print the current element
    }

    start = clock();    // Start the clock
    selection_sort(values, n); // Call the selection_sort function to sort the array
    end = clock();  // Stop the clock
    double duration = ((double)end - start) / CLOCKS_PER_SEC; // Calculate the duration of the algorithm
    printf("\n\n\n Sorted list is as follows\n\n\n");
    for (i = 0; i < n; i++) // Loop through the sorted array
        printf("%d ", values[i]); // Print the current element
    printf("\n\n\nTime taken to execute in seconds : %f second.", duration); // Print the execution time
}
