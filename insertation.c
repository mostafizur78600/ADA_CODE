#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10000
void insertion(int array[], int size)
{
    int key, i;
    for (int j = 2; j < size; j++)
    {
        key = array[j];
        i = j - 1;
        while (i >= 0 && array[i] > key)
        {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}
void main(void)
{
    clock_t start, end;
    int values[n], i;
    printf("\n Unsorted list is as follows\n");
    for (i = 0; i < n; i++)
    {
        values[i] = rand() % n;
        printf(" %d", values[i]);
    }
    start = clock();
    insertion(values, n);
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\n\n\n Sorted list is as follows\n\n\n");
    for (i = 0; i < n; i++)
        printf("%d ", values[i]);
    printf("\n\n\nTime taken to execute in seconds : %f", duration);
}