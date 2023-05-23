#include<stdio.h>
#include<stdlib.h>

int comparator (const void *num1,const void * num2)
{
    return (*(int*)num1 - *(int*)num2);
}

int main()
{
    int arr[5]={23,32,123,45,32};
    int s=5;
    qsort(arr,s,sizeof(arr[0]),comparator);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    
}