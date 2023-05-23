#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define num 10
int binary_search(int a[],int n,int x)
{
    int p=0,r=n,q;
    while(p<=r){
        q=floor((p+r)/2);
            if(a[q]==x)
                return q;
            if(a[q]>x)
                r=q-1;
            if(a[q]<x)
                p=q+1;
    }
    return -1;
}



void main(void)
{
    int in;
    int values[num]={7,15,25,45,50,52,63,68,89,99};
    printf("\nEnter element to find : ");
    scanf("%d",&in);
    int out=binary_search(values,num,in);
    if (out==-1)
    {
        printf("\nElement not found.");
    }
    else
    {
        printf("The found element position is : %d",out);
    }
}
    