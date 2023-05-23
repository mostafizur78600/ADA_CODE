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

void kruskalMST(Graph* graph) {
    int parent[MAX_VERTICES];
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
            union_(parent, x, y);
            e++;
        }
    }
}

int main() {
    int num_vertices = 14;
    Graph* graph = createGraph(num_vertices);
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 4;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 7;
    graph->edges[1].weight = 8;

    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;
    graph->edges[2].weight = 8;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 7;
    graph->edges[3].weight = 11;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 7;

    graph->edges[5].src = 2;
    graph->edges[5].dest = 5;
    graph->edges[5].weight = 4;

    graph->edges[6].src = 2;
    graph->edges[6].dest = 8;
    graph->edges[6].weight = 2;
    
    graph->edges[7].src = 3;
    graph->edges[7].dest = 4;
    graph->edges[7].weight = 9;

    graph->edges[8].src = 3;
    graph->edges[8].dest = 5;
    graph->edges[8].weight = 14;

    graph->edges[9].src = 4;
    graph->edges[9].dest = 5;
    graph->edges[9].weight = 10;

    graph->edges[10].src = 5;
    graph->edges[10].dest = 6;
    graph->edges[10].weight = 2;

    graph->edges[11].src = 6;
    graph->edges[11].dest = 7;
    graph->edges[11].weight = 1;

    graph->edges[12].src = 6;
    graph->edges[12].dest = 8;
    graph->edges[12].weight = 6;

    graph->edges[13].src = 7;
    graph->edges[13].dest = 8;
    graph->edges[13].weight = 7;
    kruskalMST(graph);
    return 0;
}
