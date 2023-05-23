/*
Date: 17/01/2023
Name: Mostafizur Rahman

insertion Sort
*/

#include <stdio.h>      // include standard input/output header
#include <stdlib.h>     // include standard library header
#include <time.h>       // include time header

#define n 1000         // define constant n as 100

void insertion(int array[], int size)    // define insertion function that takes an array and its size as parameters
{
    int key, i;     // declare key and i as integers
    for (int j = 2; j < size; j++)   // iterate through the array starting from the second element
    {
        key = array[j];     // set key to the current element
        i = j - 1;          // set i to the previous element
        while (i >= 0 && array[i] > key)    // while i is greater than or equal to 0 and the previous element is greater than the current element
        {
            array[i + 1] = array[i];    // shift the previous element one position to the right
            i = i - 1;                  // move i one position to the left
        }
        array[i + 1] = key;     // insert the current element in the correct position
    }
}

void main(void)     // main function
{
    clock_t start, end;     // declare variables to hold start and end times
    int values[n], i;       // declare an integer array values of size n and an integer variable i
    printf("\n Unsorted list is as follows\n");    // print a message indicating the unsorted list is being printed
    for (i = 0; i < n; i++)     // iterate through the array
    {
        values[i] = rand() % n;     // set each element to a random number between 0 and n-1
        printf(" %d", values[i]);   // print each element
    }
    start = clock();        // set start time to current clock time
    insertion(values, n);   // sort the array using the insertion function
    end = clock();          // set end time to current clock time
    double duration = ((double)end - start) / CLOCKS_PER_SEC;     // calculate the time taken to sort the array
    printf("\n\n\n Sorted list is as follows\n\n\n");     // print a message indicating the sorted list is being printed
    for (i = 0; i < n; i++)     // iterate through the array
        printf("%d ", values[i]);   // print each element
    printf("\n\n\nTime taken to execute in seconds : %f", duration);   // print the time taken to sort the array
}
