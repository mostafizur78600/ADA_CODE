#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#define num 10
void max_heapify(int a[], int i,int n)
{
    int largest,temp;
    int l=(2*i);
    int r=(2*i)+1;
    if ((l<=n) && (a[l]>a[i]))
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if ((r<=n)&& (a[r]>a[largest]))
    {
        largest=r;
    }
    if (largest !=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        max_heapify(a,largest,n);
    }
}
void main(void)
{
    printf("\nUnsorted list is as follows\n");
    int values[num+1]={4,1,3,2,16,9,10,14,8,7};
    for (int i = 0; i < num; i++)
    {
        printf("%d ", values[i]);
    }

   max_heapify(values,2,num);

    printf("\n\n\nSorted max heapify\n\n\n");

    for (int i = 0; i < num; i++)
        printf("%d ", values[i]);

}