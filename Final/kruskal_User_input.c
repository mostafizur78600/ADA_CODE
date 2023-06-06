/*
Date: 02/05/2023
NAME: Mostafizur Rahman

[Kruskal’s Algorithm]: Write a program to implement Kruskal’s algorithm 
using the Greedy method. Your function must take a weighted graph as input 
and compute the MST of the graph. Comment on the time and space complexity 
of the algorithm. Can Kruskal’s algorithm work on a graph with negative weights? 
What is the effect of negative weights on the algorithm?
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTICES 1000

// Structure to represent an edge
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int num_vertices;
    Edge edges[MAX_VERTICES];
} Graph;

// Function to create a graph with given number of vertices
Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    return graph;
}

// Function to find the subset of an element i
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two subsets
void union_(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Comparison function used by qsort to sort edges in non-decreasing order of their weights
int compare(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to find the minimum spanning tree (MST) using Kruskal's algorithm
int kruskalMST(Graph* graph) {
    int parent[MAX_VERTICES]; // Array to store parent of each vertex
    int cost = 0; // Variable to store the total cost of the MST
    memset(parent, -1, sizeof(parent)); // Initialize parent array with -1
    qsort(graph->edges, graph->num_vertices, sizeof(Edge), compare); // Sort edges in non-decreasing order of their weights
    int e = 0; // Counter to keep track of the number of edges added to the MST
    int i = 0; // Counter to iterate through all the edges
    while (e < graph->num_vertices - 1 && i < graph->num_vertices) {
        Edge next_edge = graph->edges[i++]; // Select the next edge in the sorted order
        int x = find(parent, next_edge.src); // Find the subset of the source vertex
        int y = find(parent, next_edge.dest); // Find the subset of the destination vertex
        if (x != y) {
            printf("%d - %d : %d\n", next_edge.src, next_edge.dest, next_edge.weight); // Print the selected edge
            cost += next_edge.weight; // Add the weight of the selected edge to the total cost
            union_(parent, x, y); // Perform union of the subsets
            e++; // Increment the counter of added edges
        }
    }
    return cost; // Return the total cost of the MST
}

int main() {
    int num_edges;
    printf("\nEnter number of edges : ");
    scanf("%d", &num_edges); // Read the number of edges from the user
    Graph* graph = createGraph(num_edges); // Create a graph with the given number of edges

    for (int i = 0; i < num_edges; i++) {
        printf("\nEnter details of %d edges.\n", i+1);
        printf("Enter source : ");
        scanf("%d", &graph->edges[i].src); // Read the source vertex of the edge
        printf("Enter destination : ");
        scanf("%d", &graph->edges[i].dest); // Read the destination vertex of the edge
        printf("Enter weight : ");
        scanf("%d", &graph->edges[i].weight); // Read the weight of the edge
    }
    printf("\nThe mst cost is : %d", kruskalMST(graph)); // Find and print the cost of the MST
    return 0;
}

/*
Kruskal's algorithm work with negative edge weights
Negative weights are not necessarily problematic for graph algorithms, as long as they do not create negative cycles
*/