/*
Date: 09/05/2023
Name: Mostafizur Rahman

[Fibonacci Sequence]: Write a Dynamic Programming implementa􀆟on 
to compute the factorial of a number.Comment on the time and 
space complexity. Implement the two DP versions 
i) memorized Fibonacci and ii) tabulated Fibonacci.
*/

#include <stdio.h>

long long memo[100] = {0}; // Declaration and initialization of an array 'memo' of size 100 with all elements set to 0

long long fib(int n)
{
    long long f = 0;            // Declaration of a variable 'f' to store the Fibonacci number
    for (int k = 1; k < n; k++) // Iterate from 1 to (n-1)
    {
        if (k <= 2) // Check if k is 1 or 2
            f = 1;  // If it is, set 'f' to 1 (since Fibonacci numbers 1 and 2 are defined as 1)
        else
        {
            f = memo[k - 1] + memo[k - 2]; // If k is greater than 2, calculate the Fibonacci number by summing up the previous two Fibonacci numbers
        }
        memo[k] = f; // Store the calculated Fibonacci number in the memo array
    }
    return f; // Return the last calculated Fibonacci number
}

int main()
{
    int n; // Declaration of a variable 'n' to store the user input
    printf("Enter number to find fib : ");
    scanf("%d", &n); // Read the value of 'n' from the user

    fib(n); // Call the fib function to calculate the Fibonacci number

    printf("\nThe fib series is : \n");

    for (int i = 0; i < n; i++) // Iterate from 0 to (n-1)
    {
        printf("%d = %lld\n", (i + 1), memo[i]); // Print the Fibonacci numbers stored in the memo array
    }

    return 0; // Indicate successful completion of the program
}

/*
The time complexity of the code is O(n), and the space complexity is O(1).
*/