/*
Date: 25/05/2023
Name: Mostafizur Rahman

[Knapsack Problem]: Apply the bottom-up Dynamic Programming algorithm 
to solve an instance of the Knapsack problem. The items, weights, and 
values are to be input by the user.
*/

#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the knapsack problem using dynamic programming
int knapsack(int W, int weights[], int values[], int n, int selected[])
{
    // Create a 2D array to store the maximum value for each subproblem
    int dp[n + 1][W + 1];

    // Initialize the dp array with 0
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            dp[i][w] = 0;
        }
    }

    // Fill the dp array in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            // If the current item's weight is less than or equal to the remaining weight
            if (weights[i - 1] <= w)
            {
                // Choose the maximum value between including and excluding the current item
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                // The current item's weight exceeds the remaining weight, so exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find the selected items
    int i = n, w = W;
    while (i > 0 && w > 0)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selected[i - 1] = 1;
            w -= weights[i - 1];
        }
        i--;
    }

    // Return the maximum value that can be obtained
    return dp[n][W];
}

int main()
{
    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &weights[i], &values[i]);
    }

    int W; // Knapsack weight capacity
    printf("Enter the weight capacity of the knapsack: ");
    scanf("%d", &W);

    int selected[n];
    for (int i = 0; i < n; i++)
    {
        selected[i] = 0;
    }

    int max_value = knapsack(W, weights, values, n, selected);
    printf("The maximum value that can be obtained is: %d\n", max_value);

    printf("Selected items:\n");
    for (int i = 0; i < n; i++)
    {
        if (selected[i] == 1)
        {
            printf("Item %d - Weight: %d, Value: %d\n", i + 1, weights[i], values[i]);
        }
    }
    return 0;
}
