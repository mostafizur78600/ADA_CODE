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


//Knapsack function
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[n], tp = 0;
    int i, j, u;
    u = capacity;

    float ratio[n];

    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
        ratio[i] = profit[i] / weight[i];   //Find ratio of profit/weight
    }

    float n_weight[n], n_profit[n]; //array decleration for new sorting using ratio
    //sorting ratio as well as new weight & profit array using ratio
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

        n_weight[i] = weight[k]; //sorting weight to a new array
        n_profit[i] = profit[k]; //sorting profit to a new array
        ratio[k] = INT_MIN;
    }

    for (i = 0; i < n; i++)
    {
        if (n_weight[i] > u) //check weight if more than Knapsack capacity
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + n_profit[i]; //add total profit
            u = u - n_weight[i]; //Decrease capacity according to item add
        }
    }

    if (i < n)
        x[i] = u / n_weight[i]; // devide a item when full capacity not present

    tp = tp + (x[i] * n_profit[i]); //add the divide part item to profit

    printf("\nMaximum possible value: %.2f", tp); //print maximum profit

    //print the item part which select
    printf("\nItems chosen: \n");
    for (int j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (n_profit[j] == profit[i] && n_weight[j] == weight[i])
            {
                if (x[j] == 1.0)
                    printf("Item : %d=%d\n", i + 1, 1);
                else if (x[j] != 0.0)
                    printf("Item : %d=%.2f part\n", i + 1, x[j]);
            }
        }
    }
}

int main()
{
    float weight[20], profit[20], capacity;
    int n, i, j;

    printf("Enter the number of items: "); 
    scanf("%d", &n); //take user input of item number

    printf("Enter the weights of the items: \n");
    for (i = 0; i < n; i++)
        scanf("%f", &weight[i]); //takes user input of item weight

    printf("Enter the profits of the items: \n");
    for (i = 0; i < n; i++)
        scanf("%f", &profit[i]); //takes user input of item profit

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity); //takes user input of Knapsack capacity

    knapsack(n, weight, profit, capacity); //call the Knapsack function

    return 0;
}
