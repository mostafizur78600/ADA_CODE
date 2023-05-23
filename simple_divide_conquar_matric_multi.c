#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 4
void print_matrix(int a[size][size])
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d      ",a[i][j]);
        }
        printf("\n");
        
    }
    
}

int square_matrix_multiply_recursion(int a[size][size],int b[size][size])
{
    int c[size][size],n=size;
    if (n==0)
    {
        c[0][0]=a[0][0]*b[0][0];   
    }

    else
    {
        c[0][0]=square_matrix_multiply_recursion(a[0][0],b[0][0])+square_matrix_multiply_recursion(a[0][1],b[1][0]);
        c[0][1]=square_matrix_multiply_recursion(a[0][0],b[0][1])+square_matrix_multiply_recursion(a[0][1],b[1][1]);
        c[1][0]=square_matrix_multiply_recursion(a[1][0],b[0][0])+square_matrix_multiply_recursion(a[1][1],b[1][0]);
        c[0][1]=square_matrix_multiply_recursion(a[1][0],b[1][1])+square_matrix_multiply_recursion(a[1][1],b[1][1]);
    }
    printf("\nThe multificatrion matrix is : \n");
    print_matrix(c);
}

void main()
{
    // int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    // int b[4][4]={17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
    int a[size][size],b[size][size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            a[i][j]=(rand() % 100)+1;
        } 
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            b[i][j]=(rand() % 100)+1;
        } 
    }

    printf("\nTwo input Matrix are : \n");
    print_matrix(a);
    print_matrix(b);
    square_matrix_multiply_recursion(a,b);
}