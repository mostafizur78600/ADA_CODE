/*
Name: Mostafizur Rahman
Date: 18-04-2023

[Top K Most Frequent Elements]: Given an integer array nums and an integer k, 
return the k most frequent elements. You may return the answer in any order.
*/

#include <stdio.h>
#include <limits.h>

void main()
{
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n); // Read the number of elements from the user

    int arr[n];
    printf("\nEnter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // Read the elements of the array from the user
    }

    printf("\nEnter the value of k: ");
    scanf("%d", &k); // Read the value of k from the user

    int max = INT_MIN;
    int max_index;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] > max) //find max number form the array for create a hiatogram array
        {
            max = arr[j];
            max_index = j;
        }
    }

    int h_arr[max + 1]; // Create a histogram array of size max+1

    for (int i = 0; i < max + 1; i++)
    {
        h_arr[i] = 0; // Initialize all elements of the histogram array to 0
    }

    for (int j = 0; j < n; j++)
    {
        h_arr[arr[j]] += 1; // Update the count of each element in the histogram array
    }

    int temp = INT_MIN;
    int index;
    printf("\nThe %d most frequent elements: ", k);
    for (int i = 0; i < k; i++) 
    {
        for (int j = 0; j < max + 1; j++) //find and print the most frequent elements
        {
            if (h_arr[j] > temp)
            {
                temp = h_arr[j]; //find the most repeat element 
                index = j;
            }
        }
        printf("%d ", index); // Print the current most frequent element
        h_arr[index] = INT_MIN; // Mark the current most frequent element as visited by setting its count to INT_MIN
        temp = INT_MIN; // Reset the temporary variable to find the next most frequent element
    }
}
