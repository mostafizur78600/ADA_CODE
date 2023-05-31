/*
Date: 27/01/2023
NAME: Mostafizur Rahman

Program for find Build_Max_Heap
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define num 100
void max_heapify(int a[], int i, int n)
{
    int largest, temp;
    int l = 2 * i;     // left node index
    int r = 2 * i + 1; // right node index
    if ((l <= n) && (a[l] > a[i]))
    {
        largest = l; // find largest
    }
    else
    {
        largest = i; // find largest
    }
    if ((r <= n) && (a[r] > a[largest]))
    {
        largest = r; // find largest
    }
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest]; // swap value
        a[largest] = temp;
        max_heapify(a, largest, n); // max_heapify function call with array,check position and total element number using recursion
    }
}
void build_max_heap(int a[])
{
    int n = num;
    for (int i = floor(n / 2); i >= 0; i--)
    {
        max_heapify(a, i, n); // call max_heapify with array,check position and total element
    }
}

void heap_sort(int a[])
{
    int temp;
    build_max_heap(a); // call build_max_heap funcion with pass array
    for (int i = num - 1; i >= 1; i--)
    {
        temp = a[i];
        a[i] = a[0]; // swap value
        a[0] = temp;
        max_heapify(a, 0, i - 1);
    }
}

void main(void)
{
    srand(time(0));
    int values[num];
    printf("\nUnsorted list is as follows\n");
    // int values[num]={32, 7, 24, 16, 3, 20, 10, 15, 7, 12};
    for (int i = 0; i < num; i++)
    {
        values[i] = rand() % 1000; // Random value input
        printf("%d ", values[i]);  // Random value print
    }

    heap_sort(values); // call Build_max_head function with pass value array

    printf("\n\n\nSorted list is as follows\n");

    for (int i = 0; i < num; i++)
        printf("%d ", values[i]); // Print output

    printf("\n\n\n");
}