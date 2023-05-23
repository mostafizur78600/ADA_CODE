#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100
void selection_sort(int array[], int size)
{
    int smallest, a;
    for (int i = 0; i < size - 1; i++)
    {
        smallest = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[smallest])
            {
                smallest = j;
            }
        }
        a = array[i];
        array[i] = array[smallest];
        array[smallest] = a;
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
        printf("%d ", values[i]);
    }

    start = clock();
    selection_sort(values, n);
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\n\n\n Sorted list is as follows\n\n\n");
    for (i = 0; i < n; i++)
        printf("%d ", values[i]);
    printf("\n\n\nTime taken to execute in seconds : %f second.", duration);
}