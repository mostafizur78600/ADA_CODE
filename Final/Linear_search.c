/*
Date: 07/02/2023
NAME: Mostafizur Rahman

[Linear Search]: Write a program to implement Sequential (Linear) search.
*/
#include <stdio.h>

#define num 10

// Function to perform linear search on an array
int linear_search(int a[], int n, int x) {
    for (int i = 0; i < n; i++) // Iterate through the array elements
    {
        if(a[i] == x) // Check if the current element is equal to the target element
            return i; // If true, return the index of the element
    }
    return -1; // If the element is not found, return -1
}

int main(void) {
    int in;
    int values[num] = {7, 15, 25, 45, 50, 52, 63, 68, 89, 99}; // Declare an array of size num and initialize it with some values

    printf("\nArray Elements: ");
    for (int i = 0; i < num; i++) // Iterate through the array elements
    {
        printf("%d ", values[i]); // Print each element of the array
    }
    
    printf("\nEnter element to find: ");
    scanf("%d", &in); // Read the element to be searched from the user

    int out = linear_search(values, num, in); // Call the linear_search function to find the element

    if(out == -1) {
        printf("\nElement not found."); // If the returned index is -1, print that the element was not found
    }
    else {
        printf("The found element position is: %d", out); // If the returned index is not -1, print the position of the found element
    }

    return 0; // Return 0 to indicate successful program execution
}
