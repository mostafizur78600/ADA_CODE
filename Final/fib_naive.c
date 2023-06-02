/*
Date: 09/05/2023
Name: Mostafizur Rahman

[Fibonacci Sequence]: Write a recursive function to compute 
the Fibonacci sequence upto n-th term. Take the n-th term 
as input from the user.
*/

#include <stdio.h>

// Function to calculate the Fibonacci series using recursion
long long fib(int n)
{
    if (n <= 1) // Check if n is less than or equal to 1
        return n; // If true, return n as the Fibonacci number
    return fib(n - 1) + fib(n - 2); // Otherwise, recursively call the fib function with n-1 and n-2, and return their sum
}

int main()
{
    int n;
    printf("Enter number to find the Fibonacci series: "); // Prompt the user to enter a number
    scanf("%d", &n); // Read the input value for number of series

    printf("\nThe Fibonacci series is: \n");
    for (int i = 0; i < n; i++) // Iterate from i=0 to i<n
    {
        printf("%lld ", fib(i)); // Print the Fibonacci number for each iteration
    }

    return 0; // Return 0 to indicate successful program execution
}
