/*
Date: 28/05/2023
Name: Mostafizur Rahman

[Longest Common Subsequence]: Write a program to implement the 
longest common subsequence (LCS) of two strings using the Dynamic 
Programming approach. The inputs are two strings X and Y. 
Comment on the time and space complexity.
*/
#include <stdio.h>
#include <string.h>

int max(int m, int n)
{
    return (m > n) ? m : n; // Function to return the maximum of two integers
}

int LCS(char *A, char *B, int x, int y)
{
    if (x == 0 || y == 0) // Base case: If either of the strings A or B is empty, return 0
        return 0;
    if (A[x - 1] == B[y - 1]) // If the last characters of A and B are the same
        return 1 + LCS(A, B, x - 1, y - 1); // Recursive call by excluding the last characters and incrementing the length of LCS by 1
    else
        return max(LCS(A, B, x, y - 1), LCS(A, B, x - 1, y)); // Recursive call by excluding the last character of A and B respectively, and taking the maximum of the two calls
}

int main()
{
    char A[] = "ABAZDC"; // First string
    char B[] = "BACBAD"; // Second string
    int x = strlen(A); // Length of string A
    int y = strlen(B); // Length of string B
    printf("Length of LCS is %d", LCS(A, B, x, y)); // Print the length of the Longest Common Subsequence (LCS) between A and B
    return 0;
}

/*
The time complexity of the code is O(2^(x+y)) in the worst case, and the space complexity is O(x+y), where x and y are the lengths of strings A and B, respectively.
*/