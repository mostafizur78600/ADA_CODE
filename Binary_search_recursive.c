#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define num 10
int binary_search(int a[], int p, int r, int x)
{
    if (p > r)
    {
        return -1;
    }
    int q;
    while (p <= r)
    {
        q = floor((p + r) / 2);
        if (a[q] == x)
            return q;
        if (a[q] > x)
            return binary_search(a, p, q - 1, x);
        if (a[q] < x)
            return binary_search(a, q + 1, r, x);
    }
    return -1;
}


void main(void)
{
    int in;
    int values[num]={7,15,15,15,50,52,63,68,89,99};
    printf("\nEnter element to find : ");
    scanf("%d",&in);
    int out = binary_search(values, 0, num, in);
    if (out==-1)
    {
        printf("\nElement not found.");
    }
    else
    {
        printf("\nThe found element position is : %d",out);
    }
}
    