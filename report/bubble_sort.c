/*
Date: 17/01/2023
Name: Mostafizur Rahman

Bubble Sort
*/
#include <stdio.h>      // include standard input/output header
#include <stdlib.h>     // include standard library header
#include <time.h>       // include time header

#define n 1000        // define constant n as 100

void bubble_sort(int array[], int size)   // define bubble sort function that takes an array and its size as parameters
{
    int temp, i, j;     // declare temp, i and j as integers
    for (i = 0; i < size; i++)      // iterate through the array
        for (j = 0; j < size; j++)      // iterate through the array again
            if (array[i] < array[j])    // if the current element is less than the other element
            {
                temp = array[i];        // swap the current element with the other element
                array[i] = array[j];
                array[j] = temp;
            }
}

void main(void)     // main function
{
    clock_t start, end;     // declare variables to hold start and end times
    int values[n], i;       // declare an integer array values of size n and an integer variable i
    printf("\nUnsorted list is as follows\n");    // print a message indicating the unsorted list is being printed
    for (i = 0; i < n; i++)     // iterate through the array
    {
        values[i] = rand() % n;     // set each element to a random number between 0 and n-1
        printf("%d ", values[i]);   // print each element
    }
    start = clock();        // set start time to current clock time
    bubble_sort(values, n); // sort the array using the bubble sort function
    end = clock();          // set end time to current clock time
    double duration = ((double)end - start) / CLOCKS_PER_SEC;     // calculate the time taken to sort the array
    printf("\n\n\nSorted list is as follows\n\n\n");     // print a message indicating the sorted list is being printed
    for (i = 0; i < n; i++)     // iterate through the array
        printf("%d ", values[i]);   // print each element
    printf("\n\n\nTime taken to execute in seconds : %f", duration);   // print the time taken to sort the array
}
