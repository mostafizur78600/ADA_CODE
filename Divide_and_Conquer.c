#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

void print_matrix(int matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrix_multiply(int A[N][N], int B[N][N], int C[N][N], int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        int A11[N / 2][N / 2], A12[N / 2][N / 2], A21[N / 2][N / 2], A22[N / 2][N / 2];
        int B11[N / 2][N / 2], B12[N / 2][N / 2], B21[N / 2][N / 2], B22[N / 2][N / 2];
        int C11[N / 2][N / 2], C12[N / 2][N / 2], C21[N / 2][N / 2], C22[N / 2][N / 2];
        int P[N / 2][N / 2], Q[N / 2][N / 2], R[N / 2][N / 2], S[N / 2][N / 2], T[N / 2][N / 2], U[N / 2][N / 2], V[N / 2][N / 2];

        // divide A matrix into 4 submatrices
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A22[i][j] = A[i + n / 2][j + n / 2];
            }
        }

        // divide B matrix into 4 submatrices
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n / 2][j];
                B22[i][j] = B[i + n / 2][j + n / 2];
            }
        }

        // recursively compute 7 products of submatrices
        matrix_multiply(A11, B11, P, n / 2);
        matrix_multiply(A12, B21, Q, n / 2);
        matrix_multiply(A11, B12, R, n / 2);
        matrix_multiply(A12, B22, S, n / 2);
        matrix_multiply(A21, B11, T, n / 2);
        matrix_multiply(A22, B21, U, n / 2);
        matrix_multiply(A21, B12, V, n / 2);

        // combine submatrices into C matrix
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                C11[i][j] = P[i][j] + Q[i][j];
                C12[i][j] = R[i][j] + S[i][j];
                C21[i][j] = T[i][j] + U[i][j];
                C22[i][j] = P[i][j] + S[i][j] - R[i][j] + V[i][j];

            }
        }

        // combine 4 submatrices into C matrix
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                C[i][j] = C11[i][j];
                C[i][j + n / 2] = C12[i][j];
                C[i + n / 2][j] = C21[i][j];
                C[i + n / 2][j + n / 2] = C22[i][j];
            }
        }
    }
}
int main()
{
    int A[N][N], B[N][N], C[N][N];
    srand(time(NULL));

    // initialize matrices A and B with random numbers
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    printf("Matrix A:\n");
    print_matrix(A);
    printf("Matrix B:\n");
    print_matrix(B);

    matrix_multiply(A, B, C, N);

    printf("Matrix C:\n");
    print_matrix(C);

    return 0;
}