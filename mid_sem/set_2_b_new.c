#include <stdio.h> // standard input output header file
#include <stdlib.h> // standard library header file
#include <math.h> // math header file

int binary_search(int a[], int p, int r, int x) // function definition
{
    if (p > r) // base condition
    {
        return -1; // return -1 if element not found
    }
    int q;
    while (p <= r) // loop until element is found or boundaries cross
    {
        q = floor((p + r) / 2); // find the middle element
        if (a[q] == x) // if element is found
            return q; // return index of the element
        if (a[q] > x) // if middle element is greater than the element to be searched
            return binary_search(a, p, q - 1, x); // search in the left half of the array
        if (a[q] < x) // if middle element is smaller than the element to be searched
            return binary_search(a, q + 1, r, x); // search in the right half of the array
    }
    return -1; // if element not found
}

void main(void) // main function
{

    int n,t,start=-1,end=-1;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the %d element in sort : ",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the target element : ");
    scanf("%d",&t);
    int out = binary_search(arr, 0, n, t); // search for the element in the array

    if (out==-1) // if element not found
    {
        printf("\nThe starting and ending position of a given target value : %d, %d",start,end);
    }
    else
    {
        start=out,end=out;
        for (int i = out; i >0; i--)
        {
            if(arr[i]!=t)
            {
                start=i+1;
                break;
            }
            start--;
        }

        for (int i = out; i < n; i++)
        {
            if(arr[i]!=t)
            {
                end=i-1;
                break;
            }
            end++;
            
        }
        printf("\nThe starting and ending position of a given target value : %d, %d",start,end);
    }
    
}