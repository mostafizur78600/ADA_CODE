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

// Function to solve the fractional knapsack problem using a greedy strategy
double fractional_knapsack(int num_items, Item items[], int capacity) {
    // Calculate the value-to-weight ratio for each item
    double ratios[num_items];
    for (int i = 0; i < num_items; i++) {
        ratios[i] = (double) items[i].value / items[i].weight;
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
                double temp_ratio = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = temp_ratio;
            }
        }
    }

    double total_value = 0.0;
    int current_capacity = capacity;

    // Fill the knapsack greedily
    for (int i = 0; i < num_items; i++) {
        if (items[i].weight <= current_capacity) {
            // Take the whole item
            printf("Item %d --- %d part, Weight: %d, Value: %d\n",items[i].sl+1,1,items[i].weight, items[i].value);
            total_value += items[i].value;
            current_capacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            float fraction = (float) current_capacity / items[i].weight;
            printf("Item %d --- %.2f part, Weight: %.2lf, Value: %.2lf\n",items[i].sl+1,fraction, fraction * items[i].weight, fraction * items[i].value);
            total_value += fraction * items[i].value;
            break;
        }
    }

    return total_value;
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

    // Solve the fractional knapsack problem using the greedy strategy
    double total_value = fractional_knapsack(num_items, items, capacity);

    printf("Total value of items in the knapsack: %.2lf\n", total_value);

    return 0;
}
