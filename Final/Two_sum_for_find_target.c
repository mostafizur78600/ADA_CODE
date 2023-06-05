/*
Name: Mostafizur Rahman
Date: 18-04-2023

[Two Sum]: Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target. 
You may assume that each input would have exactly one solution, 
and you may not use the same element twice. 
You can return the answer in any order.
*/

#include <stdio.h>

int main()
{
    int n, t;
    printf("Enter the number of elements: ");
    scanf("%d", &n); // Read the number of elements from the user

    int arr[n]; // Declare an array of size n
    printf("\nEnter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // Read the elements of the array from the user
    }

    printf("\nEnter the target element: ");
    scanf("%d", &t); // Read the target element from the user

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((arr[i] + arr[j]) == t) // Check if the sum of elements at indices i and j is equal to the target element
            {
                printf("\nIndices of the two numbers that add up to the target are in position : %d, %d", i, j);
                flag = 1; // Set the flag to 1 indicating that a pair has been found
                break;
            }
        }
        if (flag == 1)
            break; // If a pair has been found, exit the loop
    }

    if (flag == 0)
    {
        printf("\nNot found"); // If no pair is found, print "Not found"
    }
    return 0; // Return 0 to indicate successful program execution
}
