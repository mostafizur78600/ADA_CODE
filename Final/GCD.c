/*
Date: 28/05/2023
Name: Mostafizur Rahman

[Greatest Common Divisor]: Write a recursive function to 
compute the GCD of two integers. Take the two integers 
as input from the user.
*/

#include <stdio.h>

// Function to calculate the highest common factor (HCF) using recursion
int hcf(int n1, int n2)
{
    if (n2 != 0) // Check if n2 is not zero
        return hcf(n2, n1 % n2); // Recursively call the hcf function with n2 and the remainder of n1 divided by n2
    else
        return n1; // If n2 is zero, return n1 as the HCF
}

int main()
{
    int n1, n2;
    printf("Enter two numbers: "); // Prompt the user to enter two numbers
    scanf("%d %d", &n1, &n2); // Read the input values for n1 and n2

    printf("Greatest Common Divisor of %d and %d is %d.", n1, n2, hcf(n1, n2));
    // Print the result of the hcf function, which calculates the Greatest Common Divisor of n1 and n2

    return 0; // Return 0 to indicate successful program execution
}
