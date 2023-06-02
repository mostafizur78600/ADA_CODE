/*
Date: 07/02/2023
NAME: Mostafizur Rahman

[Binary Search]: Write a program to implement Binary Search. 
Write functions for both the a) iterative and b) recursive implementations.
*/

#include <stdio.h> // standard input output header file
#include <stdlib.h> // standard library header file
#include <math.h> // math header file
#define num 10 // preprocessor constant definition

int binary_search(int a[], int p, int r, int x) // function definition
{
    if (p > r) // base condition
    {
        return -1; // return -1 if element not found
    }
    int q;
    while (p <= r) // loop until element is found or boundaries cross
    {
        q = floor((p + r) / 2); // find the middle element
        if (a[q] == x) // if element is found
            return q; // return index of the element
        if (a[q] > x) // if middle element is greater than the element to be searched
            return binary_search(a, p, q - 1, x); // search in the left half of the array
        if (a[q] < x) // if middle element is smaller than the element to be searched
            return binary_search(a, q + 1, r, x); // search in the right half of the array
    }
    return -1; // if element not found
}

int main() // main function
{
    int in;
    int values[num]={7,15,25,45,50,52,63,68,89,99}; // array of sorted elements
    printf("\nArray Element is : ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ",values[i]);
    }
    
    printf("\nEnter element to find : ");
    scanf("%d",&in); // input the element to be searched
    int out = binary_search(values, 0, num, in); // search for the element in the array
    if (out==-1) // if element not found
    {
        printf("\nElement not found."); // print element not found message
    }
    else
    {
        printf("\nThe found element position is : %d",out); // print the index of the found element
    }
    return 0; // Return 0 to indicate successful program execution
}