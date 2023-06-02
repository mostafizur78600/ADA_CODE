/*
Date: 28/05/2023
Name: Mostafizur Rahman

[Tower of Hanoi]: Write a recursive function to solve the tower of 
Hanoi puzzle. Consider the number of disks as input from the user.
*/

#include <stdio.h>

// Function to solve the Tower of Hanoi problem using recursion
void ToH(int n, char rodA, char rodC, char rodB)
{
    if (n == 1) // Check if there is only one disk
    {
        printf("\nMove disk 1 from rod %c to rod %c", rodA, rodC); // If true, move the disk directly from rod A to rod C
        return;
    }
    ToH(n - 1, rodA, rodB, rodC); // Move n-1 disks from rod A to rod B, using rod C as the auxiliary rod
    printf("\nMove disk %d from rod %c to rod %c", n, rodA, rodC); // Move the nth disk from rod A to rod C
    ToH(n - 1, rodB, rodC, rodA); // Move the n-1 disks from rod B to rod C, using rod A as the auxiliary rod
}

int main()
{
    int no_of_disks;
    printf("Enter the number of disks: "); // Prompt the user to enter the number of disks
    scanf("%d", &no_of_disks); // Read the input value for the number of disks

    ToH(no_of_disks, 'A', 'C', 'B');
    // Call the ToH function with the number of disks, and the names of the rods A, C, and B respectively

    return 0; // Return 0 to indicate successful program execution
}
