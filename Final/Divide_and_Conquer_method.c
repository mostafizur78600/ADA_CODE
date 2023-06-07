/*
Date: 23/02/2023
Name: Mostafizur Rahman

[Strassen’s Matrix Multiplication]: Write a program to implement Strassen’s Matrix 
multiplication. Your function must be a true and close implementation of the algorithm 
discussed. For details refer to Chapter 4 of the CLRS book.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_multiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        // Base case: if the matrix size is 1x1, perform multiplication directly
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int i, j;
    int new_size = n / 2;

    // Declare submatrices for A, B, and C
    int A11[new_size][new_size], A12[new_size][new_size], A21[new_size][new_size], A22[new_size][new_size];
    int B11[new_size][new_size], B12[new_size][new_size], B21[new_size][new_size], B22[new_size][new_size];
    int C11[new_size][new_size], C12[new_size][new_size], C21[new_size][new_size], C22[new_size][new_size];
    int M1[new_size][new_size], M2[new_size][new_size], M3[new_size][new_size], M4[new_size][new_size];
    int M5[new_size][new_size], M6[new_size][new_size], M7[new_size][new_size];
    int temp1[new_size][new_size], temp2[new_size][new_size];

    // Divide matrices A and B into submatrices
    for (i = 0; i < new_size; i++) {
        for (j = 0; j < new_size; j++) {
            // Submatrix A11
            A11[i][j] = A[i][j];
            // Submatrix A12
            A12[i][j] = A[i][j + new_size];
            // Submatrix A21
            A21[i][j] = A[i + new_size][j];
            // Submatrix A22
            A22[i][j] = A[i + new_size][j + new_size];

            // Submatrix B11
            B11[i][j] = B[i][j];
            // Submatrix B12
            B12[i][j] = B[i][j + new_size];
            // Submatrix B21
            B21[i][j] = B[i + new_size][j];
            // Submatrix B22
            B22[i][j] = B[i + new_size][j + new_size];
        }
    }

    // Perform recursive calls to calculate the 7 products (M1, M2, ..., M7)
    matrix_multiply(new_size, A11, B11, M1);
    matrix_multiply(new_size, A12, B21, M2);
    matrix_multiply(new_size, A11, B12, M3);
    matrix_multiply(new_size, A12, B22, M4);
    matrix_multiply(new_size, A21, B11, M5);
    matrix_multiply(new_size, A22, B21, M6);
    matrix_multiply(new_size, A21, B12, M7);

    // Calculate the submatrices of the result matrix C
    for (i = 0; i < new_size; i++) {
        for (j = 0; j < new_size; j++) {
            // Calculate temporary values for C11 and C22
            temp1[i][j] = M1[i][j] + M4[i][j];
            temp2[i][j] = M5[i][j] + M7[i][j];
            // Calculate submatrix C11
            C11[i][j] = temp1[i][j] + temp2[i][j] - M2[i][j] + M6[i][j];
            // Calculate submatrix C12
            C12[i][j] = M3[i][j] + M5[i][j];
            // Calculate submatrix C21
            C21[i][j] = M2[i][j] + M4[i][j];
            // Calculate submatrix C22
            C22[i][j] = temp1[i][j] - M3[i][j] + temp2[i][j] + M6[i][j];
        }
    }

    // Merge the submatrices to get the final result matrix C
    for (i = 0; i < new_size; i++) {
        for (j = 0; j < new_size; j++) {
            // Merge submatrix C11
            C[i][j] = C11[i][j];
            // Merge submatrix C12
            C[i][j + new_size] = C12[i][j];
            // Merge submatrix C21
            C[i + new_size][j] = C21[i][j];
            // Merge submatrix C22
            C[i + new_size][j + new_size] = C22[i][j];
        }
    }
}

void print_matrix(int n, int matrix[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Print each element of the matrix
            printf("%d      ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    printf("\nEnter the size of matrices: ");
    scanf("%d", &n);
    srand(time(0));     // Initialize the random seed based on the current time

    int A[n][n], B[n][n], C[n][n];

    // Generate random values for matrix A
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = rand() % 100 + 1;
        }
    }

    // Generate random values for matrix B
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            B[i][j] = rand() % 100 + 1;
        }
    }

    // Perform matrix multiplication
    matrix_multiply(n, A, B, C);

    printf("\nMatrix A:\n");
    // Print matrix A
    print_matrix(n, A);

    printf("\nMatrix B:\n");
    // Print matrix B
    print_matrix(n, B);

    printf("\nResultant Matrix C (A * B):\n");
    // Print matrix C
    print_matrix(n, C);

    return 0;
}
