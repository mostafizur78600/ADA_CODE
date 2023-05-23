#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTICES 1000
typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int num_vertices;
    Edge edges[MAX_VERTICES];
} Graph;

Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    return graph;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void union_(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int compare(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

int kruskalMST(Graph* graph) {
    int parent[MAX_VERTICES];
    int cost=0;
    memset(parent, -1, sizeof(parent));
    qsort(graph->edges, graph->num_vertices, sizeof(Edge), compare);
    int e = 0;
    int i = 0;
    while (e < graph->num_vertices - 1 && i < graph->num_vertices) {
        Edge next_edge = graph->edges[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        if (x != y) {
            printf("%d - %d : %d\n", next_edge.src, next_edge.dest, next_edge.weight);
            cost+=next_edge.weight;
            union_(parent, x, y);
            e++;
        }
    }
    return cost;
}

int main() {
    int num_edges;
    printf("\nEnter number of edges : ");
    scanf("%d",&num_edges);
    Graph* graph = createGraph(num_edges);

    for (int i = 0; i < num_edges; i++)
    {
        printf("\nEnter details of %d edges.\n",i+1);
        printf("Enter source : ");
        scanf("%d",&graph->edges[i].src);
        printf("Enter destination : ");
        scanf("%d",&graph->edges[i].dest);
        printf("Enter weight : ");
        scanf("%d",&graph->edges[i].weight);
    }
    printf("\nThe mst cost is : %d",kruskalMST(graph));
    return 0;
}
