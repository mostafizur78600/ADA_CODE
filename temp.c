#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    printf("\n%d",INT_MAX);
    printf("\n%lli",__LONG_MAX__);
    printf("\n%lld",__LONG_LONG_MAX__);
    printf("\n%d",CLOCKS_PER_SEC);
}