/*
Date: 07/02/2023
NAME: Mostafizur Rahman

Program for find Binary_search_iterative
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define num 10 // Define a constant variable num as 10

// Function for binary search
int binary_search(int a[], int n, int x) {
    int p = 0, r = n, q; // Initialize variables p and r

    while(p <= r) { // Run a loop while p is less than or equal to r
        q = floor((p + r) / 2); // Calculate q as the middle point of p and r

        if(a[q] == x) // If element at q is equal to x
            return q; // Return the index q

        if(a[q] > x) // If element at q is greater than x
            r = q - 1; // Update r to q - 1

        if(a[q] < x) // If element at q is less than x
            p = q + 1; // Update p to q + 1
    }

    return -1; // If element is not found, return -1
}

void main(void) {
    int in;
    int values[num] = {7, 15, 25, 45, 50, 52, 63, 68, 89, 99}; // Declare an array of size num and initialize it with some values

    printf("\nArray Element is : ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ",values[i]);
    }
    
    printf("\nEnter element to find : ");
    scanf("%d", &in); // Read user input for element to search

    int out = binary_search(values, num, in); // Call binary_search function and store the result in out

    if(out == -1) { // If element is not found
        printf("\nElement not found.");
    }
    else { // If element is found
        printf("The found element position is : %d", out); // Print the index of the element
    }
}
