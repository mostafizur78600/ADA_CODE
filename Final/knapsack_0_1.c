/*
Date: 31/03/2023
Name: Mostafizur Rahman

[Knapsack]: Write a program to implement a Greedy strategy to solve the 
a) 0-1 Knapsack problem and b) Fractional Knapsack problem. 
The items, weight, and values are to be input by the user.
*/

#include <stdio.h>

// Structure to represent an item
typedef struct {
    int weight;
    int value;
    int sl;
} Item;

// Function to solve the knapsack problem using a greedy strategy
void knapsack_greedy(int num_items, Item items[], int capacity) {
    // Calculate the value-to-weight ratio for each item
    float ratios[num_items];
    for (int i = 0; i < num_items; i++) {
        ratios[i] = (float) items[i].value / items[i].weight;
    }

    // Sort the items based on their value-to-weight ratios in descending order
    for (int i = 0; i < num_items - 1; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if (ratios[i] < ratios[j]) {
                // Swap the items
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;

                // Swap the ratios
                float temp_ratio = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = temp_ratio;
            }
        }
    }

    // Create arrays to keep track of the selected items and their total weight and value
    int knapsack[num_items];
    int total_weight = 0;
    int total_value = 0;

    // Add items to the knapsack until the capacity is reached
    for (int i = 0; i < num_items; i++) {
        if (total_weight + items[i].weight <= capacity) {
            // Add the item to the knapsack
            knapsack[i] = 1;
            total_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            knapsack[i] = 0;
        }
    }

    // Print the selected items and the total value
    printf("Selected items:\n");
    for (int i = 0; i < num_items; i++) {
        if (knapsack[i] == 1) {
            printf("Item %d\n",items[i].sl+1);
        }
    }
    printf("Total value: %d\n", total_value);
}

int main() {
    int num_items, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    // Create an array of Item structures to store the weight and value of each item
    Item items[num_items];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
        printf("Value: ");
        scanf("%d", &items[i].value);
        items[i].sl=i;
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Solve the knapsack problem using the greedy strategy
    knapsack_greedy(num_items, items, capacity);

    return 0;
}
