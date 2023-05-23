/*
Date: 31/03/2023
Name: Mostafizur Rahman

Given a Knapsack of a maximum capacity of W and N items each with its own value
and weight, throw in items inside the Knapsack such that the final contents has the
maximum value. Assume the items are divisible. Propose a greedy algorithm. What is
the time and space complexity of your algorithm?


*/

#include <stdio.h>
#include <limits.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    float ratio[n];

    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
        ratio[i] = profit[i] / weight[i];
    }

    float n_weight[n], n_profit[n];

    for (int i = 0; i < n; i++)
    {
        float z = INT_MIN;
        int k;
        for (int j = 0; j < n; j++)
        {
            if (z < ratio[j])
            {
                z = ratio[j];
                k = j;
            }
        }

        n_weight[i] = weight[k];
        n_profit[i] = profit[k];
        ratio[k] = INT_MIN;
    }

    for (i = 0; i < n; i++)
    {
        if (n_weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + n_profit[i];
            u = u - n_weight[i];
        }
    }

    if (i < n)
        x[i] = u / n_weight[i];

    tp = tp + (x[i] * n_profit[i]);

    printf("\nMaximum possible value: %f", tp);
    printf("\nItems chosen: ");
    for (int j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (n_profit[j] == profit[i] && n_weight[j] == weight[i])
            {
                if (x[j] == 1.0)
                    printf("%d=%d ", i + 1, 1);
                else if (x[j] != 0.0)
                    printf("%d=%.2f ,", i + 1, x[j]);
            }
        }
    }
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
