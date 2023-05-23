#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#define n 10
void merge(int A[], int p, int q, int r)
{
    int n1, n2;
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i <= n1; i++)
    {
        L[i] = A[p + i - 1];
    }
    for (int j = 0; j <= n2; j++)
    {
        R[j] = A[q + j];
    }
    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;
    int i = 1;
    int j = 1;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void merege_sort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=floor((p+r)/2);
        merege_sort(A,p,q);
        merege_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}
void main()
{
    clock_t start, end;
    int values[n];
    srand(time(0));
    printf("\nUnsorted list is as follows\n");
    for (int i = 0; i < n; i++)
    {
        values[i] = rand() % 1000;
        printf("%d ", values[i]);
    }
    start = clock(); // Start clock
    merege_sort(values,0,n-1);
    end = clock(); // end clock
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\n\n\nSorted list is as follows\n\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", values[i]);
    }
    printf("\n\n\nTime taken to execute in seconds : %f", duration); // print running time in second
}