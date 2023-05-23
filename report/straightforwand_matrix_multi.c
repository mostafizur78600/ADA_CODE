/*
Name: Mostafizur Rahman
Date: 21-02-2023

Program for straightforwand_matrix_multiplication
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to print a 3x3 matrix
void print_matrix(int a[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d      ",a[i][j]); // print the value of each element in the matrix
        }
        printf("\n");
    }
}

// Function to multiply two 3x3 matrices
void square_matrix_multiply(int a[3][3], int b[3][3])
{
    int c[3][3]; // the result of the multiplication will be stored in this matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 0; // initialize the current element of the result matrix to 0
            for (int k = 0; k < 3; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j]; // compute the dot product of the i-th row of a with the j-th column of b and store the result in c[i][j]
            }
        }
    }
    printf("\nThe multiplication matrix is: \n");
    print_matrix(c); // print the result matrix
}

void main()
{
    int a[3][3], b[3][3];

    srand(time(0)); // seed the random number generator with the current time

    // Fill the input matrices with random numbers
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = (rand() % 100) + 1; // generate a random number between 1 and 100 and store it in a[i][j]
        } 
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[i][j] = (rand() % 100) + 1; // generate a random number between 1 and 100 and store it in b[i][j]
        } 
    }

    // Print the input matrices
    printf("\nTwo input matrices are:\n");
    print_matrix(a);
    print_matrix(b);

    // Multiply the input matrices and print the result
    square_matrix_multiply(a, b);
}
