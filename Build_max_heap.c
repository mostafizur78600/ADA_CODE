// NAME: Mostafizur Rahman
// Date: 27/01/2023

// Program for find Build_Max_Heap

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
#define num 100  
void max_heapify(int a[], int i, int n)
{
    int largest, temp;
    int l = 2 * i;   
    int r = 2 * i + 1; 
    if ((l <= n) && (a[l] > a[i]))
    {
        largest = l; 
    }
    else
    {
        largest = i; 
    }
    if ((r <= n) && (a[r] > a[largest]))
    {
        largest = r; 
    }
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest]; 
        a[largest] = temp;
        max_heapify(a, largest, n); 
    }
}
void build_max_heap(int a[])
{
    int n = num;
    for (int i = floor(n / 2); i >= 0; i--)
    {
        max_heapify(a, i, n);
    }
}

void heap_sort(int a[])
{
    int temp;
    build_max_heap(a); 
    for (int i = num - 1; i >= 1; i--)
    {
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        max_heapify(a, 0, i - 1);
    }
}

void main(void)
{
    srand(time(0));
    int values[num];
    printf("\nUnsorted list is as follows\n");

    for (int i = 0; i < num; i++)
    {
        values[i] = rand() % 1000;
        printf("%d ", values[i]);
    }

    heap_sort(values);

    printf("\n\n\nSorted list is as follows\n");

    for (int i = 0; i < num; i++)
        printf("%d ", values[i]); 
    
    printf("\n\n\n");
}