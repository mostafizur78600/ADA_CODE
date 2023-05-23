#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
        x[i] = u / weight[i];

    tp = tp + (x[i] * profit[i]);

    printf("\nMaximum possible value: %f", tp);
    printf("\nItems chosen: ");

    for (i = 0; i < n; i++)
        if (x[i] == 1.0)
            printf("%d=%d ", i + 1,1);
        else if (x[i] != 0.0)
            printf("%d=%.2f ", i + 1, x[i]);
}

int main()
{
    float weight[20], profit[20], capacity;
    int n, i, j;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items: ");
    for (i = 0; i < n; i++)
        scanf("%f", &weight[i]);

    printf("Enter the profits of the items: ");
    for (i = 0; i < n; i++)
        scanf("%f", &profit[i]);

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    knapsack(n, weight, profit, capacity);

    return 0;
}
