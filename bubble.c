#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10000
void bubble_sort(int array[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
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
    bubble_sort(values, n);
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\n\n\n Sorted list is as follows\n\n\n");
    for (i = 0; i < n; i++)
        printf("%d ", values[i]);
    printf("\n\n\nTime taken to execute in seconds : %f", duration);
}