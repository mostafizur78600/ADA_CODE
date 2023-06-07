/*
Date: 23/02/2023
Name: Mostafizur Rahman

[Strassen’s Matrix Multiplication]: Write a program to implement Strassen’s 
Matrix multiplication. Your function must be a true and close implementation 
of the algorithm discussed. For details refer to Chapter 4 of the CLRS book.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void strassen_multiply(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return; //if there is only one row
    }

    int i, j;
    int mid = n / 2;

    // Declare submatrices for A and B
    int A11[mid][mid], A12[mid][mid], A21[mid][mid], A22[mid][mid];
    int B11[mid][mid], B12[mid][mid], B21[mid][mid], B22[mid][mid];
    int C11[mid][mid], C12[mid][mid], C21[mid][mid], C22[mid][mid];
    int P1[mid][mid], P2[mid][mid], P3[mid][mid], P4[mid][mid];
    int P5[mid][mid], P6[mid][mid], P7[mid][mid];
    int temp1[mid][mid], temp2[mid][mid];

    // Divide matrices A and B into submatrices
    for (i = 0; i < mid; i++) {
        for (j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Calculate the seven products (P1, P2, ..., P7)
    strassen_multiply(mid, A11, B11, P1);
    strassen_multiply(mid, A12, B21, P2);
    strassen_multiply(mid, A11, B12, P3);
    strassen_multiply(mid, A12, B22, P4);
    strassen_multiply(mid, A21, B11, P5);
    strassen_multiply(mid, A22, B21, P6);
    strassen_multiply(mid, A21, B12, P7);

    // Calculate the submatrices of the result matrix C
    for (i = 0; i < mid; i++) {
        for (j = 0; j < mid; j++) {
            C11[i][j] = P1[i][j] + P4[i][j] - P5[i][j] + P7[i][j];
            C12[i][j] = P3[i][j] + P5[i][j];
            C21[i][j] = P2[i][j] + P4[i][j];
            C22[i][j] = P1[i][j] - P2[i][j] + P3[i][j] + P6[i][j];
        }
    }

    // Merge the submatrices to get the final result matrix C
    for (i = 0; i < mid; i++) {
        for (j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

//funtion for print matrix
void print_matrix(int n, int matrix[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d      ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    printf("\nEnter the size of matrices (power of 2): ");
    scanf("%d", &n);
    srand(time(0));     // Initialize the random seed based on the current time

    int A[n][n], B[n][n], C[n][n];

    //use random function to put number int the matrix in A
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j]=rand() % 100;
        }
    }

    //use random function to put number int the matrix in A
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            B[i][j]=rand() % 100;
        }
    }

    strassen_multiply(n, A, B, C); //call the function strassen_multiply with pass number of row matrix A matrix B and matrix c which will store the resultent matrix

    printf("\nMatrix A:\n");
    print_matrix(n, A); //call the funtion for print the matrix A

    printf("\nMatrix B:\n");
    print_matrix(n, B); //call the funtion for print the matrix B

    printf("\nResultant Matrix C (A * B):\n");
    print_matrix(n, C); //call the funtion for print the matrix C

    return 0;
}
