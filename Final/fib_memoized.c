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
    if (memo[n] != 0)   // Check if the nth Fibonacci number is already calculated and stored in the memo array
        return memo[n]; // If it is, return the stored value

    if (n == 1 || n == 2) // Base case: Fibonacci numbers 1 and 2 are defined as 1
    {
        memo[n] = 1; // Store the value 1 in the memo array for future reference
        return 1;    // Return 1
    }

    memo[n] = fib(n - 1) + fib(n - 2); // Calculate the nth Fibonacci number by recursively calling the fib function for (n-1) and (n-2) and summing them up
    return memo[n];                    // Return the calculated value
}

int main()
{
    int n; // Declaration of a variable 'n' to store the user input
    printf("Enter number to find fib : ");
    scanf("%d", &n); // Read the value of 'n' from the user

    fib(n); // Call the fib function to calculate the Fibonacci number

    printf("\nThe fib series is : \n");

    // memo[1]=1;
    // memo[2]=1;
    // The above two lines are commented out, probably indicating that the base cases are already handled in the fib function

    for (int i = 0; i < n; i++) // Iterate from 0 to (n-1)
    {
        printf("%d = %lld\n", (i + 1), memo[i]); // Print the index (i+1) and the corresponding Fibonacci number stored in the memo array
    }

    return 0; // Indicate successful completion of the program
}

/*
The time complexity of the code is O(n) and the space complexity is O(n).
*/