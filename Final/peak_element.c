/*
Name: Mostafizur Rahman
Date: 18-04-2023

[Peak Element]: A peak element is an element that is strictly greater than its 
neighbors. Given a 0-indexed integer array nums, find a peak element, and 
return its index. If the array contains multiple peaks, return the index 
to any of the peaks. You may imagine that nums[-1] = nums[n] = -∞. 
In other words, an element is always considered to be strictly greater 
than a neighbor that is outside the array. 
You must write an algorithm that runs in O(log n) time.
*/

#include <stdio.h>

int findPeakElement(int nums[], int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) { // Use binary search to find the peak element
        int mid = left + (right - left) / 2; // Calculate the middle index

        if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == size - 1 || nums[mid] > nums[mid + 1])) {
            return mid; // If the middle element is a peak element, return its index
        } else if (mid < size - 1 && nums[mid] < nums[mid + 1]) {
            left = mid + 1; // If the middle element is not a peak and the element to the right is greater, move the left pointer to mid + 1
        } else {
            right = mid - 1; // If the middle element is not a peak and the element to the left is greater, move the right pointer to mid - 1
        }
    }

    return -1; // If no peak element is found, return -1
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size); // Read the number of elements from the user

    int nums[size]; // Declare an array of size 'size'
    printf("\nEnter %d elements: \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &nums[i]); // Read the elements of the array from the user
    }

    int peakIndex = findPeakElement(nums, size); // Call the findPeakElement function to find the index of the peak element

    if (peakIndex != -1) {
        printf("Peak element found at index %d\n", peakIndex); // If a peak element is found, print its index
        printf("Peak element value is %d\n", nums[peakIndex]); // Print the value of the peak element
    } else {
        printf("No peak element found in the array.\n"); // If no peak element is found, print a message indicating the same
    }

    return 0; // Return 0 to indicate successful program execution
}
