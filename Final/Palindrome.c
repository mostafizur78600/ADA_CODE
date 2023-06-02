/*
Date: 28/05/2023
Name: Mostafizur Rahman

[Palindrome Check]: Write a program using recursion to check if a string 
is a palindrome or not (a palindrome is a string that's the same when 
reads forwards and backwards.)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Recursive helper function to check if a string is a palindrome
bool isPalRec(char str[], int s, int e)
{
    if (s == e) // Check if the start and end indices are equal
        return true; // If true, the string has only one character and is a palindrome

    if (str[s] != str[e]) // Check if the characters at the start and end indices are different
        return false; // If true, the string is not a palindrome

    if (s < e + 1) // Check if the start index is less than the end index plus one
        return isPalRec(str, s + 1, e - 1); // Recursively call the isPalRec function with updated indices

    return true; // If all characters have been checked and are equal, the string is a palindrome
}

// Function to check if a string is a palindrome
bool isPalindrome(char str[])
{
    int n = strlen(str); // Get the length of the string

    if (n == 0) // Check if the string is empty
        return true; // If true, the empty string is considered a palindrome

    return isPalRec(str, 0, n - 1); // Call the recursive helper function to check if the string is a palindrome
}

int main()
{
    char str[100];
    printf("Enter the string: "); // Prompt the user to enter a string
    scanf("%s", str); // Read the input string

    if (isPalindrome(str))
        printf("\nYes, the string is a palindrome"); // Print a message indicating that the string is a palindrome
    else
        printf("\nNo, the string is not a palindrome"); // Print a message indicating that the string is not a palindrome

    return 0; // Return 0 to indicate successful program execution
}
