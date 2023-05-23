#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void print_matrix(int a[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d      ",a[i][j]);
        }
        printf("\n");
        
    }
    
}

void square_matrix_multiply(int a[3][3],int b[3][3])
{
    int c[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j]=0;
            for (int k = 0; k < 3; k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
                    
        }
        
    }
    printf("\nThe multificatrion matrix is : \n");
    print_matrix(c);
}

void main()
{
    // int a[3][3]={1,2,3,4,5,6,7,8,9};
    // int b[3][3]={10,11,12,13,14,15,16,17,18};
    int a[3][3],b[3][3];
    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j]=(rand() % 100)+1;
        } 
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[i][j]=(rand() % 100)+1;
        } 
    }

    printf("\nTwo input Matrix are : \n");
    print_matrix(a);
    print_matrix(b);
    square_matrix_multiply(a,b);
}